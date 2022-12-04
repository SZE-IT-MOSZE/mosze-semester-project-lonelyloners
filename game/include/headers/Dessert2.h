#pragma once

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <sdl/SDL_ttf.h>

#include "headers/Router.h"
#include "headers/LoadPlanet.h"
   
RenderWindow dessert2(RenderWindow game, TTF_Font* fnt)
{  
    // egész számokból álló párokból álló vektorok definiálása
    std::vector<std::pair<int, int>> lyrsIdleR;
    std::vector<std::pair<int, int>> lyrsIdleL;
    std::vector<std::pair<int, int>> lyrsMoveR;
    std::vector<std::pair<int, int>> lyrsMoveL;
    std::vector<std::pair<int, int>> lyrsLaserR;
    std::vector<std::pair<int, int>> lyrsLaserL;

    std::vector<std::pair<int, int>> npcIdleR;
    std::vector<std::pair<int, int>> npcIdleL;
    std::vector<std::pair<int, int>> latnokMoveR;
    std::vector<std::pair<int, int>> latnokMoveL;
    std::vector<std::pair<int, int>> antMoveR;
    std::vector<std::pair<int, int>> antMoveL;
    std::vector<std::pair<int, int>> urgeIdleL;
    std::vector<std::pair<int, int>> urgeIdleR;
    std::vector<std::pair<int, int>> urgeAttackL;
    std::vector<std::pair<int, int>> urgeAttackR;

    std::vector<std::pair<int, int>> map;

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

    // Látnokond üresjárati
    // jobb
    npcIdleR = { { 0,   0}, {32,   0}};
    // bal
    npcIdleL = { { 64,   0}, {96,  0}};

    // látnokondokok séta animációjának a pozíciói
    // jobb
    latnokMoveR = { {  0,   0}, { 32,   0}, { 64,   0}, { 96,  0},  {128,  0} };
    // bal
    latnokMoveL = { {160,   0}, {192,   0}, {224,   0}, {256,  0},  {288,  0} };

    // hangya séta animációjának a pozíciói
    // jobb
    antMoveR = { {  0,   0}, { 32,   0}, { 64,   0}, { 96,  0} };
    // bal
    antMoveL = { {128,  0}, {160,   0}, {192,   0}, {224,   0} };

    // urge séta üresjárati 
    // jobb
    urgeIdleR = { {  0,   0}, { 32,   0}, { 64,   0}, { 96,  0},  {128,  0},  {160,  0},  {192,  0},  {224,  0},  {256,  0},  {288,  0} };
    // bal
    urgeIdleL = { {320,   0}, {352,   0}, {384,   0}, {416,  0},  {448,  0},  {480,  0},  {512,  0},  {544,  0},  {576,  0},  {608,  0} };
    
    // urge támadás 
    // jobb
    urgeIdleR = { {  0,   0}, { 64,   0},  {128,  0}, {192,  0},  {256,  0},  {320,  0},  {384,  0},  {448,  0} };
    // bal
    urgeIdleL = { {512,   0}, {576,   0}, {640,   0}, {704,  0},  {768,  0},  {832,  0},  {896,  0},  {960,  0} };


    // map
    map             = { {  0,   0}, {384,   0},
                        {  0, 384}, {384, 384}};

    // LyRs összes animációját tartalmazó sprite sheet betöltése
    SDL_Texture* lyrsAnim = game.loadTexture("res/gfx/Animations/lyrs_sprite_sheet.png");
    Entity l(V2F(288, 32), lyrsAnim);
    l.setPosi(288 * game.getRES(), 32 * game.getRES());
    // szöveg háttér betöltése
    SDL_Texture* textBckGround = game.loadTexture("res/gfx/Dessert_Map1/both.png");
    Entity txtbckground(V2F(384, 0), textBckGround);
    // beviteli mező háttere
    SDL_Texture* inputTextBckGround = game.loadTexture("res/gfx/Objects/blck_bckgrnd.png");
    Entity inptxtbckground(V2F(0, 384), inputTextBckGround);
    // első térkép hátterének betöltése
    SDL_Texture* background = game.loadTexture("res/gfx/Dessert_Map2/dessert_map2.png");
    Entity pl(V2F(0, 0), background);
    // látnokondokok betöltése
    SDL_Texture* latnok1 = game.loadTexture("res/gfx/Animations/dessert_latnokondok1_idle.png");
    SDL_Texture* latnok2 = game.loadTexture("res/gfx/Animations/dessert_latnokondok2_idle.png");
    SDL_Texture* latnok3 = game.loadTexture("res/gfx/Animations/dessert_latnokondok3_idle.png");
    SDL_Texture* latnok4 = game.loadTexture("res/gfx/Animations/dessert_latnokondok4_idle.png");
    SDL_Texture* latnok5 = game.loadTexture("res/gfx/Animations/dessert_latnokondok5_idle.png");
    SDL_Texture* latnok6 = game.loadTexture("res/gfx/Animations/dessert_latnokondok6_idle.png");
    
    SDL_Texture* latnok1a = game.loadTexture("res/gfx/Animations/dessert_latnokondok1_anim.png");
    SDL_Texture* latnok2a = game.loadTexture("res/gfx/Animations/dessert_latnokondok2_anim.png");
    SDL_Texture* latnok3a = game.loadTexture("res/gfx/Animations/dessert_latnokondok3_anim.png");
    SDL_Texture* latnok4a = game.loadTexture("res/gfx/Animations/dessert_latnokondok4_anim.png");
    SDL_Texture* latnok5a = game.loadTexture("res/gfx/Animations/dessert_latnokondok5_anim.png");
    SDL_Texture* latnok6a = game.loadTexture("res/gfx/Animations/dessert_latnokondok6_anim.png");
    
    SDL_Texture* chst = game.loadTexture("res/gfx/Dessert_Map2/dessert_map2_chest.png");
    Entity chstE(V2F(224, 116), chst);
    chstE.setSize(120, 50);

    Entity latnok1E(V2F(0,0), latnok1);
    Entity latnok2E(V2F(0,0), latnok2);
    Entity latnok3E(V2F(0,0), latnok3);
    Entity latnok4E(V2F(0, 0), latnok4);
    Entity latnok5E(V2F(192, 96), latnok5);
    Entity latnok6E(V2F(96, 352), latnok6);
    
    Entity latnok1Ea(V2F(0, 0), latnok1a);
    Entity latnok2Ea(V2F(0, 0), latnok2a);
    Entity latnok3Ea(V2F(0, 0), latnok3a);
    Entity latnok4Ea(V2F(0, 0), latnok4a);
    Entity latnok5Ea(V2F(192, 96), latnok5a);
    Entity latnok6Ea(V2F(96, 352), latnok6a);

    latnok1Ea.setPosi(-32, 96);
    latnok2Ea.setPosi(-64, 96);
    latnok3Ea.setPosi(-96, 96);
    
    latnok1E.setPosi(64, 96);
    latnok2E.setPosi(96, 96);
    latnok3E.setPosi(128, 96);

    SDL_Texture* antI1 = game.loadTexture("res/gfx/Animations/dessert_hangya_idle.png");
    Entity antEI1(V2F(0,0), antI1);
    antEI1.setPosi(192, 96);
    
    SDL_Texture* antI2 = game.loadTexture("res/gfx/Animations/dessert_hangya_idle.png");
    Entity antEI2(V2F(0,0), antI2);
    antEI2.setPosi(224, 96);

    SDL_Texture* antI3 = game.loadTexture("res/gfx/Animations/dessert_hangya_idle.png");
    Entity antEI3(V2F(0,0), antI3);
    antEI3.setPosi(320, 96);

    SDL_Texture* antA = game.loadTexture("res/gfx/Animations/dessert_hangya_seta.png");
    Entity antEA(V2F(0,0), antA);
    
    // urge
    SDL_Texture* urge1 = game.loadTexture("res/gfx/Animations/dessert_urge_idle.png");
    Entity urgeE1(V2F(0,0), urge1);
    urgeE1.setPosi(192, 320);
    SDL_Texture* urge2 = game.loadTexture("res/gfx/Animations/dessert_urge_idle.png");
    Entity urgeE2(V2F(0,0), urge2);
    urgeE2.setPosi(224, 320);

    // térbeli kövek
    SDL_Texture* rocks = game.loadTexture("res/gfx/Dessert_Map2/dessert_map2_rocks.png");
    Entity rocksEntity(V2F(0, 0), rocks);

    // Entity vector létrehozása
    std::vector<Entity> planet1 = {};
    planet1 = LoadPlanet(game, "res/gfx/Dessert_Map2/dessert_map2_felho.png");
    // logikai változókat tartalmazó vektorok definiálása
    std::vector<bool> planetR1 = {};
    planetR1 = setPlanetPos();

    std::vector<bool> planetR2 = {};
    planetR2 = setPlanetPos();

    std::vector<bool> planetR3 = {};
    planetR3 = setPlanetPos();

    std::vector<bool> planetR4 = {};
    planetR4 = setPlanetPos();


    // parancs választó deklarálása
    Router r = Router();

    // összes logikai változó a gombnyomásokhoz
    bool gameRunning = true;
    bool attack = false;
    bool fel = false;
    bool le = false;
    bool jobbra = false;
    bool balra = false;
    bool flip = false;
    bool beszel = false;
    bool belep = false;
    bool next = false;
    bool a = false;
    bool b = false;
    bool start = false;

    // esemény létrehozása
    SDL_Event event;
    // FPS limitációhoz szükséges változók
    const float timeStep = 0.01f;
    float accum = 0.0f;
    float cTime = utils::hireTimeInSeconds();
    // input text 
    std::string command;
    
    game.nextTxt(next);

    gameRunning = true;
    // dessert1
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
                            if (!fel && !le && !balra && !jobbra && !attack)
                            {
                                Command c = Command(command);
                                c.make();
                                r.route(c.getCommand(), c.getItem(), l);
                                if (command == "LAPOZZ")
                                {
                                    game.nextPage();
                                }
                                if (command == "TAMADAS")
                                {
                                    attack = true;
                                }
                                if (command == "POSI")
                                {
                                    std::cout << " CURRENT POSITION: " << l.getPos().getY() << " \t " << l.getPos().getX() << std::endl;
                                }
                                if (command == "TARGET")
                                {
                                    std::cout << " TARGET COORDINATE: " << l.getTargetY() << " \t " << l.getTargetX() << std::endl;
                                }
                                if (command == "BELEP")
                                {
                                    belep = true;
                                }
                                if (command == "BESZEL")
                                {
                                    beszel = true;
                                }
                                command = "";
                            }
                        }
                }
            }
            accum -= timeStep;
        }           
        const float alpha = accum / timeStep;    

        // megfelelő map kirenderelése
        if (game.getMap() == 0 && l.getPos().getY() == 320 && l.getPos().getX() >= 384)
        {
            // MAP 1 -> MAP 2
            game.setMap(1);

            l.setPosi(-416, 0);

            l.setTarget(2, 1);
        }
        else if (game.getMap() == 1 && l.getPos().getY() == 320 && l.getPos().getX() <= -32)
        {
            // MAP 2 -> MAP 1
            game.setMap(0);

            l.setPosi(416, 0);

            l.setTarget(4, 1);
        }
        else if (game.getMap() == 0 && l.getPos().getY()  >= 384 && l.getPos().getX() == 32)
        {
            // MAP 1 -> MAP 3
            game.setMap(2);

            l.setPosi(0, -416);

            l.setTarget(3, 1);
        }
        else if (game.getMap() == 2 && l.getPos().getY() == -32 && l.getPos().getX() == 32)
        {
            // MAP 3 -> MAP 1
            game.setMap(0);

            l.setPosi(0, 416);

            l.setTarget(1, 1);
        }
        else if (game.getMap() == 0 && l.getPos().getY()  >= 384 && l.getPos().getX() == 128)
        {
            // MAP 1 -> MAP 3
            game.setMap(2);

            l.setPosi(0, -416);

            l.setTarget(3, 1);
        }
        else if (game.getMap() == 2 && l.getPos().getY() == -32 && l.getPos().getX() == 128)
        {
            // MAP 3 -> MAP 1
            game.setMap(0);

            l.setPosi(0, 416);

            l.setTarget(1, 1);
        }
        else if (game.getMap() == 2 && l.getPos().getY() == 64 && l.getPos().getX() >= 384)
        {
            // MAP 3 -> MAP 4
            game.setMap(3);

            l.setPosi(-416, 0);

            l.setTarget(2, 1);
        }
        else if (game.getMap() == 3 && l.getPos().getY() == 64 && l.getPos().getX() <= -32)
        {
            // MAP 4 -> MAP 3
            game.setMap(2);

            l.setPosi(416, 0);

            l.setTarget(4, 1);
        }

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
        case 5:
            attack = true;
        default:
            break;
        }
        // először a háttér kirajzolása
        game.updateMap(pl, map);

        if (!fel && !le && !balra && !jobbra && !attack)
        {
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra néző üresjárati animáció következő kockája
                game.update(l, lyrsIdleR, lyrsIdleR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra néző üresjárati animáció következő kockája
                game.update(l, lyrsIdleL, lyrsIdleL.size(), 32, 32, 0, true);
            }
            // if (l.getPos().getX() != l.getTargetX() || l.getPos().getY() != l.getTargetY())
            // {
            //     l.setPosi(l.getPos().getX(), l.getPos().getY());
            // } 
        }
        // felfele gomb megnyomva?
        if (fel && !attack)
        {                
            if (l.getPos().getY() <= l.getTargetY())
            {
                fel = false;
                if ((l.getPos().getY() != l.getTargetY()))
                {
                    l.setPosi(l.getPos().getX(), l.getTargetY());
                }
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása fel
                game.up(l);
            }

            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra mozog animáció következő kockája
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra mozog animáció következő kockája
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            }
        }
        // lefele gomb megnyomva?
        if (le && !attack)
        {
            if (l.getPos().getY() >= l.getTargetY())
            {
                le = false;
                if ((l.getPos().getY() != l.getTargetY()))
                {
                    l.setPosi(l.getPos().getX(), l.getTargetY());
                }
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása le
                game.down(l);
            }
            // jobbra gomb volt utoljára lenyomva?
            if (flip)
            {
                // LyRs jobbra mozog animáció következő kockája
                game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
            }
            else
            {
                // LyRs balra mozog animáció következő kockája
                game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            }
        }
        // balra gomb megnyomva?
        if (balra && !attack)
        {
            if (l.getPos().getX() <= l.getTargetX())
            {
                balra = false;
                // irány 0-ra állítása, hogy következő tick esetén ne állítsa megint az irányt
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása balra
                game.left(l);
            }
            // LyRs balra mozog animáció következő kockája
            game.update(l, lyrsMoveL, lyrsMoveL.size(), 32, 32, 0, true);
            // összes animáció balra néz
            flip = false;
        }
        // jobbra gomb megnyomva?
        if (jobbra && !attack)
        {
            if (l.getPos().getX() >= l.getTargetX())
            {
                jobbra = false;
                l.setDirZero();
            }
            else
            {
                // LyRs mozgatása jobbra
                game.right(l);
            }
            // LyRs jobbra mozog animáció következő kockája
            game.update(l, lyrsMoveR, lyrsMoveR.size(), 32, 32, 0, true);
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
                attack = game.update(l, lyrsLaserR, lyrsLaserR.size(), 64, 32, 0, false);
            }
            else
            {
                // LyRs balra támad animáció következő kockája
                attack = game.update(l, lyrsLaserL, lyrsLaserL.size(), 64, 32, 32, false);
            }
        }
        if (l.getPos().getY() == 256 && l.getPos().getX() == 32 && belep) 
        {
            gameRunning = false;
        }
        switch (game.getMap())  {
            case 0:
                game.update(latnok5E, npcIdleL, npcIdleL.size(), 32, 32, 0, true);
                game.update(latnok6E, npcIdleR, npcIdleL.size(), 32, 32, 0, true);
                if (l.getPos().getX() == 160 && l.getPos().getY() == 96 && beszel)
                {
                    if (!a)
                    {
                        game.nextTxt(false);
                        a = true;
                    }
                    if (game.getPage() == 7 && !b)
                    {
                        start = true;
                        b = true;
                    }
                }
                if (start)
                {
                    if (latnok1Ea.getPos().getX() < 65)
                    {
                        game.right(latnok1Ea);
                        game.update(latnok1Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                    }
                    else 
                    {                        
                        game.update(latnok1E, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                    }
                    if (latnok2Ea.getPos().getX() < 97)
                    {
                        game.right(latnok2Ea);
                        game.update(latnok2Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                    }
                    else
                    {                        
                        game.update(latnok2E, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                    }
                    if (latnok3Ea.getPos().getX() < 129)
                    {
                        game.right(latnok3Ea);
                        game.update(latnok3Ea, latnokMoveR, latnokMoveR.size(), 32, 32, 0, true);
                    }
                    else
                    {                        
                        game.update(latnok3E, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                    }
                }
                // felhők renderelése és ütközések ellenőrzése és lekezelése
                planetR1 = renderPlanet(game, planet1, planetR1, l);

                break;
            case 1:
                
                game.render(chstE);

                game.update(antEI1, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                game.update(antEI2, npcIdleR, npcIdleR.size(), 32, 32, 0, true);
                game.update(antEI3, npcIdleL, npcIdleL.size(), 32, 32, 0, true);
                
                // felhők renderelése és ütközések ellenőrzése és lekezelése
                planetR2 = renderPlanet(game, planet1, planetR2, l);

                break;
            case 2:

                game.update(urgeE1, urgeIdleR, urgeIdleR.size(), 32, 32, 0, true);
                game.update(urgeE2, urgeIdleR, urgeIdleR.size(), 32, 32, 0, true);


                break;
            //case 3:
        }

        // terbeli kövek render
        game.updateMap(rocksEntity, map);
        game.render(inptxtbckground);
        game.renderInputText(command, fnt);
        // szöveg háttér
        game.render(txtbckground);
        game.renderText(fnt);
        // rendererbe tötött elemek képernyőre helyezése
        game.display();
        // TODO:
        // delete c; 
    }
    game.mapReset();
    game.nextTxt(next);
    return game;
}