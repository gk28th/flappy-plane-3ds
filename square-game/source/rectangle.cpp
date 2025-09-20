/*created by gk28th
  File Name: rectangle.cpp
  Purpose: Manages rectangle
*/
#include "rectangle.h"

void resetRect() // reset the rectangle to defualt state
{
	bx = 350;    // top left x cordinate of rectangle
	by = 0;		 // top left y cordinate of rectangle
	length = 50; // length of rectangle
	up = true;   // rectangle spawns up
}
void gameOver() // checks if you hace touched the rectangle. comments wont help lol
{
	if((sqrX+sqrSize >= bx && sqrX+sqrSize <= bx+thickness) || sqrX == bx+thickness) // figure it out
	{	
		if(up && (sqrY <= length)) // if the rect spawns up and square y cordinate is <= to rect length
		{
			sleep(1);      // freeze the screen for one second
			resetRect();   // reset rectangle to defualt state
			resetSquare(); // reset square to defualt state
		} 
		if(!up && (sqrY+sqrSize>=240-length)) // if the rect spawns down and right edge of square is <= to rect 240 - length
		{
			sleep(1);      // freeze the screen for one second
			resetRect();   // reset rectangle to defualt state
			resetSquare(); // reset square to defualt state
    	}	
	}	
}
void rectMove() // moves the rectangle
{
	if(!(bx <= 0-thickness))  // if the rectangle is not of screen
	{	
		bx=bx-4;
	}		
	else  // if it is
	{
		bx = 400 - thickness; 		// teleport rectangle here 
		length = rand() % 120 + 50; // set length to be random
		if (!up) by = 0;            // is the rectangle is up, set y cordinate = 0
		if (up) by = 240 - length;  // if it is down set y cordinate minus the random length
		up = !up;                 	// flip up to oposite
	}
}