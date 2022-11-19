#include <sdl/SDL.h>
#include <sdl/SDL_Main.h> 
#include <sdl/SDL_image.h>
#include <sdl/SDL_ttf.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "headers/RenderWindow.h"

/**
* \brief A felbontás szorzó kiovasása.
*
* A felbontás egy szorzó segítségével van állítva, 
* ez egy fájlban van tárolva, és ezt olvassa ki ez a függvény.   
* 
* \return Egész szaám, amivel meg kell szorozni a méreteket.
*/
int RenderWindow::getRES()
{
    int i = 0;
    int RES = 1;
    std::string line;
    std::ifstream set;
    // beállítások fájl megnyitása
    set.open("user.settings");
    if (set.is_open())
    {
        while(getline(set, line))
        {
            i++;
            // felbontás szorzó az első sorban van tárolva 
            if (i = 1)
            {
                // a visszaadandó változóbva olvassuk az első sort
                RES = std::stoi(line);
            } 
        }
        set.close();
    }
    // hibakezelés, ha a fájl nem látezne
    else std::cout << "A beallítások fajl serult vagy nem letezik" << std::endl; 
    // szorzó visszaadása
    return RES;
}

/**
 * \brief Létrehozza az ablakot.
 * 
 * Megadott méretek, cím alapján pontosan a képernyő közepére létrehoz egy
 * GPU gyorsított ablakot.s
 * 
 * \param p_title Az ablak címsorába kerülő szöveg.
 * \param p_w Az ablak szélessége.
 * \param p_h Az ablak magassága.
 */
RenderWindow::RenderWindow (const char* p_title, int p_w, int p_h) : window(NULL), renderer(NULL)
{
    // ablak létrehozása 
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w * getRES(), p_h * getRES(), SDL_WINDOW_SHOWN);
    // ablak ikon beállytása
    SDL_Surface *surface;
    surface = IMG_Load("res/gfx/Characters/lyrs_jobb.png");
    SDL_SetWindowIcon(window, surface);
    SDL_FreeSurface(surface);
    // ellenőrzés, hogy létrejött-e az ablak
    if (window == NULL)
    {
        std::cout << "Ablak betöltése sikertelen Error: " << SDL_GetError() << std::endl;
    }
    // GPU gyorsított renderer létrehozása
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    pg = frms = 1;
}
/**
 * \brief Kép betöltése.
 * 
 * A paraméterként kapott elérési úttal rendelkező képet a rendererbe tölti.
 * 
 * \param p_filepath A kép eléeési útja.
 * \return A létrejött téglalap.
 */
SDL_Texture* RenderWindow::loadTexture(const char* p_filepath)
{
    // üres textúra
    SDL_Texture* texture = NULL;
    // png betöltése a rendererbe
    texture = IMG_LoadTexture(renderer, p_filepath);
    // png létrejöttének ellenőrzése
    if (texture == NULL)
    {
        std::cout << "Nem sikerült a képet betölteni. Error: " << SDL_GetError() << std::endl;
    }
    // betöltött elem visszaadása
    return texture;
}
/**
 * \brief A monitor FPS-ének lekérése.
 * 
 * A függvény lekéri a monitor azonosítóját, amelyiken azu ablakunk elindult, 
 * majd ennek a monitornak a beállított képpfrissítési frekvenciáját kéri le, 
 * és adja vissza.
 * 
 * \return A monitor beállított FPS-e.
 */
int RenderWindow::getRefreshRate()
{
    // képernyő számának lekérése
    int displayIndex = SDL_GetWindowDisplayIndex( window );

    SDL_DisplayMode m;
    // a képernyő információinak lekérése
    SDL_GetDisplayMode(displayIndex, 0, &m);
    // csak az fps visszaadása
    return m.refresh_rate;
}
/**
 * \brief A létrehozott képernyő törlése.
 * 
 * A létrehozott ablakot törli és bezárja. 
 * 
 */
void RenderWindow::cleanUp()
{
    // clear the window
    SDL_DestroyWindow(window);
}
/**
 * \brief A létrehozott renderer törlése.
 * 
 * A létrehozott renderert törli. Ezzel kiüríthetjük az ablakot,
 * és új dolgokat helyezhetünk ki. (pl. menüből első pályára ugrás) 
 * 
 */
