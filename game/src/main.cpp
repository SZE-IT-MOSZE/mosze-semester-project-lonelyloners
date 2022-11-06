#define SDL_MAIN_HANDLED

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include "headers/RenderPlanets.h"
#include "headers/Planet1.h"
#include "headers/Menu.h"
#include "headers/Entity.h"

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
    // ablak létrehozása
    RenderWindow game("LonelyLoners - LyRs kalandjai v0.1", 384 /* * getRRes() */, 384 /* * getRRes() */);
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
        Entity l(V2F(0, 0), lyrsAnim);           
        // első térkép hátterének betöltése
        SDL_Texture* background = game.loadTexture("res/gfx/Dessert_Map1/dessert_map1_alapmap.png");
        Entity pl(V2F(0, 0), background);
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
                    // kilépés gomb lekezelése 
                    if (event.type == SDL_QUIT)
                    {
                        gameRunning = false;
                    }
                    // gomb lenyomások kezelése
                    if(event.type == SDL_KEYDOWN)
                    {   
                        switch(event.key.keysym.sym)
                        {
                            // felfele gomb nyomásának ellenőrzése 
                            case SDLK_UP:
                                // std::cout << "FEL! lenyomva" << std::endl;
                                fel = true;
                                break;
                            // lefele gomb nyomásának ellenőrzése 
                            case SDLK_DOWN:
                                // std::cout << "LE! lenyomva" << std::endl;
                                le = true;
                                break;
                            // balra gomb nyomásának ellenőrzése 
                            case SDLK_LEFT:
                                // std::cout << "BALRA! lenyomva" << std::endl;
                                balra = true;
                                break;
                            // jobbra gomb nyomásának ellenőrzése 
                            case SDLK_RIGHT: 
                                // std::cout << "JOBBRA! lenyomva" << std::endl;
                                jobbra = true;
                                break;
                            // szóköz gomb nyomásának ellenőrzése 
                            case SDLK_SPACE:
                                attack = true;
                                // std::cout << "SZOKOZ! lenyomva" << std::endl;
                                break;
                            default:;
                        }
                    }
                    // gomb felengedések kezelése
                    if(event.type == SDL_KEYUP)
                    {   
                        switch(event.key.keysym.sym)
                        {
                            // felfele gomb elengedésének ellenőrzése 
                            case SDLK_UP:
                                // std::cout << "FEL! elengedve" << std::endl; 
                                fel = false;
                                break;
                            // lefele gomb elengedésének ellenőrzése 
                            case SDLK_DOWN:
                                // std::cout << "LE! elengedve" << std::endl;
                                le = false;
                                break;
                            // balra gomb elengedésének ellenőrzése 
                            case SDLK_LEFT:
                                // std::cout << "BALRA! elengedve" << std::endl;
                                balra = false;
                                break;
                            // jobbra gomb elengedésének ellenőrzése 
                            case SDLK_RIGHT: 
                                // std::cout << "JOBBRA! elengedve" << std::endl;
                                jobbra = false;
                                break;
                            // szóköz gomb elengedésének ellenőrzése 
                            case SDLK_SPACE:
                                attack = false; 
                                // std::cout << "SZOKOZ! elengedve" << std::endl;
                                break;
                            default:;
                        }
                    }
                }
                accum -= timeStep;
            }
            
            const float alpha = accum / timeStep;          
            // először a háttér kirajzolása
            game.render(pl);
            // felfele gomb megnyomva?
            if (fel)
            {
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
            // felhők renderelés és ütközések ellenőrzése és lekezelése
            planetR = renderPlanet(game, planet1, planetR, l);
            // rendererbe tötött elemek képernyőre helyezése
            game.display();
        }
        // ablak törlése      
        game.cleanUp();
        // program bezárása
        SDL_Quit();
    }
    // kilépés gomb 
    else if (choice == 5)
    {
        return 0;
    }
    return 0;
}
