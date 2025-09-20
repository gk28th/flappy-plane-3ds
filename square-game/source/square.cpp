/*created by gk28th
  File Name: square.cpp
  Purpose: Manages square and exit variable
*/
#include "square.h" 

void resetSquare() // reset the square 
{ 
	sqrX = 0; // defualt x coordinate for top left corner
	sqrY = 0; // defualt y coordinate for top left corner
}

void moveSquare()
{
	hidScanInput();	// scan for input
	u32 kHeld = hidKeysHeld(); // store the keys that have been pressed in vairable
	if((kHeld & KEY_DUP) && (sqrY != 0)) sqrY -= 2;      // if up is pressed, move square up by 2 pixles 
	if((kHeld & KEY_DDOWN) && (sqrY != 190)) sqrY += 2;  // if down is pressed, move square down by 2 pixles
	if((kHeld & KEY_DLEFT) && (sqrX != 0)) sqrX -= 2;    // if left is pressed, move square left by 2 pixles
	if((kHeld & KEY_DRIGHT) && (sqrX != 350)) sqrX += 2; // if right is pressed, move square right by 2 pixles
	if(kHeld & KEY_START) shouldExit = true;			 // if start is pressed set should exit to true
}