void RenderWindow::clear()
{
    // renderer tisztítása
    SDL_RenderClear(renderer);
}
/**
 * \brief Animáció következő képkockája.
 * 
 * A sprite sheet-ből vágja ki és jeleníti meg a következő képet egy int párokat tartalmazó vektor segítségével.
 * Az program kezdete óta eltelt időt figyelembe véve 100ms időközönként sprite sheeten való pozíció és szélesség 
 * alapján jeleníti meg a következő képkockát, majd rendererbe másolja. Az ff változó azért szükséges, mert pl.
 * támadás animáció esetén nem az első képkocától játszaná le az animációt. Ezért megvárjuk, amíg az eltelt idő
 * alapján számolt képkocka szám elérje ismét az egyet, majd ekkor kezdjük el az animációt. Amennyiben elérte a
 * képkockák száma az animációk képkockájának számát, visszaad egy hamis értéket, ami jelzi az animáció végét.
 * 
 * \param p_entity Ez tartalmazza a sprite sheetet.
 * \param spritepos A megjelenítendő animáció képkocka pozícióit tárolja.
 * \param frames Az animációban szereplő képkockák számát jelöli.
 * \param w A megjelenítendő képkocka szélessége.
 * \param h A megjelenítendő képkocka magassága.
 * \param offset Ha el kéne tolni az x tengely mentén.
 * \param ff .
 */
bool RenderWindow::update(Entity& p_entity, std::vector<std::pair<int, int>> spritepos, int frames, int w, int h, int offset, bool ff)
{   
    SDL_Rect src;

    int t = (SDL_GetTicks() / 100) % frames;
    
    if (t == frms)
    {
        frms++;
    }

    if (ff)
    {
        // megfelelő képkocka kivágása
        src.x = spritepos[t].first;
        src.y = spritepos[t].second;
    }
    else
    {
        // megfelelő képkocka kivágása
        src.x = spritepos[frms].first;
        src.y = spritepos[frms].second;
    }

    // téglalap méreteinek beállítása
    src.h = h;
    src.w = w;
    // cél téglalap beállítása
    SDL_Rect dst;
    dst.x = (p_entity.getPos().x - offset);
    dst.y = p_entity.getPos().y;
    dst.w = w * getRES();
    dst.h = h * getRES();
    // rendererbe másolás
    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);

    if ( frms == frames - 1 )
    {
        frms = 1;
        return false;
    }
    else
    {
        return true;
    }
}
/**
 * \brief Egy Entity felfele mozgatása.
 * 
 * A paraméterként kapott Entity-t mozgatja.
 * 
 * \param p_entity Ez tartalmazza a mozgatandó elemet.
 */
void RenderWindow::up(Entity& p_entity)
{
    // Entity 1 pixellel felfele mozgatása 
    p_entity.setPosi(0, -1 * getRES());
}
/**
 * \brief Egy Entity lefele mozgatása.
 * 
 * A paraméterként kapott Entity-t mozgatja.
 * 
 * \param p_entity Ez tartalmazza a mozgatandó elemet.
 */
void RenderWindow::down(Entity& p_entity)
{
    // Entity 1 pixellel lefele mozgatása 
    p_entity.setPosi(0, 1 * getRES());
}
/**
 * \brief Egy Entity balra mozgatása.
 * 
 * A paraméterként kapott Entity-t mozgatja.
 * 
 * \param p_entity Ez tartalmazza a mozgatandó elemet.
 */
void RenderWindow::left(Entity& p_entity)
{
    // Entity 1 pixellel balra mozgatása 
    p_entity.setPosi(-1 * getRES(), 0);
}
/**
 * \brief Egy Entity jobbra mozgatása.
 * 
 * A paraméterként kapott Entity-t mozgatja.
 * 
 * \param p_entity Ez tartalmazza a mozgatandó elemet.
 */
void RenderWindow::right(Entity& p_entity)
{
    // Entity 1 pixellel jobbra mozgatása 
    p_entity.setPosi(1 * getRES(), 0);
}
/**
 * \brief Egy Entity megjelenítése.
 * 
 * A paraméterként kapott Entity-t jeleníti meg.
 * 
 * \param p_entity Ez tartalmazza a megjelenítendő elemet.
 */
