#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "src/headers/Command.h"

//Ez semmi
std::vector<std::vector<int>> map_matrix;

void csv2vector(std::string path) {
    std::ifstream map_file(path);

    std::string temp_text;

    while (getline (map_file, temp_text)) {
            size_t last = 0;
            size_t next = 0;
            std::vector<int> temp_vector;

            while ((next = temp_text.find(";", last)) != std::string::npos) {
                std::string token = temp_text.substr(last, next-last);

                temp_vector.push_back(std::stoi(token));
        
                last = next + 1;
            }
            map_matrix.push_back(temp_vector);
    }

    for(auto i: map_matrix) {
        for (auto j: i) {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }

    map_file.close();
}
//idáig

int main() {
    //ez kell a game loop elé
    Command c = Command();

    //ez kell a game loopba a Router elé
    c.make("ELORE 5");
    //ez kell a Router után
    c.reset();
    return 0;
}