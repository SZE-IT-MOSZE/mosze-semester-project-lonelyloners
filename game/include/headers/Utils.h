#pragma once

#include <sdl/SDL.h>

namespace utils
{
    /**
     * \brief Eltelt idő.
     * 
     * A futás kezdete óta eltelt időt számolja ki, és adja vissza.
     * 
     * \return Eltelt idő.
     */    
    inline float hireTimeInSeconds()
    {
        float t = float(SDL_GetTicks());
        t *= 0.001f;

        return t;
    }

}