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
    // Draw character
    Rectangle source{(float)texture.width / 6.0f * frame, 0.f, rightLeft * (float)texture.width / 6.0f, (float)texture.height};
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * (float)texture.width / 6.0f, 4.0f * (float)texture.height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Blade & Stone");

    SetTargetFPS(60);

    // World map texture
    Texture2D worldMap = LoadTexture("Assets/WorldMap2.png");
    Vector2 mapPosition = {0.0f, 0.0f};

    Character playerCharacter;
    playerCharacter.setScreenPos(SCREEN_WIDTH,SCREEN_HEIGHT);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        mapPosition = Vector2Scale(playerCharacter.getWorldPos(),-1.f);
        //  Draw the map
        DrawTextureEx(worldMap, mapPosition, 0, 2, WHITE);

        // Update animation frame
        playerCharacter.tick(GetFrameTime());
        EndDrawing();
    }

    CloseWindow();

    return 0;
}