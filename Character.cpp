#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) : windowWidth(winWidth),
                                                    windowHeight(winHeight)
{

    width = texture.width / maxFrames;
    height = texture.height;
}
Vector2 Character::getScreenPos()
{
    return Vector2{static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
                   static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)};
}
void Character::tick(float deltaTime)
{
    if (!getAlive())
        return;

    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0f;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0f;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0f;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0f;
    BaseCharacter::tick(deltaTime);

    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    rightLeft > 0 ? rotation = 35.f : rotation = -35.f;
    if (rightLeft > 0.f)
    {
        // Facing right
        origin = {0.f, wepon.height * scale};
        offset = {35.f, 55.f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - wepon.height * scale,
            wepon.width * scale,
            wepon.height * scale};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35.f : 0.f;
    }
    else
    {
        // Facing left
        origin = {wepon.width * scale, wepon.height * scale};
        offset = {25.f, 55.f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x - wepon.width * scale,
            getScreenPos().y + offset.y - wepon.height * scale,
            wepon.width * scale,
            wepon.height * scale};
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -35.f : 0.f;
    }

    // Draw the sword
    Rectangle source{0.f, 0.f, static_cast<float>(wepon.width) * rightLeft, static_cast<float>(wepon.height)};
    Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, wepon.width * scale, wepon.height * scale};
    DrawTexturePro(wepon, source, dest, origin, rotation, WHITE);

    // Draw wepon collision rectangle
    //DrawRectangleLines(weaponCollisionRec.x, weaponCollisionRec.y, weaponCollisionRec.width, weaponCollisionRec.height, RED);
}
void Character::takeDamage(float damage){
    health-=damage;
    if (health<=0.f)
    {
        setAlive(false);
    }
    
}
