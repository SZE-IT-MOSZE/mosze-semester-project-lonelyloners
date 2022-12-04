//
// pch.h
//
#pragma once
#include <iostream>
#include <string>
#include <vector> 
#include "../game/include/sdl/SDL_ttf.h"
#include "../game/include/sdl/SDL.h"
#include "../game/include/sdl/SDL_image.h"
#include "../game/include/headers/Command.h"
#include "../game/include/headers/Entity.h"
#include "../game/include/headers/Player.h"
#include "../game/include/headers/Router.h"
#define big 10
int ize(int a, int b, bool d);
bool ize2(int a, int b, bool** c, bool d);
bool ize3(int a, int aa, int b, int bb, bool** c, bool d);
bool V2F_EQ(V2F* a, V2F* b);
V2F V2Fadd(float a, float b, float c, float d);
V2F V2Fadd2(V2F* a, V2F* b);


