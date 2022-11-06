#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include "headers/Menu.h"
/**
 * \brief Betölti a felhőket.
 *
 * Ez a függvény egy Entity-ket tartalmazó vektorba tölti, és
 * megfelelő pozícióval látja el a felhőket, ami az első mapon
 * fog megjelenni.
 * 
 * \param planet1 Az ablak, amin meg fognak jelenni a felhők.
 * \return Egy vektor, ami Entity-ket tartalmaz.
 */
std::vector<Entity> LoadPlanet1(RenderWindow planet1) 
{
    int i = 0;
    int y = 0;
    // vektor létrehozás a felhőknek
    std::vector<Entity> resEntities;
    // felhők a megfelelő koordinátákkal vektorba töltése
    for (int z = 0; z < 10; z++)
    {
        switch(z)
        {
            case 0:
                i = -55 /* * getR() */;
                y = 45 /* * getR() */;
                {
                    SDL_Texture* cloud0 = planet1.loadTexture("res/gfx/Dessert_Map1/dessert_map1_felho.png");
                    Entity cl0(V2F(i, y), cloud0);
                    cl0.setSize(154,84);
                    resEntities.push_back(cl0);
                }
            case 1:
                i = 135 /* * getR() */;
                y = 65 /* * getR() */;             
                {
                    SDL_Texture* cloud1 = planet1.loadTexture("res/gfx/Dessert_Map1/dessert_map1_felho.png");
                    Entity cl1(V2F(i, y), cloud1);           
                    cl1.setSize(154,84);
                    resEntities.push_back(cl1);
                }
            case 2:
                i = 110 /* * getR() */;
                y = 160 /* * getR() */;             
                {
                    SDL_Texture* cloud2 = planet1.loadTexture("res/gfx/Dessert_Map1/dessert_map1_felho.png");
                    Entity cl2(V2F(i, y), cloud2);           
                    cl2.setSize(154,84);
                    resEntities.push_back(cl2);
                }
            case 3:
                i = -60 /* * getR() */;
                y = 220 /* * getR() */;  
                {           
                    SDL_Texture* cloud3 = planet1.loadTexture("res/gfx/Dessert_Map1/dessert_map1_felho.png");
                    Entity cl3(V2F(i, y), cloud3);           
                    cl3.setSize(154,84);
                    resEntities.push_back(cl3);
                }
            case 4:
                i = 50 /* * getR() */;
                y = 250 /* * getR() */;  
                {           
                    SDL_Texture* cloud4 = planet1.loadTexture("res/gfx/Dessert_Map1/dessert_map1_felho.png");
                    Entity cl4(V2F(i, y), cloud4);           
                    cl4.setSize(154,84);
                    resEntities.push_back(cl4);
                }
            case 5:
                i = 220 /* * getR() */;
                y = 5 /* * getR() */;  
                {           
                    SDL_Texture* cloud5 = planet1.loadTexture("res/gfx/Dessert_Map1/dessert_map1_felho.png");
                    Entity cl5(V2F(i, y), cloud5);           
                    cl5.setSize(154,84);
                    resEntities.push_back(cl5);
                }
            case 6:
                i = 250 /* * getR() */;
                y = 120 /* * getR() */;  
                {           
                    SDL_Texture* cloud6 = planet1.loadTexture("res/gfx/Dessert_Map1/dessert_map1_felho.png");
                    Entity cl6(V2F(i, y), cloud6);           
                    cl6.setSize(154,84);
                    resEntities.push_back(cl6);
                }
            case 7:
                i = 160 /* * getR() */;
                y = 270 /* * getR() */;  
                {           
                    SDL_Texture* cloud7 = planet1.loadTexture("res/gfx/Dessert_Map1/dessert_map1_felho.png");
                    Entity cl7(V2F(i, y), cloud7);           
                    cl7.setSize(154,84);
                    resEntities.push_back(cl7);
                }
            case 8:
                i = 230 /* * getR() */;
                y = 310 /* * getR() */;  
                {           
                    SDL_Texture* cloud8 = planet1.loadTexture("res/gfx/Dessert_Map1/dessert_map1_felho.png");
                    Entity cl8(V2F(i, y), cloud8);           
                    cl8.setSize(154,84);
                    resEntities.push_back(cl8);
                }
        } 
    }

    return resEntities;     
}
/**
 * \brief Feltölti igaz értékekkel a felhő vektort.
 *
 * Ez a függvény annyi igaz értéket vesz fel, amennyi felhőt betöltöttünk.
 *  
 * \return Egy vektor, ami igaz értékeket tartalmaz.
*/
std::vector<bool> setPlanet1Pos() 
{
    std::vector<bool> toR;

    for(int i = 0; i < 10; i++)
    {
        toR.push_back(true);
    }

    return toR;     
}