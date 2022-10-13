#include <iostream>
#include <string>

#include "src/headers/Command.h"
#include "src/headers/Router.h"
#include "src/headers/Player.h"

int main() {
    std::string input;

    getline(std::cin, input);

    Player p;
    Router rt(p);

    if(input != "q") {
        Command cm(input);
        cm.make();
        rt.route(cm.getCommand(), cm.getItem());
    }

    return 0;
}