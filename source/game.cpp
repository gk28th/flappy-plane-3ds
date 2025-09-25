#include "sprites.h"

bool planeTowerCollision()
{
   for(int i = 0; i < 6; i++)
   {
     if(((sprites::towerSprite[i].params.pos.x <= sprites::planeSprite.params.pos.x+sprites::planeWidth) && (sprites::towerSprite[i].params.pos.x+sprites::towerWidth >= sprites::planeSprite.params.pos.x)) && ((sprites::towerSprite[i].params.pos.y <= sprites::planeSprite.params.pos.y) && (sprites::towerSprite[i].params.pos.y+sprites::towerHeight >= sprites::planeSprite.params.pos.y)))
      if(sprites::towerSprite[i].params.pos.x )    
         return true;
   }
    return false;
}