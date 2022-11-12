#include "headers/Player.h"
#include "headers/Router.h"

#include <iostream> //törölhető


void Router::route(std::string cm, std::string it, Entity& ent) {
    if(cm == "FEL" || cm == "LE" || cm == "JOBBRA" || cm == "BALRA" || cm == "ELORE" || cm == "HATRA") {
        this->move(cm, it, ent);
    }
    else if(cm == "HELP" || cm == "SEGITSEG") {
        this->help();
    }
}

void Router::help() {
    std::cout << "Engedelyezett parancsok:" << std::endl;
}

void Router::move(std::string cm, std::string it, Entity& ent) {
    int dist = std::stoi(it);

    if(cm == "FEL" || cm == "ELORE") {
        ent.setTarget(1, dist);
    }
    else if(cm == "JOBBRA") {
        ent.setTarget(2, dist);
    }
    else if(cm == "LE" || cm == "HATRA") {
        ent.setTarget(3, dist);
    }
    else if(cm == "BALRA") {
        ent.setTarget(4, dist);
    }
}
