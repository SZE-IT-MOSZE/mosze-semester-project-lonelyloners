#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <sdl/SDL_ttf.h>
#include <sdl/SDL_ttf.h>

#include "headers/Map.h"

/**
 * \brief Bolygókat tartalmazó osztály.
 *
 * Ebben az osztályban találhatók a bolygók
 * megjelenítéséért felelős függvények.
 * 
 */
class Plnt
{
public:
    Plnt(RenderWindow game, TTF_Font* fnt);

    int menu();
    void prolog();
    void dessert1();
    void dessert2();
    void glacies();
    void planthea();
    void nosoria();
    void ladaPlusz() { lada++; };
    void sivatagiBogyoPlusz() { sivatagiBogyo++; };
    void faRonkPlusz() { faRonk++; };
    void nemSivatagiBogyoPlusz() { nemSivatagiBogyo++; };

    void talk() { beszel = true; };
    void enter() { belep = true; };

private:
    int lada, sivatagiBogyo, faRonk, nemSivatagiBogyo;
    bool kulcs, attack, beszel, belep;
    RenderWindow game;
    TTF_Font* fnt;
    // LyRs sprite sheet
    std::vector<std::pair<int, int>> lyrsIdleR;
    std::vector<std::pair<int, int>> lyrsIdleL;
    std::vector<std::pair<int, int>> lyrsMoveR;
    std::vector<std::pair<int, int>> lyrsMoveL;
    std::vector<std::pair<int, int>> lyrsLaserR;
    std::vector<std::pair<int, int>> lyrsLaserL;

};