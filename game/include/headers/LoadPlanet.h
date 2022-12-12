#pragma once

#include <iostream>
#include <stdio.h>
#include <vector>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

/**
 * \brief Betölti a felhőket.
 *
 * Ez a függvény egy Entity-ket tartalmazó vektorba tölti, és
 * megfelelő pozícióval látja el a felhőket, ami az első mapon
 * fog megjelenni.
 * 
 * \param planet Az ablak, amin meg fognak jelenni a felhők.
 * \return Egy vektor, ami Entity-ket tartalmaz.
 */
std::vector<Entity> LoadPlanet(RenderWindow planet, const char* p) 
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
                i = -55;
                y = 45;
                {
                    SDL_Texture* cloud0 = planet.loadTexture(p);
                    Entity cl0(V2F(i, y), cloud0);
                    cl0.setSize(154,84);
                    resEntities.push_back(cl0);
                }
            case 1:
                i = 135;
                y = 65;             
                {
                    SDL_Texture* cloud1 = planet.loadTexture(p);
                    Entity cl1(V2F(i, y), cloud1);           
                    cl1.setSize(154,84);
                    resEntities.push_back(cl1);
                }
            case 2:
                i = 110;
                y = 160;             
                {
                    SDL_Texture* cloud2 = planet.loadTexture(p);
                    Entity cl2(V2F(i, y), cloud2);           
                    cl2.setSize(154,84);
                    resEntities.push_back(cl2);
                }
            case 3:
                i = -60;
                y = 220;  
                {           
                    SDL_Texture* cloud3 = planet.loadTexture(p);
                    Entity cl3(V2F(i, y), cloud3);           
                    cl3.setSize(154,84);
                    resEntities.push_back(cl3);
                }
            case 4:
                i = 50;
                y = 250;  
                {           
                    SDL_Texture* cloud4 = planet.loadTexture(p);
                    Entity cl4(V2F(i, y), cloud4);           
                    cl4.setSize(154,84);
                    resEntities.push_back(cl4);
                }
            case 5:
                i = 220;
                y = 5;  
                {           
                    SDL_Texture* cloud5 = planet.loadTexture(p);
                    Entity cl5(V2F(i, y), cloud5);           
                    cl5.setSize(154,84);
                    resEntities.push_back(cl5);
                }
            case 6:
                i = 250;
                y = 120;  
                {           
                    SDL_Texture* cloud6 = planet.loadTexture(p);
                    Entity cl6(V2F(i, y), cloud6);           
                    cl6.setSize(154,84);
                    resEntities.push_back(cl6);
                }
            case 7:
                i = 160;
                y = 270;  
                {           
                    SDL_Texture* cloud7 = planet.loadTexture(p);
                    Entity cl7(V2F(i, y), cloud7);           
                    cl7.setSize(154,84);
                    resEntities.push_back(cl7);
                }
            case 8:
                i = 230;
                y = 310;  
                {           
                    SDL_Texture* cloud8 = planet.loadTexture(p);
                    Entity cl8(V2F(i, y), cloud8);           
                    cl8.setSize(154,84);
                    resEntities.push_back(cl8);
                }
            case 9:
                i = 288;
                y = 96;  
                {           
                    SDL_Texture* cloud9 = planet.loadTexture(p);
                    Entity cl9(V2F(i, y), cloud9);           
                    cl9.setSize(154,84);
                    resEntities.push_back(cl9);
                }
            case 10:
                i = 80;
                y = 340;  
                {           
                    SDL_Texture* cloud10 = planet.loadTexture(p);
                    Entity cl10(V2F(i, y), cloud10);           
                    cl10.setSize(154,84);
                    resEntities.push_back(cl10);
                }
            case 11:
                i = -30;
                y = 150;  
                {           
                    SDL_Texture* cloud11 = planet.loadTexture(p);
                    Entity cl11(V2F(i, y), cloud11);           
                    cl11.setSize(154,84);
                    resEntities.push_back(cl11);
                }
            case 12:
                i = 64;
                y = 96;  
                {           
                    SDL_Texture* cloud12 = planet.loadTexture(p);
                    Entity cl12(V2F(i, y), cloud12);           
                    cl12.setSize(154,84);
                    resEntities.push_back(cl12);
                }
            case 13:
                i = -25;
                y = -35;  
                {           
                    SDL_Texture* cloud13 = planet.loadTexture(p);
                    Entity cl13(V2F(i, y), cloud13);           
                    cl13.setSize(154,84);
                    resEntities.push_back(cl13);
                }
            case 14:
                i = 128;
                y = -20;  
                {           
                    SDL_Texture* cloud14 = planet.loadTexture(p);
                    Entity cl14(V2F(i, y), cloud14);           
                    cl14.setSize(154,84);
                    resEntities.push_back(cl14);
                }
            case 15:
                i = 224;
                y = 224;  
                {           
                    SDL_Texture* cloud15 = planet.loadTexture(p);
                    Entity cl15(V2F(i, y), cloud15);           
                    cl15.setSize(154,84);
                    resEntities.push_back(cl15);
                }
            case 16:
                i = -32;
                y = 352;  
                {           
                    SDL_Texture* cloud16 = planet.loadTexture(p);
                    Entity cl16(V2F(i, y), cloud16);           
                    cl16.setSize(154,84);
                    resEntities.push_back(cl16);
                }
            case 17:
                i = -50;
                y = 270;  
                {           
                    SDL_Texture* cloud17 = planet.loadTexture(p);
                    Entity cl17(V2F(i, y), cloud17);           
                    cl17.setSize(154,84);
                    resEntities.push_back(cl17);
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
std::vector<bool> setPlanetPos() 
{
    std::vector<bool> toR;

    for(int i = 0; i < 18; i++)
    {
        toR.push_back(true);
    }

    return toR;
}