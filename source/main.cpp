#include <citro2d.h>
//#include <iostream>
#include "sprites.h"
#include "plane.h"
#include "tower.h"
#include "game.h"

int main() 
{
	romfsInit();
	gfxInitDefault();
	consoleInit(GFX_BOTTOM, NULL);
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

	sprites::initSpriteSheet();
	sprites::initSprites();
	
	Plane plane {&sprites::planeSprite};
	Tower towers[3] {{&sprites::towerSprite[0], &sprites::towerSprite[1], 0}, {&sprites::towerSprite[2], &sprites::towerSprite[3], sprites::towerWidth+133}, {&sprites::towerSprite[4], &sprites::towerSprite[5], sprites::towerWidth+133+sprites::towerWidth+133}};
	for(int i = 0; i < 3; i++) towers[i].generateTower();

			
	while (aptMainLoop())
	{
		//if(planeTowerCollision()) std::cout << "Crashed\n";

		plane.planeJump();
		for(int i = 0; i < 3; i++) 
		{
			towers[i].generateTower();
			towers[i].moveTower();
		}
			
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, C2D_Color32f(1.0f, 0.0f, 0.0f, 1.0f));
		C2D_SceneBegin(top);
		
		sprites::scrollBg();
		sprites::drawSprites();	

		C2D_DrawRectSolid(0, 220, 0, 400, 20, C2D_Color32f(0.0f, 255.0f, 0.0f, 255.0f));
		C3D_FrameEnd(0);
	}

	C2D_SpriteSheetFree(sprites::spriteSheet);

	C2D_Fini();
	C3D_Fini();
	gfxExit();
	romfsExit();
	return 0;
}
