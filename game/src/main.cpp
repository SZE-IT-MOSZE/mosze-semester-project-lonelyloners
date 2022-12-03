#define SDL_MAIN_HANDLED

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <sdl/SDL_ttf.h>

#include "headers/Router.h"
#include "headers/Command.h"
#include "headers/RenderPlanets.h"
#include "headers/Menu.h"
#include "headers/Prolog.h"
#include "headers/Dessert1.h"
#include "headers/Dessert2.h"
#include "headers/Glacies.h"

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
    RenderWindow game("LonelyLoners - LyRs kalandjai v0.2", 768 /* * getRRes() */, 484 /* * getRRes() */);
    // betűtípus betöltése
    TTF_Font* fnt = TTF_OpenFont("font/PatrickHand-Regular.ttf", 18);  
    // menü futtatása és menüpont számának elmentése
    int choice = menu(game);
    game.nextTxt(false);
    // renderer "takarítása"
    game.clear();
    // megfelelő menüpont futtatása
    if (choice == 1)
    {
        bool next;

        game = prolog(game, fnt);

        game = dessert1(game, fnt);

        game = dessert2(game, fnt);

        game = glacies(game, fnt);

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
