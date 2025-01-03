#include "raylib.h"

#define SCREEN_WIDTH 384
#define SCREEN_HEIGHT 384
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Blade & Stone");

    SetTargetFPS(60); 
    //World map texture
    Texture2D worldMap = LoadTexture("Assets/WorldMap.png");
    Vector2 mapPosition = {0.0f, 0.0f};
   
    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureEx(worldMap, mapPosition, 0, 0.651f, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}