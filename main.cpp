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
        EndDrawing();
    }

    CloseWindow();

    return 0;
}