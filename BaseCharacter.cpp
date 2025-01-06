#include "BaseCharacter.h"
#include "raylib.h"

BaseCharacter::BaseCharacter()
{
}
void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

int BaseCharacter::getCharacterTextureSizex()
{
    return texture.width / maxFrames;
}

int BaseCharacter::getCharacterTextureSizey()
{
    return texture.height;
}

Rectangle BaseCharacter::getCollisonRec()
{

    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale};
}

void BaseCharacter::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;
    // Update animation frame

    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }
    // Draw character
    Rectangle source{width * frame, 0.f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}