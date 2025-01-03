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

    Texture2D knight = LoadTexture("Assets/characters/knight_idle_spritesheet.png");
    Vector2 knightPosition = {
        (float)SCREEN_WIDTH/2.0f-4.0f*(0.5f*(float)knight.width/6.0f),
        (float)SCREEN_HEIGHT/2.0f-4.0f*(0.5f*(float)knight.height)
     };
  
   
    
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
        }
        
      
        
        
        DrawTextureEx(worldMap, mapPosition, 0, 1, WHITE);
        
        Rectangle source {0.f,0.f,(float)knight.width/6.0f,(float)knight.height};
        Rectangle dest{knightPosition.x,knightPosition.y,4.0f*(float)knight.width/6.0f,4.0f*(float)knight.height};
        DrawTexturePro(knight,source,dest,Vector2{},0.f,WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}