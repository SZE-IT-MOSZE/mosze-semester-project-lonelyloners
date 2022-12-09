#pragma once

#include <sdl/SDL.h>
#include <SDL_Main.h> 
#include <sdl/SDL_image.h>

#include "headers/Math.h"

/**
 * \brief A megjelenítendő elemeket tartalmazó osztály.
 *
 * Ebben az osztályban találhatók a képernyőn megjelenő
 * elemek kezeléséért felelős függvények találhatók.
 * Itt lehet megadni az egyes elemek pozícióit és különféle
 * tulajdonságait.
 * 
 */

class Entity
{
public:

    Entity(V2F p_pos, SDL_Texture* p_tex);
    V2F& getPos() { return posi; }
    SDL_Texture* getTex();

    SDL_Rect getCurrentFrame();
    
    void setSize(int w, int h);
    void setPosi(int x, int y);
    void setAbsPosi(int x, int y);
    void setTarget(int direct, int distance);

    void setDirZero()   { d = 0;    }
    int getDirection()  { return d; }
    int getTargetX()    { return x; }
    int getTargetY()    { return y; }

private:

    V2F posi;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
    int d, x, y;
};