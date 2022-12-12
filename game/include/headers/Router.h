#pragma once

#include <string>

#include "headers/RenderWindow.h"
#include "headers/Map.h"
#include "headers/Plnt.h"

class Router {
    private:
        void move(std::string cm, std::string it, Entity& ent, RenderWindow& rw, Map& map,  TTF_Font* fnt);
        void help();
        void nextPage(RenderWindow& rw);
        void attack(Entity& e);
        void ent(Plnt& e);
        void speak(Plnt& e);

    public:
        void route(std::string cm, std::string it, Entity& ent, RenderWindow& rw, Map& map,  TTF_Font* fnt, Plnt& p);
};