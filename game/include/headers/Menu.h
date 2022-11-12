#pragma once

#include "headers/RenderWindow.h"
#include "headers/Utils.h"

// int getR()
// {
//     int i = 0;
//     int RES = 1;
//     std::string line;
//     std::ifstream set;
//     set.open("user.settings");
//     if (set.is_open())
//     {
//         while(getline(set, line))
//         {
//             i++;
//             if (i = 1)
//             {
//                 RES = std::stoi(line);
//             } 
//         }
//         set.close();
//     }
//     
//     else std::cout << "A beallítások fajl serult vagy nem letezik" << std::endl; 
// 
//     return RES;
// }
/**
 * \brief Menü megjelenítése.
 *
 * Egy képernyőt kap bemeti paraméterként, amire megjelenik a menü.
 * Visszatérési értékként egy integer szolgál, ami reprezentálja a 
 * megnyitásra szánt menüpontot.
 * 
 * \param menuWindow az ablak, amire megjelenítjük a menüt.
 * \return Egy szám, ami a megnyomott menüponto jelenti.
 */
int menu(RenderWindow menuWindow)
{
    int selectednumber;
    bool menu = true;
    std::string input;
    int c,i=0;
    char str[100];
    
    // betűtípus betöltése
    TTF_Font* fnt = TTF_OpenFont("font/PatrickHand-Regular.ttf", 18);  

    SDL_Texture* newGame = nullptr;
    // háttér betöltése
    SDL_Texture* mnuBckGround = menuWindow.loadTexture("res/gfx/Menu/menu_hatter.png");
    Entity bckground(V2F(0, 0), mnuBckGround);
    
    // szöveg háttér betöltése
    SDL_Texture* textBckGround = menuWindow.loadTexture("res/gfx/Dessert_Map1/both.png");
    Entity txtbckground(V2F(384, 0), textBckGround);

    // nagy új játék gomb
    SDL_Texture* newGameButton = menuWindow.loadTexture("res/gfx/Menu/menu_alap_nagy_ujjatek.png");
    Entity nGameB(V2F(30 /* * getR() */, 20 /* * getR() */), newGameButton);
    nGameB.setSize(125,65);

    // nagy új játék gomb lenyomott
    SDL_Texture* newGameButtonDown = menuWindow.loadTexture("res/gfx/Menu/menu_alap_nagy_benyomott_ujjatek.png");
    Entity nGameBD(V2F(30 /* * getR() */, 20 /* * getR() */), newGameButtonDown);
    nGameBD.setSize(125,65);

    // betöltés gomb
    SDL_Texture* loadGameButton = menuWindow.loadTexture("res/gfx/Menu/menu_alap_betoltes.png");
    Entity lgGameB(V2F(35 /* * getR() */, 116 /* * getR() */), loadGameButton);
    lgGameB.setSize(95,43);

    // betöltés gomb lenyomott
    SDL_Texture* loadGameButtonDown = menuWindow.loadTexture("res/gfx/Menu/menu_alap_benyomott_betoltes.png");
    Entity lgGameBD(V2F(35 /* * getR() */, 116 /* * getR() */), loadGameButtonDown);
    lgGameBD.setSize(95,43);

    // segítség gomb    
    SDL_Texture* helpGameButton = menuWindow.loadTexture("res/gfx/Menu/menu_alap_segitseg.png");
    Entity hlpGameB(V2F(35 /* * getR() */, 189 /* * getR() */), helpGameButton);
    hlpGameB.setSize(95,43);

    // segítség gomb lenyomott
    SDL_Texture* helpGameButtonDown = menuWindow.loadTexture("res/gfx/Menu/menu_alap_benyomott_segitseg.png");
    Entity hlpGameBD(V2F(35 /* * getR() */, 189 /* * getR() */), helpGameButtonDown);
    hlpGameBD.setSize(95,43);

    // beállítások gomb
    SDL_Texture* setGameButton = menuWindow.loadTexture("res/gfx/Menu/menu_alap_beallitas.png");
    Entity setGameB(V2F(385 /* * getR() */ - 35 /* * getR() */ - 95 /* * getR() */, 116 /* * getR() */), setGameButton);
    setGameB.setSize(95,43);

    // beállítások gomb lenyomott
    SDL_Texture* setGameButtonDown = menuWindow.loadTexture("res/gfx/Menu/menu_alap_benyomott_beallitas.png");
    Entity setGameBD(V2F(384 /* * getR() */ - 35 /* * getR() */ - 95 /* * getR() */, 116 /* * getR() */), setGameButtonDown);
    setGameBD.setSize(95,43);

    // kilépés gomb
    SDL_Texture* exitGameButton = menuWindow.loadTexture("res/gfx/Menu/menu_alap_kilepes.png");
    Entity eGameB(V2F(385 /* * getR() */ - 35 /* * getR() */ - 95 /* * getR() */, 189 /* * getR() */), exitGameButton);
    eGameB.setSize(95,43);

    // kilépés gomb lenyomott
    SDL_Texture* exitGameButtonDown = menuWindow.loadTexture("res/gfx/Menu/menu_alap_benyomott_kilepes.png");
    Entity eGameBD(V2F(384 /* * getR() */ - 35 /* * getR() */ - 95 /* * getR() */, 189 /* * getR() */), exitGameButtonDown);
    eGameBD.setSize(95,43);
    // fő ciklus változó
    bool menuRunning = true;

    newGame = newGameButton;
    // event létrehozás a menü ciklushoz
    SDL_Event event;

    const float timeStep = 0.01f;
    float accum = 0.0f;
    float cTime = utils::hireTimeInSeconds();
    // fő menü ciklus
    while(menuRunning)
    {
        // képkocka idők számolás    
        int startTick = SDL_GetTicks();

        float nTime = utils::hireTimeInSeconds();
        float fTime = nTime - cTime;

        cTime = nTime;
        accum += fTime;
        // logikai változók a gombokhoz
        bool nGameDown = false;
        bool eGameDown = false;
        bool lgGameDown = false;
        bool hlpGameDown = false;
        bool setGameDown = false;

        while(accum >= timeStep)
        {
            // események vezérlése
            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                    {
                        // új játék gomb lenyomásának ellenőrzése
                        if (event.button.button = SDL_BUTTON_LEFT
                        and event.button.x > 30 /* * getR() */
                        and event.button.x < 30 /* * getR() */ + 125 /* * getR() */
                        and event.button.y > 20 /* * getR() */ 
                        and event.button.y < (20 + 65) /* * getR() */
                        ) 
                        {
                            nGameDown = true;
                        }
                        // betöltés gomb lenyomásának ellenőrzése
                        else if (event.button.button = SDL_BUTTON_LEFT
                        and event.button.x > 35 /* * getR() */ 
                        and event.button.x < 35 /* * getR() */ + 95 /* * getR() */  
                        and event.button.y > 116 /* * getR() */ 
                        and event.button.y < 116 /* * getR() */ + 35 /* * getR() */
                        ) 
                        {
                            lgGameDown = true;
                        }
                        // segítség gomb lenyomásának ellenőrzése
                        else if (event.button.button = SDL_BUTTON_LEFT
                        and event.button.x > 35 /* * getR() */ 
                        and event.button.x < 35 /* * getR() */ + 95 /* * getR() */  
                        and event.button.y > 189 /* * getR() */ 
                        and event.button.y < 189 /* * getR() */ + 35 /* * getR() */
                        ) 
                        {
                            hlpGameDown = true;
                        }   
                        // beállítások gomb lenyomásának ellenőrzése
                        else if (event.button.button = SDL_BUTTON_LEFT
                        and event.button.x > 384 /* * getR() */ - 35 /* * getR() */ - 95 /* * getR() */ 
                        and event.button.x < 384 /* * getR() */ - 35 /* * getR() */
                        and event.button.y > 116 /* * getR() */ 
                        and event.button.y < 116 /* * getR() */ + 35 /* * getR() */
                        ) 
                        {
                            setGameDown = true;
                        }
                        // kilépés gomb lenyomásának ellenőrzése
                        else if (event.button.button = SDL_BUTTON_LEFT
                        and event.button.x > 384 /* * getR() */ - 35 /* * getR() */ - 95 /* * getR() */ 
                        and event.button.x < 384 /* * getR() */ - 35 /* * getR() */
                        and event.button.y > 189 /* * getR() */ 
                        and event.button.y < 189 /* * getR() */ + 35 /* * getR() */
                        ) 
                        {
                            eGameDown = true;
                        }

                    }
                }
             }
            accum -= timeStep;  
        }

        const float alpha = accum / timeStep;       

        if (nGameDown)
        {
            menuWindow.render(nGameBD);
            selectednumber = 1;
            menuWindow.display();
            SDL_Delay(500);
            menuRunning = false;
        }

        else if (lgGameDown)
        {
            menuWindow.render(lgGameBD);
            selectednumber = 2;
            menuWindow.display();
            SDL_Delay(500);
            menuRunning = false;
        }
        else if (hlpGameDown)
        {
            menuWindow.render(hlpGameBD);
            selectednumber = 3;
            menuWindow.display();
            SDL_Delay(500);
            menuRunning = false;
        }
        else if (setGameDown)
        {
            menuWindow.render(setGameBD);
            selectednumber = 4;
            menuWindow.display();
            SDL_Delay(500);
            menuRunning = false;
        }
        else if (eGameDown)
        {
            menuWindow.render(eGameBD);
            selectednumber = 5;
            menuWindow.display();
            SDL_Delay(500);
            menuRunning = false;
        }
        // gombok megjelenítése
        menuWindow.render(bckground);  
        menuWindow.render(txtbckground); 
        menuWindow.renderText("story/bevezeto.txt", fnt);
        menuWindow.render(nGameB);
        menuWindow.render(lgGameB);
        menuWindow.render(hlpGameB);
        menuWindow.render(setGameB);  
        menuWindow.render(eGameB);  
        menuWindow.display();
    }


    return selectednumber;
}