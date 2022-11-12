#pragma once

#include <string>

#include "headers/Entity.h"

class Router {
    private:
        Entity p;

        void move(std::string cm, std::string it);
        void help();

    public:
        Router(Entity ent);
        void route(std::string command, std::string item);
};