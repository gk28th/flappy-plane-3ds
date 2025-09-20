/*created by gk28th
  File Name: main.cpp
  Purpose: Main entry point
*/
#include <iostream>
#include <citro2d.h> 
#include "square.h"
#include "rectangle.h"
#include "screen.h"

int main() 
{
	sceneInit(); // run one time. init everything. screen.cpp
	
	while (aptMainLoop())	  // main loop of game.
	{
		moveSquare();		  // moves the square. square.cpp
		drawFrame();		  // draws each frame. screen.cpp
		gameOver();			  // checks for game over. rectangle.cpp
		rectMove();			  // moves the rectangles. rectangle.cpp
		if(shouldExit) break; // break the loop if start is pressed. square.cpp
	}

	C2D_Fini();	// de-init libraries once loop is broken
	C3D_Fini();
	gfxExit();
	return 0;
}
