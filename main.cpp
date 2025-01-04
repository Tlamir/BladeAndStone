#include "raylib.h"
#include "raymath.h"

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 768
class Character
{
public:
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPos(int winWith, int winHeight);
    void tick(float detltaTime);

private:
    Texture2D texture{LoadTexture("Assets/characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("Assets/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("Assets/characters/knight_run_spritesheet.png")};
    Vector2 screenPos;
    Vector2 worldPos;
    // 1 facing right, -1 facing left
    float rightLeft = 1.0f;
    // Animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.0f / 12.0f};
    const float speed{4.f};
};

void Character::setScreenPos(int winWith, int winHeight)
{
    screenPos = {
        (float)winWith / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
        (float)winHeight / 2.0f - 4.0f * (0.5f * (float)texture.height)};
}
void Character::tick(float detltaTime)
{
    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0f;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0f;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0f;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0f;
    if (Vector2Length(direction) != 0.0)
    {
        // Set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.f ? rightLeft = -1.0f : rightLeft = 1.0f;
        texture = run;
    }
    else
        texture = idle;

    // Update animation frame

    runningTime += detltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Blade & Stone");
    const float playerSpeed = 3.0f;
    SetTargetFPS(60);

    // World map texture
    Texture2D worldMap = LoadTexture("Assets/WorldMap2.png");
    Vector2 mapPosition = {0.0f, 0.0f};

    // Knight textures
    Texture2D knight_idle = LoadTexture("Assets/characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("Assets/characters/knight_run_spritesheet.png");

    Texture2D knight = LoadTexture("Assets/characters/knight_idle_spritesheet.png");
    Vector2 knightPosition = {
        (float)SCREEN_WIDTH / 2.0f - 4.0f * (0.5f * (float)knight.width / 6.0f),
        (float)SCREEN_HEIGHT / 2.0f - 4.0f * (0.5f * (float)knight.height)};

    // Animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.0f / 12.0f};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Vector2 direction{};
        if (IsKeyDown(KEY_A))
            direction.x -= 1.0f;
        if (IsKeyDown(KEY_D))
            direction.x += 1.0f;
        if (IsKeyDown(KEY_W))
            direction.y -= 1.0f;
        if (IsKeyDown(KEY_S))
            direction.y += 1.0f;
        if (Vector2Length(direction) != 0.0)
        {

            mapPosition = Vector2Subtract(mapPosition, Vector2Scale(Vector2Normalize(direction), playerSpeed));
            direction.x < 0.f ? rightLeft = -1.0f : rightLeft = 1.0f;
            knight = knight_run;
        }
        else
            knight = knight_idle;

        // Game loop
        //  Draw the map
        DrawTextureEx(worldMap, mapPosition, 0, 2, WHITE);

        // Update animation frame

        runningTime += GetFrameTime();
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if (frame > maxFrames)
                frame = 0;
        }

        // Draw character
        Rectangle source{(float)knight.width / 6.0f * frame, 0.f, rightLeft * (float)knight.width / 6.0f, (float)knight.height};
        Rectangle dest{knightPosition.x, knightPosition.y, 4.0f * (float)knight.width / 6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}