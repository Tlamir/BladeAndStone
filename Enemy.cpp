#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    width = texture.width / maxFrames;
    height = texture.height;
    speed = 2.0f;
}

void Enemy::tick(float deltaTime)
{
    // Get toTarget
    Vector2 toTarget = Vector2Subtract(target->getScreenPos(), screenPos);
    // Normalize toTarget
    toTarget=Vector2Normalize(toTarget);
    // speed * toTarget
    toTarget=Vector2Scale(toTarget,speed);
    // worldPos=toTarget
    worldPos= Vector2Add(worldPos,toTarget);

    screenPos = Vector2Subtract(worldPos, target->getWorldPos());
    screenPos = Vector2Add(screenPos, Vector2{10.0f, 10.f});
    BaseCharacter::tick(deltaTime);
}