#pragma once

#include <stdio.h>

#include "headers/Entity.h"
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

/**
 * \brief Ellenőrzi, hogy két entity ütközik-e.
 *
 * Két Entity-t hasonlít össze, és ellenőrzi, hogy van-e közös terület.
 * 
 * \param first Az első Entity.
 * \param second A második Entity.
 * \return Igaz, ha van ütközés, hamis, ha nincs.
 */
bool Collision(Entity& first, Entity& second)
{
    // az első Entity pozíciója
    V2F pos1;
    pos1 = first.getPos();
    // a második Entity pozíciója
    V2F pos2;
    pos2 = second.getPos();
    // átfedés ellenőrzése
    bool x_overlaps = (pos1.getX() < (pos2.getX() + second.getCurrentFrame().w) ) && (pos1.getX() + 32 > pos2.getX());
    bool y_overlaps = (pos1.getY() < (pos2.getY() + second.getCurrentFrame().h) ) && (pos1.getY() + 32 > pos2.getY());
    // std::cout << pos1.getX() << " \t " << pos2.getX() << " \t " << second.getCurrentFrame().w << std::endl << std::endl;
    // igazat ad vissza, ha volt átfedés
    return (x_overlaps && y_overlaps);
}