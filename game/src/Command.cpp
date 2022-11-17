#include <iostream>

#include "headers/Command.h"

/**
 * \brief Barancs beolvasása.
 * 
 * Beolvassa a parancsot egy string típusként és eltárolja a későbbi feldolgozáshoz.
 * 
 * \param cm parancs szövege.
 * 
 */

Command::Command(std::string cm) {
    this->input = cm;
}

/**
 * \brief Parancs helyességének ellenőrzése.
 * 
 * Ellenőrzi, hogy a parancs helyességét. Ha a parancshoz item is tartozik, annak a helyességét is ellenőrzi.
 * 
 * \param cm a parancs szövege.
 * \return A beírt parancs szintaktikailag helyes-e vagy sem.
 */

bool Command::validate(std::string cm) {
    bool check[2] = {false, false};
    int space_pos = cm.find(" ", 0);
    std::string cma;

    if(space_pos != std::string::npos) {
        std::string cma = cm.substr(0, space_pos);
        std::string it = cm.substr(space_pos+1, cm.length());

        for(std::string i : this->items) {
            if(i == it) {
                check[1] = true;
                break;
            }
        }
    }
    else {
        cma = cm;
        check[1] == true;
    }

    for(auto i : this->commands) {
        if(i == cma) {
            check[0] = true;
            break;
        }
    }

    if(check[0] && check[1]) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * \brief Parancs mentése.
 * 
 * A beírt parancsot ellenőrzés után két részletben eltárolja. A két részlet a command és az item.
 */

void Command::make() {
    if(this->validate(this->input)) {
        int space_pos = this->input.find(" ", 0);
        if(space_pos != std::string::npos) {
            this->command = this->input.substr(0, space_pos);
            this->item = this->input.substr(space_pos+1, this->input.length());
        }
        else {
            this->command = this->input;
            this->item = " ";
        }
    }
    else {
        std::cout << "Hibas parancs" << std::endl;
    }
}

/**
 * \brief Parancs visszaadása.
 * \return Parancs string.
 */

std::string Command::getCommand() const {
    return this->command;
}

/**
 * \brief Tárgy visszaadása.
 * \return Tárgy string.
 */

std::string Command::getItem() const {
    return this->item;
}