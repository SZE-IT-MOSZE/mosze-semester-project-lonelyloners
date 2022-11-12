#define SDL_MAIN_HANDLED

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <sdl/SDL_ttf.h>

#include "headers/RenderPlanets.h"
#include "headers/Planet1.h"
#include "headers/Menu.h"
#include "headers/Entity.h"
#include "headers/Router.h"
#include "headers/Command.h"

/**
 * \brief Fő függvény.
 *  
 * Ez a függvény tartalmazza, jeleníti meg a játékot.
 * 
 * \param argc SDL esetén kötelező.
 * \param argv[] SDL esetén kötelező.
 * \return Nullát ad vissza, ha minden rendben lefutott.
 */
int main(int argc, char* argv[])
{
    // SDL inicializálása
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "SDL Init hiba: " << SDL_GetError();
    }
    
    if (TTF_Init() == -1)
    {
        std::cout << "TTF Init hiba: " << SDL_GetError();
    }
    // ablak létrehozása
    RenderWindow game("LonelyLoners - LyRs kalandjai v0.1", 768 /* * getRRes() */, 484 /* * getRRes() */);
    // betűtípus betöltése
    TTF_Font* fnt = TTF_OpenFont("font/TheFountainOfWishesRegular-OVxw4.ttf", 18);  
    // menü futtatása és menüpont számának elmentése
    int choice = menu(game);
    // renderer "takarítása"
    game.clear();
    // megfelelő menüpont futtatása
    if (choice == 1)
    {
        // egész számokból álló párokból álló vektorok definiálása
        std::vector<std::pair<int, int>> lyrsIdleR;
        std::vector<std::pair<int, int>> lyrsIdleL;
        std::vector<std::pair<int, int>> lyrsMoveR;
        std::vector<std::pair<int, int>> lyrsMoveL;
        std::vector<std::pair<int, int>> lyrsLaserR;
        std::vector<std::pair<int, int>> lyrsLaserL;
        
        // LyRs üresjárati animációjának a piozíciói
        // jobb            
        lyrsIdleR       = { { 0,   0}, {64,   0}, {128,   0}, {192,   0} };
        // bal
        lyrsIdleL       = { {32,  32}, {96,  32}, {160,  32}, {224,  32} };
        
        // LyRs séta animációjának a piozíciói
        // jobb
        lyrsMoveR       = { { 0,  64}, {64,  64}, {128,  64}, {192,  64}, {256,  64} };
        // bal
        lyrsMoveL       = { {32,  96}, {96,  96}, {160,  96}, {224,  96}, {290,  96} };
        
        // LyRs lövés animációjának a piozíciói
        // jobb
        lyrsLaserR      = { { 0, 128}, {64, 128}, {128, 128}, {192, 128}, {256, 128} , 
                            { 0, 160}, {64, 160}, {128, 160}, {192, 160}, {256, 160} , 
                            { 0, 192}, {64, 192}, {128, 192}, {192, 192}, {256, 192} ,
                            { 0, 224}, {64, 224}, {128, 224}, {192, 224}, {256, 224} };
        // bal
        lyrsLaserL      = { { 0, 256}, {64, 256}, {128, 256}, {192, 256}, {256, 256} , 
                            { 0, 288}, {64, 288}, {128, 288}, {192, 288}, {256, 288} , 
                            { 0, 320}, {64, 320}, {128, 320}, {192, 320}, {256, 320} ,
                            { 0, 352}, {64, 352}, {128, 352}, {192, 352}, {256, 352} };
                          
        // Entity vector létrehozása
        std::vector<Entity> planet1 = {};
        planet1 = LoadPlanet1(game);
        // logikai változókat tartalmazó vektor definiálása
        std::vector<bool> planetR = {};
        planetR = setPlanet1Pos();
        // LyRs összes animációját tartalmazó sprite sheet betöltése
        SDL_Texture* lyrsAnim = game.loadTexture("res/gfx/Animations/lyrs_sprite_sheet.png");
        Entity l(V2F(64, 0), lyrsAnim);
        l.setPosi(64, 0);
        // első térkép hátterének betöltése
        SDL_Texture* background = game.loadTexture("res/gfx/Dessert_Map1/dessert_map1_alapmap.png");
        Entity pl(V2F(0, 0), background);
        // szöveg háttér betöltése
        SDL_Texture* textBckGround = game.loadTexture("res/gfx/Dessert_Map1/both.png");
        Entity txtbckground(V2F(384, 0), textBckGround);
        // beviteli mező háttere
        SDL_Texture* inputTextBckGround = game.loadTexture("res/gfx/Objects/blck_bckgrnd.png");
        Entity inptxtbckground(V2F(0, 384), inputTextBckGround);
        // parancs választó deklarálása
        Router r = Router();

        // összes logikai változó a gombnyomásokhoz
        bool gameRunning = true;
        bool attack = false;
        bool fel = false;
        bool le = false;
        bool jobbra = false;
        bool balra = false;
        bool flip = true;
        // esemény létrehozása
        SDL_Event event;
        // FPS limitációhoz szükséges változók
        const float timeStep = 0.01f;
        float accum = 0.0f;
        float cTime = utils::hireTimeInSeconds();
        // input text 
        std::string command;
       
        SDL_StartTextInput();

        // main game loop
        while(gameRunning)
        {
            // képkockák számolása
            int startTick = SDL_GetTicks();
            
            float nTime = utils::hireTimeInSeconds();
            float fTime = nTime - cTime;
            
            cTime = nTime;
            accum += fTime;
            // fps limitálása
            while(accum >= timeStep)
            {   
                // események vezérlése
                while (SDL_PollEvent(&event))
                {
                    switch(event.type)
                    {
                        // kilépés gomb lekezelése 
                        case SDL_QUIT:
                            gameRunning = false;
                            break;
                        // szövegbevitel kezelése
                        case SDL_TEXTINPUT:
                            command += event.text.text;
                            break;
                        // gomb lenyomások kezelése                        
                        case SDL_KEYDOWN:
                            switch(event.key.keysym.sym)
                            {
                                case SDLK_BACKSPACE:
                                    command = command.substr(0, command.size()-1);
                                    break;
                                case SDLK_RETURN:
                                    Command c = Command(command);
                                    c.make();
                                    r.route(c.getCommand(), c.getItem(), l);
                                    command = "";
                            }
                    }
                }
                accum -= timeStep;
            }           
            const float alpha = accum / timeStep;          
            // irányok beállítása
            switch (l.getDirection())
            {
                case 0:
                    break;
                case 1:
                    // fel
                    fel = true;
                    break;
                case 2:
                    // jobbra
                    jobbra = true;
                    break;     
                case 3:
                    // le
                    le = true;
                    break;
                case 4: 
                    // balra
                    balra = true;
                    break;
                default:
                    break;
            }
            // először a háttér kirajzolása
            game.render(pl);          
            // felfele gomb megnyomva?
            if (fel)
            {                
                if (l.getPos().getY() <= l.getTargetY())
                {
                    fel = false;
                    // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                    l.setDirZero();
                }   
                // LyRs mozgatása fel
                game.up(l);
                // jobbra gomb volt utoljára lenyomva?
                if (flip)
                {
                    // LyRs jobbra mozog animáció következő kockája
                    game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0);
                }
                else
                {
                    // LyRs balra mozog animáció következő kockája
                    game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0);
                }
            }
            // lefele gomb megnyomva?
            if (le)
            {
                if (l.getPos().getY() >= l.getTargetY())
                {
                    le = false;
                    // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                    l.setDirZero();
                } 
                // LyRs mozgatása le
                game.down(l);
                // jobbra gomb volt utoljára lenyomva?
                if (flip)
                {
                    // LyRs jobbra mozog animáció következő kockája
                    game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0);
                }
                else
                {
                    // LyRs balra mozog animáció következő kockája
                    game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0);
                }
            }
            // balra gomb megnyomva?
            if (balra)
            {
                if (l.getPos().getX() <= l.getTargetX())
                {
                    balra = false;
                    // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                    l.setDirZero();
                } 
                // LyRs mozgatása balra
                game.left(l);
                // LyRs balra mozog animáció következő kockája
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0);
                // összes animáció balra néz
                flip = false;
            }
            // jobbra gomb megnyomva?
            if (jobbra)
            {
                if (l.getPos().getX() >= l.getTargetX())
                {
                    jobbra = false;
                    l.setDirZero();
                } 
                // LyRs mozgatása jobbra
                game.right(l);
                // LyRs jobbra mozog animáció következő kockája
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0);
                // összes animáció jobbra néz
                flip = true;
            }
            // szóköz gomb megnyomva?
            if (attack)
            {
                // jobbra gomb volt utoljára lenyomva?
                if (flip)
                {
                    // LyRs jobbra támad animáció következő kockája
                    game.update(l, lyrsLaserR, lyrsLaserR.size(), 64, 32, 0);               
                }
                else
                {
                    // LyRs balra támad animáció következő kockája
                    game.update(l, lyrsLaserL, lyrsLaserL.size(), 64, 32, 32);               
                }
            }

            if (!fel && !le && !balra && !jobbra && !attack)
            {
                // check if the right button was the last pressed not the left
                if (flip)
                {
                    // LyRs jobbra néző üresjárati animáció következő kockája
                    game.update(l, lyrsIdleR, lyrsIdleR.size(), 32, 32, 0);
                }
                else
                {
                    // LyRs balra néző üresjárati animáció következő kockája
                    game.update(l, lyrsIdleL, lyrsIdleL.size(), 32, 32, 0);
                }
            }
            // felhők renderelése és ütközések ellenőrzése és lekezelése
            planetR = renderPlanet(game, planet1, planetR, l);
            game.render(inptxtbckground);
            game.renderInputText(command, fnt);
            // szöveg háttér
            game.render(txtbckground);
            game.renderText("story/bevezeto.txt", fnt);
            // rendererbe tötött elemek képernyőre helyezése
            game.display();
            // TODO:
            // delete c;
        }
        // ablak törlése
        game.cleanUp();
        game.clear();
        // program bezárása
        SDL_StopTextInput();
        TTF_Quit();
        SDL_Quit();
    }
    // kilépés gomb 
    else if (choice == 5)
    {
        return 0;
    }
    return 0;
}
