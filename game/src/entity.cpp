#include <fstream>
#include <iostream>
#include <sdl/SDL.h>
#include <SDL_Main.h> 
#include <sdl/SDL_image.h>

#include "headers/Entity.h"

int getRES()
{
    int i = 0;
    int RES = 1;
    std::string line;
    std::ifstream set;
    set.open("user.settings");
    if (set.is_open())
    {
        while(getline(set, line))
        {
            i++;
            if (i = 1)
            {
                RES = std::stoi(line);
            } 
        }
        set.close();
    }
    
    else std::cout << "A beallítások fajl serult vagy nem letezik" << std::endl; 

    return RES;
}

Entity::Entity(V2F p_pos, SDL_Texture*  p_tex) : posi(p_pos), tex(p_tex)
{
    int resolution = getRES();
    
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 384 * resolution;
    currentFrame.h = 384 * resolution;
}

void Entity::setSize(int w, int h)
{
    int resolution = getRES();

    currentFrame.w = w * resolution;
    currentFrame.h = h * resolution;    
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}
