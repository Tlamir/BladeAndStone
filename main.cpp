#include "raylib.h"
#include "raymath.h"

#include "Character.h"

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 768
#define MAP_SCALE 2.0f

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Blade & Stone");

    SetTargetFPS(60);

    // World map texture
    Texture2D worldMap = LoadTexture("Assets/WorldMap2.png");
    Vector2 mapPosition = {0.0f, 0.0f};

    Character playerCharacter;
    playerCharacter.setScreenPos(SCREEN_WIDTH, SCREEN_HEIGHT);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        mapPosition = Vector2Scale(playerCharacter.getWorldPos(), -1.f);
        //  Draw the map
        DrawTextureEx(worldMap, mapPosition, 0, MAP_SCALE, WHITE);

        playerCharacter.tick(GetFrameTime());
        // Out of Bounds check
        if (
            playerCharacter.getWorldPos().x < 0.f ||
            playerCharacter.getWorldPos().y < 0.f ||
            playerCharacter.getWorldPos().x + SCREEN_WIDTH > worldMap.width * MAP_SCALE ||
            playerCharacter.getWorldPos().y + SCREEN_HEIGHT > worldMap.height * MAP_SCALE)
        {
            playerCharacter.undoMovement();
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}