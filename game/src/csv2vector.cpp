#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "headers/csv2vector.h"

CSV2Vector::CSV2Vector(std::string path) {
    this->path = path;
}

void CSV2Vector::convert() {
    std::string text;

    std::ifstream f(this->path);

    while (getline (f, text)) {
        std::cout << text;
    }
}