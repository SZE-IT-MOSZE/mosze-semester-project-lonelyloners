
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
 
void Router::route(std::string cm, std::string it, Entity& ent, RenderWindow& rw, Map& map, TTF_Font* fnt, Plnt& p) {
    std::cout << "cm " << cm << " it " << it << std::endl;

    if(cm == "FEL" || cm == "LE" || cm == "JOBBRA" || cm == "BALRA" || cm == "ELORE" || cm == "HATRA") {
       this->move(cm, it, ent, rw, map, fnt);
    }
    else if(cm == "HELP" || cm == "SEGITSEG") {
       this->help();
    }
    else if(cm == "LAPOZ" || cm == "LAPOZZ") {
        this->nextPage(rw);
    }
    else if(cm == "TAMADAS") {
        this->attack(ent);
    }
    else if(cm == "BELEP") {
        this->ent(p);
    }
    else if(cm == "BESZEL") {
        this->speak(p);
    }
    else if(cm == "DONT") {
        
        if (it == " A")
        {
            p.sA();
        }
        if (it == " B")
        {
            p.sB();
        }
    }
    else if(cm == "FELVESZ") {
        p.pUp();
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
void Router::move(std::string cm, std::string it, Entity& ent, RenderWindow& rw, Map& map, TTF_Font* fnt) {
    int dist = std::stoi(it);

    if(cm == "FEL" || cm == "ELORE") {
        if(map.matrix_pos(1, dist)) {
            ent.setTarget(1, dist);
        }
        else {
            rw.renderInfoText("Ide nem léphetsz", fnt);
        }
    }
    else if(cm == "JOBBRA") {
        
        if(map.matrix_pos(2, dist)) {
            ent.setTarget(2, dist);
        }
        else {
            rw.renderInfoText("Ide nem léphetsz", fnt);
        }
    }
    else if(cm == "LE" || cm == "HATRA") {
        if(map.matrix_pos(3, dist)) {
            ent.setTarget(3, dist);
        }
        else {
            rw.renderInfoText("Ide nem léphetsz", fnt);
        }
    }
    else if(cm == "BALRA") {
        if(map.matrix_pos(4, dist)) {
            ent.setTarget(4, dist);
        }
        else {
            rw.renderInfoText("Ide nem léphetsz", fnt);
        }
    }
}

void Router::nextPage(RenderWindow& rw) {
    rw.nextPage();
}

void Router::attack(Entity& e) {
    e.setAttack(true);
}

void Router::ent(Plnt& e) {
    e.enter();
}

void Router::speak(Plnt& e) {
    e.talk();
}
