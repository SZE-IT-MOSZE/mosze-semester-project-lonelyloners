#pragma once

#include <string>
#include <vector>

#include "Entity.h"

class Map {
private:
  std::vector<std::vector<int>> map_matrix;
  std::string map;
  Entity e;

public:
  Map(std::string pth, Entity ent);
  void csv2vector();
  bool matrix_pos(int dir, int dist);
};