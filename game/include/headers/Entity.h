#pragma once
#include <sdl/SDL.h>
#include <SDL_Main.h> 
#include <sdl/SDL_image.h>

#include "headers/Math.h"

class Entity
{
public:
    Entity(V2F p_pos, SDL_Texture* p_tex);
    V2F& getPos()
    {
        return posi;
    }
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
    void setSize(int w, int h);

private:
    V2F posi;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
};

