// reading a text file

#pragma once

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

namespace settings
{
    /**
    * \brief A felbontás szorzó kiovasása.
    *
    * A felbontás egy szorzó segítségével van állítva, 
    * ez egy fájlban van tárolva, és ezt olvassa ki ez a függvény.   
    * 
    * \return Egész szaám, amivel meg kell szorozni a méreteket.
    */
    int getRES()
    {
        int i = 0;
        int RES = 1;
        std::string line;
        std::ifstream set;
        // beállítások fájl megnyitása
        set.open("user.settings");
        if (set.is_open())
        {
            while(getline(set, line))
            {
                i++;
                // felbontás szorzó az első sorban van tárolva 
                if (i = 1)
                {
                    // a visszaadandó változóbva olvassuk az első sort
                    RES = std::stoi(line);
                } 
            }
            set.close();
        }
        // hibakezelés, ha a fájl nem látezne
        else std::cout << "A beallítások fajl serult vagy nem letezik" << std::endl; 
        // szorzó visszaadása
        return RES;
    }
}

