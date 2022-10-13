#include "headers/Player.h"
#include "headers/Router.h"

#include <iostream> //törölhető

Router::Router(Player p) {
    this->p = p;
}

void Router::route(std::string cm, std::string it) {
    if(cm == "FEL" || cm == "LE" || cm == "JOBBRA" || cm == "BALRA") {
        this->move(cm, it);
    }
}

void Router::move(std::string cm, std::string it) {
    /*
    if(cm == "FEL" || cm == "ELORE") {
        
    }*/
    std::cout << cm + " " + "mentem " + it + "-et" << std::endl;
}