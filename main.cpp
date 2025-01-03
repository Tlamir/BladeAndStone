#include "raylib.h"
#include "raymath.h"

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 768
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Blade & Stone");
    const float playerSpeed = 3.0f;
    SetTargetFPS(60); 

    //World map texture
    Texture2D worldMap = LoadTexture("Assets/WorldMap.png");
    Vector2 mapPosition = {0.0f, 0.0f};

    // Knight textures
    Texture2D knight_idle = LoadTexture("Assets/characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("Assets/characters/knight_run_spritesheet.png");


    Texture2D knight = LoadTexture("Assets/characters/knight_idle_spritesheet.png");
    Vector2 knightPosition = {
        (float)SCREEN_WIDTH/2.0f-4.0f*(0.5f*(float)knight.width/6.0f),
        (float)SCREEN_HEIGHT/2.0f-4.0f*(0.5f*(float)knight.height)
     };
     // 1 facing right, -1 facing left 
     float rightLeft=1.0f;

     // Animation variables
     float runningTime{};
     int frame{};
     const int maxFrames{6};
     const float updateTime{1.0f/12.0f};
   
    
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Vector2 direction{};
        if (IsKeyDown(KEY_A))  direction.x -= 1.0f;
        if (IsKeyDown(KEY_D)) direction.x += 1.0f;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0f;
        if (IsKeyDown(KEY_S))  direction.y += 1.0f;
        if (Vector2Length(direction)!=0.0)
        {   
            
            mapPosition = Vector2Subtract(mapPosition,Vector2Scale(Vector2Normalize(direction),playerSpeed));
            direction.x<0.f ? rightLeft=-1.0f : rightLeft=1.0f;
            knight=knight_run;
         
        }
        else knight = knight_idle;
      
        
        // Draw the map
        DrawTextureEx(worldMap, mapPosition, 0, 1, WHITE);
        
        // Update animation frame
        
        runningTime += GetFrameTime();
        if (runningTime>=updateTime)
        {
            frame++;
            runningTime=0.f;
            if (frame>maxFrames) frame=0;
            
            
        }
        
        
        
        Rectangle source {(float)knight.width/6.0f*frame,0.f,rightLeft*(float)knight.width/6.0f,(float)knight.height};
        Rectangle dest{knightPosition.x,knightPosition.y,4.0f*(float)knight.width/6.0f,4.0f*(float)knight.height};
        DrawTexturePro(knight,source,dest,Vector2{},0.f,WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}