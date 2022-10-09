#define SDL_MAIN_HANDLED

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

#include "headers/RenderWindow.h"
#include "headers/RenderPlanets.h"
#include "headers/Planet1.h"
#include "headers/Utils.h"
#include "headers/Entity.h"
#include "headers/Menu.h"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init hiba. SDL_ERROR: " << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_Init hiba. Error: " << SDL_GetError() << std::endl;
    }
    
    int choice = menu(); 
    
    if (choice == 1)
    {

        // ablak kirajzolása
        RenderWindow game("LonelyLoners - LyRs kalandjai v0.1", 384 * getR(), 384 * getR());

        std::vector<Entity> planet1 = {};
        planet1 = LoadPlanet1(game);

        SDL_Texture* lyrsPNG = game.loadTexture("res/gfx/Characters/lyrs_jobb.png");
        Entity lirs(V2F(90 * getR(), 16 * getR()), lyrsPNG);

        bool gameRunning = true;

        SDL_Event event;

        const float timeStep = 0.01f;
        float accum = 0.0f;
        float cTime = utils::hireTimeInSeconds();

        while(gameRunning)
        {
            // képkocka idők számolás    
            int startTick = SDL_GetTicks();

            float nTime = utils::hireTimeInSeconds();
            float fTime = nTime - cTime;

            cTime = nTime;
            accum += fTime;
            
            while(accum >= timeStep)
            {
                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        gameRunning = false;
                    }
                }
                accum -= timeStep;            
            }

            const float alpha = accum / timeStep;

            renderPlanet(game, planet1, lirs);     

        }
            game.cleanUp();
            SDL_Quit();
    }
    else if (choice == 5)
    {
        return 0;
    }

    return 0;
}
