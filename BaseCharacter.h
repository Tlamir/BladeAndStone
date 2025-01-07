#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "raylib.h"
class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle getCollisonRec();
    int getCharacterTextureSizex();
    int getCharacterTextureSizey();
    virtual void tick(float deltaTime);
    virtual Vector2 getScreenPos() = 0; // pure virtual function

protected:
    Texture2D texture{LoadTexture("Assets/characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("Assets/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("Assets/characters/knight_run_spritesheet.png")};
    Vector2 worldPos{0.f, 0.f};
    // 1 facing right, -1 facing lef
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
    Vector2 velocity{};

private:
};
#endif