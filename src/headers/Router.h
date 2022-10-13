#include <string>

#include "Player.h"

class Router {
    private:
        Player p;

        void move(std::string cm, std::string it);

    public:
        Router(Player p);
        void route(std::string command, std::string item);
};