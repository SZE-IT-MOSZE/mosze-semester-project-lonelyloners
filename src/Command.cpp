#include <iostream>

#include "headers/Command.h"

Command::Command(std::string cm) {
    this->command = cm;
}

bool Command::validate(std::string cm) {
    return true;
}

void Command::make() {
    if(!this->validate(this->command)) {
        std::cout << "Hibás parancs";
    }
    else {
        std::cout << "Jó parancs";
    }
}