#include "raylib.h"

#define SCREEN_WIDTH 384
#define SCREEN_HEIGHT 384
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Blade & Stone");
    const float playerSpeed = 2.0f;
    SetTargetFPS(60); 
    //World map texture
    Texture2D worldMap = LoadTexture("Assets/WorldMap.png");
    Vector2 mapPosition = {0.0f, 0.0f};
   
    
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (IsKeyDown(KEY_D))  mapPosition.x -= playerSpeed;
        else if (IsKeyDown(KEY_A)) mapPosition.x += playerSpeed;
        else if (IsKeyDown(KEY_W)) mapPosition.y += playerSpeed;
        else if (IsKeyDown(KEY_S))  mapPosition.y -= playerSpeed;
      
        
        
        DrawTextureEx(worldMap, mapPosition, 0, 0.651f, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}