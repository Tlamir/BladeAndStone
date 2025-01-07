#include "BaseCharacter.h"
#include "raylib.h"
#include "raymath.h"

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
        getScreenPos().x,
        getScreenPos().y,
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
    if (Vector2Length(velocity) != 0.0)
    {
        // Set worldPos = worldPos + velocity
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1.0f : rightLeft = 1.0f;
        texture = run;
    }
    else
        texture = idle;
    velocity = {};
    // Draw character
    Rectangle source{width * frame, 0.f, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}