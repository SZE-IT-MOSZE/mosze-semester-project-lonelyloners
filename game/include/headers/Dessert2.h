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
#include "headers/Planet1.h"
   
RenderWindow dessert2(RenderWindow game, TTF_Font* fnt)
{  
    // egész számokból álló párokból álló vektorok definiálása
    std::vector<std::pair<int, int>> lyrsIdleR;
    std::vector<std::pair<int, int>> lyrsIdleL;
    std::vector<std::pair<int, int>> lyrsMoveR;
    std::vector<std::pair<int, int>> lyrsMoveL;
    std::vector<std::pair<int, int>> lyrsLaserR;
    std::vector<std::pair<int, int>> lyrsLaserL;

    std::vector<std::pair<int, int>> latnokIdleR;
    std::vector<std::pair<int, int>> latnokIdleL;
    std::vector<std::pair<int, int>> latnokMoveR;
    std::vector<std::pair<int, int>> latnokMoveL;


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
    latnokIdleR = { { 0,   0}, {32,   0}};
    // bal
    latnokIdleL = { { 64,   0}, {96,  0}};

    // LyRs séta animációjának a piozíciói
    // jobb
    latnokMoveR = { {  0,   0}, { 32,   0}, { 64,   0}, { 96,  0},  {128,  0} };
    // bal
    latnokMoveL = { {160,   0}, {192,   0}, {224,   0}, {256,  0},  {288,  0} };

    // LyRs összes animációját tartalmazó sprite sheet betöltése
    SDL_Texture* lyrsAnim = game.loadTexture("res/gfx/Animations/lyrs_sprite_sheet.png");
    Entity l(V2F(288, 0), lyrsAnim);
    l.setPosi(288 * game.getRES(), 0);
    // szöveg háttér betöltése
    SDL_Texture* textBckGround = game.loadTexture("res/gfx/Dessert_Map1/both.png");
    Entity txtbckground(V2F(384, 0), textBckGround);
    // beviteli mező háttere
    SDL_Texture* inputTextBckGround = game.loadTexture("res/gfx/Objects/blck_bckgrnd.png");
    Entity inptxtbckground(V2F(0, 384), inputTextBckGround);
    // logikai változókat tartalmazó vektor definiálása
    std::vector<bool> planetR = {};
    planetR = setPlanet1Pos();
    // első térkép hátterének betöltése
    SDL_Texture* background = game.loadTexture("res/gfx/Dessert_Map2/dessert_map2_alapmap.png");
    Entity pl(V2F(0, 0), background);
    // látnokondokok betöltése
    SDL_Texture* latnok1 = game.loadTexture("res/gfx/Animations/dessert_latnokondok1_idle.png");
    SDL_Texture* latnok2 = game.loadTexture("res/gfx/Animations/dessert_latnokondok2_idle.png");
    SDL_Texture* latnok3 = game.loadTexture("res/gfx/Animations/dessert_latnokondok3_idle.png");
    SDL_Texture* latnok4 = game.loadTexture("res/gfx/Animations/dessert_latnokondok4_idle.png");
    SDL_Texture* latnok5 = game.loadTexture("res/gfx/Animations/dessert_latnokondok5_idle.png");
    SDL_Texture* latnok6 = game.loadTexture("res/gfx/Animations/dessert_latnokondok6_idle.png");
    
    Entity latnok1E(V2F(0, 0), latnok1);
    Entity latnok2E(V2F(0, 0), latnok2);
    Entity latnok3E(V2F(0, 0), latnok3);
    Entity latnok4E(V2F(0, 0), latnok4);
    Entity latnok5E(V2F(0, 0), latnok5);
    Entity latnok6E(V2F(0, 0), latnok6);
    // térbeli kövek
    SDL_Texture* rocks = game.loadTexture("res/gfx/Dessert_Map2/dessert_map2_terbelikovek.png");
    Entity rocksEntity(V2F(0, 100), rocks);

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
    bool  next = false;
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
        game.render(pl);
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
        // terbeli kövek render
        game.render(rocksEntity);
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
    game.nextTxt(next);
    return game;
}