#include <sdl/SDL.h>
#include <SDL_Main.h> 
#include <sdl/SDL_image.h>
#include <sdl/SDL_ttf.h>
#include <fstream>
#include <iostream>
#include <vector>

#include "headers/RenderWindow.h"
#include "headers/Entity.h"
/**
 * \brief Létrehozza az ablakot.
 * 
 * Megadott méretek, cím alapján pontosan a képernyő közepére létrehoz egy
 * GPU gyorsított ablakot.
 * 
 * \param p_title Az ablak címsorába kerülő szöveg.
 * \param p_w Az ablak szélessége.
 * \param p_h Az ablak magassága.
 */
RenderWindow::RenderWindow (const char* p_title, int p_w, int p_h) : window(NULL), renderer(NULL)
{
    // ablak létrehozása 
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_w, p_h, SDL_WINDOW_SHOWN);
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
 * Az program kezdete óta eltelt idő 100-ad részét figyelembe véve vágja ki a megadott pozíció, magasság és
 * szélesség alapján a következő képkockát, majd rendererbe másolja.  
 * 
 * \param p_entity Ez tartalmazza a sprite sheetet.
 * \param spritepos A megjelenítendő animáció képkocka pozícióit tárolja.
 * \param frames Az animációban szereplő képkockák számát jelöli.
 * \param w A megjelenítendő képkocka szélessége.
 * \param h A megjelenítendő képkocka magassága.
 * \param offset Ha el kéne tolni az x tengely mentén.
 */
void RenderWindow::update(Entity& p_entity, std::vector<std::pair<int, int>> spritepos, int frames, int w, int h, int offset)
{
    SDL_Rect src;
    // megfelelő képkocka kivágása
    int t = (SDL_GetTicks()/100) % frames;
    src.x = spritepos[t].first;
    src.y = spritepos[t].second;
    // téglalap méreteinek beállítása
    src.h = h /* * getRRes() */;
    src.w = w /* * getRRes() */;
    // cél téglalap beállítása
    SDL_Rect dst;
    dst.x = (p_entity.getPos().x - offset);
    dst.y = p_entity.getPos().y;
    dst.w = w;
    dst.h = h;
    // rendererbe másolás
    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
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
    p_entity.setPosi(0, -1);
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
    p_entity.setPosi(0, 1);
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
    p_entity.setPosi(-1, 0);
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
    p_entity.setPosi(1, 0);
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
    dst.x = p_entity.getPos().x;
    dst.y = p_entity.getPos().y;
    dst.w = p_entity.getCurrentFrame().w;
    dst.h = p_entity.getCurrentFrame().h;
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
 * \return A renderer.
 */
void RenderWindow::renderText()
{
    TTF_Font* Sans = TTF_OpenFont("font/starcruiser.ttf", 24);

    SDL_Color White = {0, 0, 0};

    // as TTF_RenderText_Solid could only be used on
    // SDL_Surface then you have to create the surface first
    SDL_Surface* surfaceMessage =
        TTF_RenderText_Solid(Sans, "Udvozollek a LonelyLoners nevu", White); 

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    // létrehoz egy téglalapot
    SDL_Rect Message_rect;
    // beállítja a téglalap x koordinátáját  
    Message_rect.x = 464;    
    // beállítja a téglalap x koordinátáját
    Message_rect.y = 55;    
    // beállítja a téglalap szélességét
    Message_rect.w = 240;
    // beállítja a téglalap magasságát   
    Message_rect.h = 24;    

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

    // memória felszabadítása
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
