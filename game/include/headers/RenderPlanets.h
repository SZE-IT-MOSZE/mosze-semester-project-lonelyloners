#pragma once

#include <vector>
#include <stdio.h>

#include "headers/Entity.h"
#include "headers/RenderWindow.h"
#include "headers/Collision.h"
/**
 * \brief Rendererbe másolja a felhőket.
 *
 * A felhőket tartalmazó vektor elemeit jeleníti meg. Ezen felül ellenőrzi, 
 * hogy ütközik-e a mozgó karakterünkkel, és ha igen, akkor az igaz értékeket
 * tartalmazó vektor megfelelő indexű elemét hamisra állítja. Ezt az értéket 
 * veszi alapul a program, hogy kell-e az adott felhőt renderelni, mert volt
 * már ütközés.
 *  
 * \param planet A létrehozott ablak, ahol az Entityk helyezkednek el.
 * \param entitii A felhőket tartalmazó vektor.
 * \param pp A logikai változókat tartalmazó vektor.
 * \param l Az az Entity, amivel való ütközést ellenőrizni kívánjuk. 
 * \return A logikai változókat tartalmazó vektor, hogy a következő tick esetén
 *         is el legyen tüntetve az a felhő, amivel ütközés történt.
 */
std::vector<bool> renderPlanet(RenderWindow planet, std::vector<Entity> &entitii, std::vector<bool> pp, Entity& l)  
{
    int i = 0;
    bool c;
    // logikai változókat tartalmazó vektoron iterálás
    for(bool p : pp)
    {   
        // ütközés ellenőrzése
        c = Collision(l, entitii[i]);
        // ha történt ütközés, akkor a megfelelő indexű logikai változó hamisra állítása
        if (c)
            pp[i] = false;
        // ha nem volt ütközés, akkor felhő renderelése
        if (p)
            planet.render(entitii[i]);

        i++;
    }
    // visszaadjuk a logikai változókat tartalmazó vektort,
    // hogy a következő tickben se renderelje az összeütközött felhőt
    return pp;
}
