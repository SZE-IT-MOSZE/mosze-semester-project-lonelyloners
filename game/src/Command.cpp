#include <iostream>

#include "headers/Command.h"

Command::Command(std::string cm) {
    this->input = cm;
}

bool Command::validate(std::string cm) {
    bool check[2] = {false, false};
    int space_pos = cm.find(" ", 0);
    std::string cma = cm.substr(0, space_pos);
    std::string it = cm.substr(space_pos+1, cm.length());

    for(auto i : this->commands) {
        if(i == cma) {
            check[0] = true;
            break;
        }
    }

    for(std::string i : this->items) {
        if(i == it) {
            check[1] = true;
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

void Command::make() {
    if(this->validate(this->input)) {
        int space_pos = this->input.find(" ", 0);
        this->command = this->input.substr(0, space_pos);
        this->item = this->input.substr(space_pos+1, this->input.length());
    }
    else {
        std::cout << "Hibas parancs" << std::endl;
    }
}

std::string Command::getCommand() const {
    return this->command;
}

std::string Command::getItem() const {
    return this->item;
}