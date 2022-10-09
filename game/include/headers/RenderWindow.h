#pragma once

#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include "headers/Entity.h"

class RenderWindow
{
    public:

        RenderWindow(const char* p_title, int p_w, int p_h);
        SDL_Texture* loadTexture(const char* p_filePAth);
        
        int getRefreshRate();

        void cleanUp();
        void clear();
        void render(Entity& p_entity);
        void display();
   
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};
