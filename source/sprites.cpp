#include <citro2d.h>



namespace sprites{
    
    C2D_SpriteSheet spriteSheet;
    C2D_Sprite planeSprite; 
    C2D_Sprite towerSprite[6];
    C2D_Sprite bgSprite[2];

    constexpr int towerWidth{47};
    constexpr int towerHeight{240};
    constexpr int planeWidth{47};
    constexpr int planeHeight{240};

    void initSpriteSheet()
    {   
        spriteSheet = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");
        if (!spriteSheet) svcBreak(USERBREAK_PANIC);
    }
        
    void initSprites()
    {
        // set up plane sprite
        C2D_SpriteFromSheet(&planeSprite, spriteSheet, 0);  
        C2D_SpriteSetCenter(&planeSprite, 0.0f, 0.0f);
        C2D_SpriteSetPos(&planeSprite, 100, 50); 
        //set up background
        C2D_SpriteFromSheet(&bgSprite[0], spriteSheet, 2);  
        C2D_SpriteSetCenter(&bgSprite[0], 0.0f, 0.0f);
        C2D_SpriteSetPos(&bgSprite[0], 0, 0);
        C2D_SpriteFromSheet(&bgSprite[1], spriteSheet, 2);  
        C2D_SpriteSetCenter(&bgSprite[1], 0.0f, 0.0f);
        C2D_SpriteSetPos(&bgSprite[1], 612, 0);
        //set up tower
        for(int i = 0; i < 6; i++)
        {
            C2D_SpriteFromSheet(&towerSprite[i], spriteSheet, 1);  
            C2D_SpriteSetCenter(&towerSprite[i], 0.0f, 0.0f);
            
            if(i % 2 == 0)  // even number tower in array is the top tower
            {
            C2D_SpriteSetPos(&towerSprite[i], 401, 0);
            C2D_SpriteScale(&towerSprite[i], 1, -1);
            }

            else C2D_SpriteSetPos(&towerSprite[i], 401, 240);
                
        }
    }

    void drawSprites()
    {
		C2D_DrawSprite(&bgSprite[0]);
        C2D_DrawSprite(&bgSprite[1]);
        for(int i = 0; i < 6; i++) C2D_DrawSprite(&towerSprite[i]);
        C2D_DrawSprite(&planeSprite);
    }

    void scrollBg()
    {
        if(sprites::bgSprite[0].params.pos.x <= -612) sprites::bgSprite[0].params.pos.x = 612;
        if (sprites::bgSprite[1].params.pos.x <= -612) sprites::bgSprite[1].params.pos.x = 612;
        
        sprites::bgSprite[0].params.pos.x -= 1;
        sprites::bgSprite[1].params.pos.x -= 1;
    }

}