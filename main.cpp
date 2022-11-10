#include <iostream>
#include <string>

#include "src/headers/Command.h"
#include "src/headers/Router.h"
#include "src/headers/Player.h"

int main() {
    Player p = Player();

    //Ez a sor kell a while ciklusok elé
    Router r = Router(p);

    while(true) {
        std::string command;
        getline(std::cin, command);

        //Ez a 3 sor kell az eventfigyelő ciklusba
        Command c = Command(command);
        c.make();
        r.route(c.getCommand(), c.getItem());

    }
}