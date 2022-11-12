#include "headers/Player.h"
#include "headers/Router.h"

#include <iostream> //törölhető

Router::Router(Entity& ent) : p(ent)  
{
}

void Router::route(std::string cm, std::string it) {
    if(cm == "FEL" || cm == "LE" || cm == "JOBBRA" || cm == "BALRA" || cm == "ELORE" || cm == "HATRA") {
        this->move(cm, it);
    }
    else if(cm == "HELP" || cm == "SEGITSEG") {
        this->help();
    }
}

void Router::help() {
    std::cout << "Engedelyezett parancsok:" << std::endl;
}

void Router::move(std::string cm, std::string it) {
    int dist = std::stoi(it);

    if(cm == "FEL" || cm == "ELORE") {
        p.setTarget(1, dist);
    }
    else if(cm == "JOBBRA") {
        p.setTarget(2, dist);
    }
    else if(cm == "LE" || cm == "HATRA") {
        p.setTarget(3, dist);
    }
    else if(cm == "BALRA") {
        p.setTarget(4, dist);
    }
}
