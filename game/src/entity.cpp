#include <fstream>
#include <iostream>
#include <string.h>
#include <sdl/SDL.h>
#include <sdl/SDL_Main.h> 
#include <sdl/SDL_image.h>
#include <iostream>
#include <fstream> 

#include "headers/Entity.h"

/**
 * \brief Létrehoz egy Entity-t.
 * 
 * A paraméterként kapott pozíció és textúra alapján létrehoz egy
 * téglalapot, ami meghatározza a betöltött kép helyét.
 * 
 * \param p_pos A kívánt pozíció.
 * \param p_tex A betölteni kívánt textúra.
 */
Entity::Entity(V2F p_pos, SDL_Texture*  p_tex) : posi(p_pos), tex(p_tex)
{
    // int resolution = getRES();
    // téglalap létrehozása
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 384;
    currentFrame.h = 384;
    // számok lenullázása 
    d = x = y = 0;
}
/**
 * \brief Beállítja egy Entity méretét.
 * 
 * Ha egy betöltött kép nem megfelelő méretű, akkor ezzel
 * a függvénnyel lehet méretezni.
 * 
 * \param w A kívánt szélesség.
 * \param h A kívánt magasság.
 */
void Entity::setSize(int w, int h)
{
    // int resolution = getRES();
    // Entity méretének beállítás kapott paraméterek alapján
    currentFrame.w = w;
    currentFrame.h = h;   
}
/**
 * \brief Beállítja egy Entity pozícióját.
 * 
 * Egy betöltött kép megfelelő pozícióba helyezését teszi lehetővé. 
 * 
 * \param x A kívánt pozíció az x tengelyen.
 * \param y A kívánt pozíció az y tengelyen.
 */
void Entity::setPosi(int x, int y)
{
    // Entity pozíciójának beállítása
    posi.x = ( currentFrame.x += x );
    posi.y = ( currentFrame.y += y );
}
/**
 * \brief Visszaadja az Entity textúráját.
 * 
 * Egy betöltött kép pixel pontos reprezentálásra szolgáló tulajdonságát adja vissza.
 * 
 * \return SDL_Texture.
 */
SDL_Texture* Entity::getTex()
{
    // Entity SDL_Texture változójának visszaadása 
    return tex;
}
/**
 * \brief Visszaadja az Entity téglalapját.
 * 
 * Egy betöltött kép helyzetét és méretét tartalmazó változót adja vissza.
 * Ez a változó egy téglalapot reprezentál.
 * 
 * \return SDL_Rect.
 */
SDL_Rect Entity::getCurrentFrame()
{
    // Entity SDL_Rect változójának visszaadása
    return currentFrame;
}
/**
 * \brief Megadja a cél pozíciót.
 * 
 * Megadott irány és távolság alapján beállítja
 * az elérni kívánt koordinátákat.
 * 
 */
void Entity::setTarget(int dir, int dist)
{
    // megadott irány eltárolása
    d = dir;

    // cél koordináták meghatározása és eltárolása
    switch(dir)
    {
    case 1:
        // fel
        x = posi.getX();
        y = posi.getY() - (dist * 32);
        break; 
    case 2:
        // jobbra
        x = posi.getX() + (dist * 32);
        y = posi.getY();
        break;  
    case 3:
        // le
        x = posi.getX();
        y = posi.getY() + (dist * 32);
        break;
    case 4: 
        // balra
        x = posi.getX() - (dist * 32);
        y = posi.getY();
        break;
    }
}


