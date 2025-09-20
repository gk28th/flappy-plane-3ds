/*created by gk28th
  File Name: rectangle.h
  Purpose: Header file for rectangle.cpp
*/
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <citro2d.h> // include header files
#include <iostream>
#include "square.h"

inline int length = 50;     // defualt length of rectangle 
inline int thickness = 50;  // thickness of rectangle
inline int by = 0;          // defualt y coordinate of top left corner
inline int bx = 350;        // defualt x coordinate of top left corner
inline bool up = true;      // if the rectangle is coming up or down

void rectMove();    // function prototypes
void gameOver();
void resetRect();

#endif