void RenderWindow::render(Entity& p_entity)
{
    // forrás téglalap beállítása
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;
    // cél téglalap beállítása
    SDL_Rect dst;
    dst.x = p_entity.getPos().getX() * getRES();
    dst.y = p_entity.getPos().getY() * getRES();
    dst.w = p_entity.getCurrentFrame().w * getRES();
    dst.h = p_entity.getCurrentFrame().h * getRES();
    // rendererbe másolás
    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}
/**
 * \brief Az összes renderelendő elem megjelenítése.
 * 
 * A rendererbe betöltött összes elemet a képernyőre helyezi
 * 
 */
void RenderWindow::display() 
{
    // renderer elemeinek képernyőn való megjelenítése
    SDL_RenderPresent( renderer );
}
/**
 * \brief A létrehozott ablakot adja vissza.
 * 
 * A létrehozott ablakot adja vissza paraméterként.
 * Akkor hasznos, ha esetleg komplett menüpontok ki
 * vannak szervezve egy header fájlba. 
 * 
 * \return Az ablak.
 */
SDL_Window* RenderWindow::getWindow()
{
    // a létrehozottt ablakot adja vissza
    return window;
}
/**
 * \brief A létrehozott renderert adja vissza.
 * 
 * A létrehozott renderert adja vissza paraméterként.
 * 
 * \return A renderer.
 */
SDL_Renderer* RenderWindow::getRenderer()
{
    // a létrehozottt renderert adja vissza
    return renderer;
}
/**
 * \brief Szöveg képernyőre íratása.
 * 
 * Paraméterként kapott szöveget jeleníti meg a képernyőn.
 * 
 * \return A következő txt.
 */
const char* RenderWindow::renderText(const char* path, TTF_Font* Sans)
{
   
    std::ifstream ifs(path);
    std::string line;
    const char * c;
    int i = 0, asterisk = 0, alline = 0; 

    SDL_Color blck = {0, 0, 0};

    while(std::getline(ifs, line))
    {
        alline++;
        if (pg > asterisk && (pg - 1) == asterisk && line.substr(0, 2) != "//" && line != "*")
        { 
            // std::string const *charrá konvertálása
            c = line.c_str();
            SDL_Surface* surfaceMessage = TTF_RenderUTF8_Blended(Sans, c, blck); 

            SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

            // létrehoz egy téglalapot
            SDL_Rect Message_rect;
            // beállítja a téglalap x koordinátáját  
            Message_rect.x = 450 * getRES();;    
            // beállítja a téglalap x koordinátáját
            Message_rect.y = 30 * getRES() + (20 * i) * getRES();;    
            // beállítja a téglalap szélességét
            Message_rect.w = 6 * line.length() * getRES();;
            // beállítja a téglalap magasságát   
            Message_rect.h = 18 * getRES();;    

            SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

            // memória felszabadítása
            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(Message);
            i++;
        }
        if (line == "*")
        {
            asterisk++;            
        }
    }
    if (alline < pg)
    {
        pg = 1;
    }
}
/**
 * \brief A bekért szöveg képernyőre íratása.
 * 
 * Paraméterként kapott, billentyűről beolvasott
 * szöveget jeleníti meg a képernyőn.
 * 
 */
void RenderWindow::renderInputText(std::string inputText, TTF_Font* Sans)
{  
    const char * c;

    SDL_Color wht = {255, 255, 255};
    inputText = ">> " + inputText;

    c = inputText.c_str();

    SDL_Surface* surfaceMessage = TTF_RenderUTF8_Blended(Sans, c, wht); 

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    // létrehoz egy téglalapot
    SDL_Rect Message_rect;
    // beállítja a téglalap x koordinátáját  
    Message_rect.x = 50 * getRES();    
    // beállítja a téglalap x koordinátáját
    Message_rect.y = 416 * getRES();    
    // beállítja a téglalap szélességét
    Message_rect.w = 12 * inputText.length() * getRES();
    // beállítja a téglalap magasságát
    Message_rect.h = 36 * getRES();    

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

    // memória felszabadítása
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);    
}
