#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <sdl/SDL_ttf.h>

#include "headers/Entity.h"
/**
 * \brief A megjelenítésért felelős függvényeket tartalmazó osztály.
 *
 * Ebben az osztályban találhatók az Entityben létrehozott
 * elemek elhelyezéséér felelős függvények.
 * Továbbá a képernyőn megjelenő szöveg ebolvasásáért felelős
 * függvények.
 * 
 */

class RenderWindow
{
public:

    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePAth);
    
    int getRefreshRate();

    void cleanUp();
    void clear();
    void render(Entity& p_entity);
    bool update(Entity& p_entity, std::vector<std::pair<int, int>> spritepos, int frames, int w, int h, int offset, bool ff);
    void display();
    
    bool renderText(TTF_Font* Sans);

    void up(Entity& p_entity);        
    void down(Entity& p_entity);
    void left(Entity& p_entity);   
    void right(Entity& p_entity);   
    
    void renderInputText(std::string inputText, TTF_Font* Sans);
    void nextTxt(bool c);
    void nextPage() { pg++; };
    int getPage() { return pg; };
    void resetPage() { pg = 1; };

    int getRES();
    int getMap();
    void setMap(int i);
    void mapReset();
    void updateMap(Entity& p_entity, std::vector<std::pair<int, int>> spritepos);
    
    SDL_Renderer* getRenderer();
    SDL_Window* getWindow();

private:

    SDL_Window* window;
    SDL_Renderer* renderer;
    
    const char* p_title;
    std::string curr_txt;
    int p_w, p_h, pg, frms, map;
};
