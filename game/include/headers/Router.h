#pragma once

#include <string>

#include "headers/Entity.h"

class Router {
    private:
        void move(std::string cm, std::string it, Entity& ent);
        void help();
        void next_page(RenderWindow& rw);

    public:
        void route(std::string command, std::string item, Entity& ent);
};