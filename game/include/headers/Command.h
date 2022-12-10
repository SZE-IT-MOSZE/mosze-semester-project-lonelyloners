#pragma once

#include <string>
#include <vector>

#include "headers/RenderWindow.h"

class Command {
    private:
        std::vector<std::string> commands;
        std::vector<bool> has_items;
        std::vector<std::vector<std::string>> items;
        std::string command;
        std::string item;

        void parse();
        std::string to_upper(std::string str);
        bool check_command(std::string cm);
        int get_command_id(std::string cm);
        bool check_item(std::string it, int item_id);
        bool check_input(std::string input);
        void setCommand(std::string cm);
    
    public:
        Command();
        void make(std::string input, TTF_Font* fnt, RenderWindow w);
        std::string getCommand();
        std::string getItem();
        void reset();
};