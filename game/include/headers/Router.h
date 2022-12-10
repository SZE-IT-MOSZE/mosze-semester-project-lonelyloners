#pragma once

#include <string>

#include "headers/RenderWindow.h"

class Router {
    private:
        void move(std::string cm, std::string it, Entity& ent, Map& map);
        void help();
        void nextPage(RenderWindow& rw);
        void attack(Entity& e);

    public:
        void route(std::string command, std::string item, Entity& ent, RenderWindow& rw, Map& map);
};