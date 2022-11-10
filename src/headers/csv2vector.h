#pragma once

#include <string>
#include <vector>

class CSV2Vector {
    private:
        std::string path;
        std::vector<std::vector<int>> v;

    public:
        CSV2Vector(std::string path);
        void convert();
        std::vector<std::vector<int>> getVector();
};