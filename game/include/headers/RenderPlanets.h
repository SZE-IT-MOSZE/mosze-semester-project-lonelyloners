#pragma once

#include <vector>
#include <stdio.h>

#include "headers/RenderWindow.h"
#include "headers/Entity.h"
#include "headers/Utils.h"


void renderPlanet(RenderWindow planet, std::vector<Entity> &entitii, Entity lirs)  
{
    for(Entity& ent : entitii)
    {      
        planet.render(ent); 
    }

    lirs.setSize(32,32); 
    planet.render(lirs);

    planet.display();

}
