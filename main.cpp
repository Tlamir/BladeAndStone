#include "raylib.h"
#include "raymath.h"

#include <string>

#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

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
    // Player Character
    Character playerCharacter(SCREEN_WIDTH, SCREEN_HEIGHT);
    // Prop
    Texture2D propTexture = LoadTexture("Assets/nature_tileset/Rock.png");
    Prop props[2]{
        Prop{Vector2{600.0f, 300.0f}, propTexture},
        Prop{Vector2{400.0f, 600.0f}, propTexture}};
    // Enemy
    Enemy goblin{
        Vector2{800.f, 300.f},
        LoadTexture("Assets/characters/goblin_idle_spritesheet.png"),
        LoadTexture("Assets/characters/goblin_run_spritesheet.png"),
    };
    Enemy slime{
        Vector2{500.f, 700.f},
        LoadTexture("Assets/characters/slime_idle_spritesheet.png"),
        LoadTexture("Assets/characters/slime_run_spritesheet.png"),
    };
    Enemy *enemies[2]{
        &goblin,
        &slime};
    for (auto &&enemy : enemies)
    {
        enemy->setTarget(&playerCharacter);
    }

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
            playerCharacter.getWorldPos().x - 4.0f < 0.f ||
            playerCharacter.getWorldPos().y < 0.f ||
            playerCharacter.getWorldPos().x + SCREEN_WIDTH + playerCharacter.getCharacterTextureSizex() > worldMap.width * MAP_SCALE ||
            playerCharacter.getWorldPos().y + SCREEN_HEIGHT + playerCharacter.getCharacterTextureSizey() + 10.f > worldMap.height * MAP_SCALE)
        {
            playerCharacter.undoMovement();
        }
        // Check prop collision
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.getCollisonRec(playerCharacter.getWorldPos()), playerCharacter.getCollisonRec()))
            {
                playerCharacter.undoMovement();
            }
        }
        // Draw the props
        for (Prop prop : props)
        {
            prop.Render(playerCharacter.getWorldPos());
        }
        if (!playerCharacter.getAlive()) // Character is dead
        {
            DrawText("Game Over!", 40.f, 40.f, 40, RED);
            EndDrawing();
            continue;
        }
        else // Character is alive
        {
            std::string playerHealth = "Health: ";
            playerHealth.append(std::to_string(playerCharacter.getHealth()), 0, 5);
            DrawText(playerHealth.c_str(), 40.f, 40.f, 40, RED);
        }

        for (auto &&enemy : enemies)
        {
            enemy->tick(GetFrameTime());
            // Set enemy target
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (CheckCollisionRecs(playerCharacter.getWeaponCollisionRec(), enemy->getCollisonRec()))
                {
                    enemy->setAlive(false);
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}