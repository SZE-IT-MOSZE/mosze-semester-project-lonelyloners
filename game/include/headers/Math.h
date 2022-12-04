#pragma once

#include <iostream>

class V2F
{
public:
    
    V2F() : x(0.0f), y(0.0f)
    {

    }
    
    V2F(float vx, float vy) : x(vx), y(vy)
    {

    }

    /**
    * \brief Kiírja az adott elem koordinátáit.
    *
    * Egy betöltött kép pozícióját kaphatjuk meg vele.
    * 
    */
    void print()
    {
        std::cout << "V2F (x, y): " << x << ", " << y << std::endl;
    }
    /**
    * \brief Visszaadja az X koordinátát.
    *
    * Egy betöltött kép X koordinátáját kaphatjuk meg vele.
    * 
    * \return X koordináta.
    */
    float getX()
    {
        return x;
    }
    /**
    * \brief Visszaadja az Y koordinátát.
    *
    * Egy betöltött kép Y koordinátáját kaphatjuk meg vele.
    * 
    * \return Y koordináta.
    */
    float getY()
    {
        return y;
    }

    float x, y;

private:
};