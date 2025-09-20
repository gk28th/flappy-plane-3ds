/*created by gk28th
  File Name: square.h
  Purpose: Header file for square.cpp
*/
#ifndef SQUARE_H
#define SQUARE_H

#include <citro2d.h> // include header fiels
#include <screen.h>
#include <iostream>

inline int sqrSize = 50; // height and width of square
inline int sqrX;         // x cordinate for top left corner
inline int sqrY;         // y cordinate for top left corner

void moveSquare();  // forward declaretions 
void resetSquare();

#endif