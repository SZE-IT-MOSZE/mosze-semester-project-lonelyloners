#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "headers/Map.h"

Map::Map(std::string pth, Entity ent) : map(pth), e(ent)
{
	csv2vector();
}

void Map::csv2vector() {
    std::ifstream map_file(this->map);

    std::string temp_text;

    while (getline(map_file, temp_text)) {
      
        size_t last = 0;
        size_t next = 0;
        std::vector<int> temp_vector;

        while ((next = temp_text.find(";", last)) != std::string::npos) {
          std::string token = temp_text.substr(last, next - last);

          temp_vector.push_back(std::stoi(token));

          last = next + 1;
        }
        this->map_matrix.push_back(temp_vector);
    }

    map_file.close();
}

bool Map::matrix_pos(int dir, int dist) {
    int x  = e.getPos().getX();
    x = static_cast<int>(x) / 32 + 1;

	std::cout << " x " << x << std::endl;

    int y  = e.getPos().getY();
    y = static_cast<int>(y) / 32 + 1;
  
	std::cout << " y " << y << std::endl;


    while (y >= 0 && x >= 0 && y < 12 && x < 12 && dist > 0) {
        if (this->map_matrix[y][x] == 0) {
          return false;
        } else if (dir == 1) {
          y--;
        } else if (dir == 2) {
          x++;
        } else if (dir == 3) {
          y++;
        } else if (dir == 4) {
          x--;
        }
        dist--;
    }

    if (dist > 0) {
      return false;
    }
    return true;
}