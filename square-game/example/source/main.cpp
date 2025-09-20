#include <citro2d.h>

int main() 
{
	gfxInitDefault();					// init graphics with defulat arguments 
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);  // init citro 3d
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);  // init citro 2d
	C2D_Prepare();						// prepare citro 2d
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT); // create screen to draw to

	while (aptMainLoop()) // main loop
	{
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW); 				// citro 3d begin the frame
		C2D_TargetClear(top, C2D_Color32(0, 0, 255, 255));	// fill the top screen with colour blue
		C2D_SceneBegin(top);								// start the scene
		C2D_DrawRectSolid(175, 95, 0, 50, 50, C2D_Color32(255, 0, 0, 255)); // draw square to center
		C3D_FrameEnd(0); // end the frame
	}
	
	C2D_Fini(); // de init libaries
	C3D_Fini();
	gfxExit();
	return 0;
}