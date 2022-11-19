#pragma once

#include <stdio.h>

#include "headers/Entity.h"
#include "headers/RenderWindow.h"

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
    bool x_overlaps = (pos1.getX() < pos2.getX() + second.getCurrentFrame().w) && (pos1.getX() + 32 > pos2.getX());
    bool y_overlaps = (pos1.getY() < pos2.getY() + second.getCurrentFrame().h) && (pos1.getY() + 32 > pos2.getY());
    // igazat ad vissza, ha volt átfedés 
    return (x_overlaps && y_overlaps);
}