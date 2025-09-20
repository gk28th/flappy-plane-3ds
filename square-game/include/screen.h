/*created by gk28th
  File Name: screen.h
  Purpose: Header file for screen.cpp
*/
#ifndef SCREEN_H 
#define SCREEN_H

#include <citro2d.h> // include header files
#include <iostream>
#include "square.h"
#include "rectangle.h"

inline C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT); // create screen to draw to
inline bool shouldExit = false; // determinse if start has been pressed 

void drawFrame(); // forward declarations 
void sceneInit();

#endif