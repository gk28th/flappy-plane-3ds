/*created by gk28th
  File Name: screen.cpp
  Purpose: Init graphics and draw frames
*/
#include "screen.h"

void sceneInit() // init everything, called once
{
    gfxInitDefault()                   // init graphics lib with defualt arguments
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE); // init citro3d 
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS); // init citro3d
	C2D_Prepare();					   // prepare citro2d  
	srand(time(NULL));				   // for random height of rectangles
}
void drawFrame() // runs every loop
{
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW); 			   // start frame citro3d
	C2D_TargetClear(top, C2D_Color32(0, 0, 255, 255)); // clear the screen with a colour
	C2D_SceneBegin(top); 							   // start the scene
	C2D_DrawRectSolid(sqrX, sqrY, 0, sqrSize, sqrSize, C2D_Color32(255, 0, 0, 255)); // draw square
	C2D_DrawRectSolid(bx, by, 0, thickness, length, C2D_Color32(255, 0, 0, 255));    // draw rectangle
	C3D_FrameEnd(0); // end the frame
}