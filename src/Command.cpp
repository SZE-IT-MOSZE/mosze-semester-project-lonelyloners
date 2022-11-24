#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "headers/Command.h"

Command::Command() {
    this->parse();
}

void Command::parse() {
    std::string plain_text;

    std::ifstream command_file("commands.csv");

    while (getline (command_file, plain_text)) {
            size_t last = 0;
            size_t next = 0;
            int no = 0;
            std::vector<std::string> item;

            while ((next = plain_text.find(";", last)) != std::string::npos) {
                std::string token = plain_text.substr(last, next-last);

                if(no == 0) {
                    this->commands.push_back(token);
                }
                else if(no == 1) {
                    this->has_items.push_back(std::stoi(token));
                }
                else {
                    item.push_back(token);
                }
                last = next + 1;
                no++;
            }
        this->items.push_back(item);
    }
    command_file.close();
}

std::string Command::to_upper(std::string str) {
    std::string temp_str = "";

    for(char c: str) {
        temp_str += toupper(c);
    }

    return temp_str;
}

bool Command::check_command(std::string cm) {
    for(std::string str: this->commands) {
        if(str == cm) {
            return true;
        }
    }
    return false;
}

int Command::get_command_id(std::string cm) {
    int id = 0;
    for(std::string str: this->commands) {
        if(str == cm) {
            return id;
        }
        id++;
    }
    return -1;
}

bool Command::check_item(std::string it, int item_id) {
    if(!this->has_items[item_id]) {
        return false;
    }
    else {
        for(std::string str: this->items[item_id]) {
            if(str == it) {
                return true;
            }
        }
    }
    return false;
}

bool Command::check_input(std::string input) {
    input = to_upper(input);
    input += " ";

    size_t last = 0;
    size_t next = 0;
    int no = 0;

    std::string command;

    while ((next = input.find(" ", last)) != std::string::npos) {
        std::string token = input.substr(last, next-last);

        if(no == 0) {
            command = token;
        }

        if(no == 0 && !check_command(token)) {
            return false;
        }
        
        else if(no == 1 && !check_item(token, get_command_id(command))) {
            return false;
        }

        last = next + 1;
        no++;
    }
        
    return true;
}

void Command::setCommand(std::string cm) {
    if(cm.find(" ") != std::string::npos) {
        this->command = cm.substr(0, cm.find(" "));
        this->item = cm.substr(cm.find(" "), cm.length());
    }
    else {
        this->command = cm;
        this->item = " ";
    }
}

void Command::make(std::string input) {
    if(this->check_input(input)) {
        std::cout << "Jó parancs" << std::endl;
    }
    else {
        std::cout << "Hibás parancs";
    }
}

std::string Command::getCommand() {
    return this->command;
}

std::string Command::getItem() {
    return this->item;
}

void Command::reset() {
    this->command = " ";
    this->item = " ";
}