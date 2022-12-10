#include "headers/Player.h"
#include "headers/Router.h"

#include <iostream> //törölhető

/**
 * \brief Parancsot végrehajtó függvény meghívása.
 * 
 * A parancs alapján meghívja a parancsnak megfelelő függvényt a megfelelő paraméterekkel.
 * 
 * \param cm A parancs szövegkódja.
 * \param it A tárgy szövegkódja.
 * \param ent Egy Entity objektum, amelyet a mozgás parancsok használnak.
 * \param rw Egy RenderWindow objektum, amely a kiíró parancsok használatához kell.
 */

void Router::route(std::string cm, std::string it, Entity& ent, Map& map) {
    if(cm == "FEL" || cm == "LE" || cm == "JOBBRA" || cm == "BALRA" || cm == "ELORE" || cm == "HATRA") {
        this->move(cm, it, ent, map);
    }
    else if(cm == "HELP" || cm == "SEGITSEG") {
        this->help();
    }
}
/**
 * \brief Segítség kiírása.
 * 
 * Kiírja az engedélyezett parancsok listáját.
 * 
 */
void Router::help() {
    std::cout << "Engedelyezett parancsok:" << std::endl;
}
/**
 * \brief Játékos mozgatását végzi.
 * 
 * A játékost mozgató parancsok alapján átad két paramétert egy entitás objektumnak, amely azt a pozíciót határozza meg, ahova a játékos lépni szeretne.
 * 
 * \param cm A parancs szövegkódja.
 * \param it A tárgy szövegkódja.
 * \param ent Egy Entity objektum, amelyet a mozgás parancsok használnak.
 */
void Router::move(std::string cm, std::string it, Entity& ent, Map& map) {
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