// reading a text file

#pragma once

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sdl/SDL.h>
#include <sdl/SDL_image.h>

namespace settings
{
    int getRES()
    {
        int i = 0;
        int RES = 1;
        std::string line;
        std::ifstream set;
        set.open("user.settings");
        if (set.is_open())
        {
            while(getline(set, line))
            {
                i++;
                if (i = 1)
                {
                    RES = std::stoi(line);
                } 
            }
            set.close();
        }
      
        else std::cout << "A beallítások fajl serult vagy nem letezik" << std::endl; 

        return RES;
    }
}

