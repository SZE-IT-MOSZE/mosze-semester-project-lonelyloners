#include <iostream>
#include <string>
#include <vector>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>
#include <sdl/SDL_ttf.h>

class Plnt
{
public:
    Plnt(RenderWindow g, TTF_Font* f) : game(g), fnt(f) {};

    int menu();
    void prolog();
    void dessert1();
    void dessert2();
    void glacies();

private:
    RenderWindow game;
    TTF_Font* fnt;
};