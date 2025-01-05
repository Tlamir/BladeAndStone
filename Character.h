#include "raylib.h"

class Character
{
public:
    Character(int winWith, int winHeight);
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPos(int winWith, int winHeight);
    void tick(float detltaTime);
    void undoMovement();

private:
    Texture2D texture{LoadTexture("Assets/characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("Assets/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("Assets/characters/knight_run_spritesheet.png")};
    Vector2 screenPos;
    Vector2 worldPos{0.f, 0.f};
    // 1 facing right, -1 facing left
    float rightLeft = 1.0f;
    // Animation variables
    float runningTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.0f / 12.0f};
    float speed{4.f};
    float width{};
    float height{};
    float scale{4.0f};
    Vector2 worldPosLastFrame;
};