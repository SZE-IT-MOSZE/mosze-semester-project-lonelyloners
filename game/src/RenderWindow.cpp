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
            if (i == 1)
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
    // oldal és képkockák száma alapból 1 legyen 
    pg = frms = 1;
    map = 0;
    // első txt, többit kiolvassa
    curr_txt = "story/start.txt";
    nextTxt(false);
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
    
    if (t == frms && !ff)
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
bool RenderWindow::renderText(TTF_Font* Sans)
{
    int i = 0, asterisk = 0, alline = 0; 
    SDL_Color blck = {0, 0, 0};
    const char* c;

    for (std::string line: storyTextToRender) 
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
            Message_rect.x = 450 * getRES();
            // beállítja a téglalap x koordinátáját
            Message_rect.y = 30 * getRES() + (20 * i) * getRES();
            // beállítja a téglalap szélességét
            Message_rect.w = 6 * line.length() * getRES();
            // beállítja a téglalap magasságát   
            Message_rect.h = 18 * getRES();

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
    if (asterisk < pg)
    {
        pg = 1;
        asterisk = 0;
        return false;
    }
    else
    {
        return true;
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
    const char* c;

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
/**
 * \brief A egyéb információ megjelenítése.
 * 
 * Parancs, interakció és egyéb információs üzenet
 * 
 */
void RenderWindow::renderInfoText(std::string inputText, TTF_Font* Sans)
{  
    const char* c;
    
    SDL_RenderClear(renderer);

    SDL_Color wht = {255, 255, 255};

    c = inputText.c_str();

    SDL_Surface* surfaceMessage = TTF_RenderUTF8_Blended(Sans, c, wht); 

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    // létrehoz egy téglalapot
    SDL_Rect Message_rect;
    // beállítja a téglalap x koordinátáját  
    Message_rect.x = 434 * getRES();    
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

/**
 * \brief A következő txt meghatározása.
 * 
 * Paraméterként kapott, játékos inputján
 * alapján határozza meg a következő szövegfájlt.
 * 
 *  * \param c Ez tartalmazza a döntést.
 */
void RenderWindow::nextTxt(bool c)
{
    std::fstream set;
    std::string line;
    std::vector<std::string> lines;
    const char * s;
    int i = 0, asterisk = 0, alline = 0; 

    // a user sttings fájl második sorának növelése eggyel
    set.open("user.settings");
    
    if (set.fail())
    {
        std::cout << "A beallítások fajl serult vagy nem letezik" << std::endl;
    }
    
    while (getline(set, line))
    {
        lines.push_back(line);
    }
    set.close();
        
    std::ofstream write_file;

    write_file.open("user.settings");

    if (write_file.fail())
    {
        std::cout << "A beallítások fajl serult vagy nem letezik" << std::endl;
    }

    for (int i = 0; i < lines.size(); i++)
    {
        if (i != 1)
        write_file << lines[i] << std::endl;
        else 
        write_file << std::to_string( std::stoi(lines[i]) + 1) << std::endl; 
    }

    write_file.close();

    std::ifstream ifs(curr_txt);

    while(std::getline(ifs, line))
    {
        alline++;
    }

    ifs.close();

    std::ifstream ttt(curr_txt);
    i = 0;
    while(std::getline(ttt, line))
    {
        //if (i == alline && line.substr(2, line.length()) == "game_over.png")
        //{
        //    bEnd = true;
        //}

        i++;
        if (c)
        {
            if (i == alline - 1)
            {
                curr_txt = line.substr(2, line.length());
            }
        }
        else if (!c)
        {
            if (i == alline)
            {
                curr_txt = line.substr(2, line.length());
            }
        }
    }

    curr_txt = "story/" + curr_txt;
    ttt.close();
    storyTextToRender.clear();
    // az új txt sorainak betöltése egy vektorba
    std::ifstream txt(curr_txt);

    while(std::getline(txt, line))
    {
        storyTextToRender.push_back(line);
    }
    txt.close();
}
/**
 * \brief Térkép számánek visszaadása.
 * 
 * Visszaadja a térkép számát, ami alapján meghatározható a térkép.
 * 
 * \return A térkép száma.
 */
int RenderWindow::getMap()
{
    return map;
}
/**
 * \brief Megadott számú térkép beállítása.
 * 
 * Térkép váltása esetén a megadott számú térképet állítja be.
 * 
 * \param i Ez tartalmazza a térkép számát.
 */
void RenderWindow::setMap(int i)
{
    map = i;
}
/**
 * \brief Térkép alalapértelmezettre állítja.
 * 
 * Térkép váltása esetén az első térképre állítja a számlálót.
 * 
 */
void RenderWindow::mapReset()
{
    map = 0;
}
/**
 * \brief Térkép megjelenítése.
 * 
 * Paraméterként kapott, nagy térkép, és a kivágandó részek koordinátái
 * alapján a megfelelően beállított térkép száma alapján jeleníti meg a 
 * térképet.
 * 
 * \param p_entity Ez tartalmazza a térképet.
 * \param spritepos A nagy térkép egy részletének helye.
 */
void RenderWindow::updateMap(Entity& p_entity, std::vector<std::pair<int, int>> spritepos)
{   
    SDL_Rect src;

    // megfelelő képkocka kivágása
    src.x = spritepos[map].first;
    src.y = spritepos[map].second;
    // téglalap méreteinek beállítása
    src.h = 384;
    src.w = 384;
    // cél téglalap beállítása
    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = 384 * getRES();
    dst.h = 384 * getRES();
    // rendererbe másolás
    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

