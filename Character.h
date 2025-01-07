#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int winWith, int winHeight);
    virtual void tick(float detltaTime) override;
    virtual Vector2 getScreenPos() override;
    Rectangle getWeaponCollisionRec(){return weaponCollisionRec;}
    float getHealth() const {return health;}
    void takeDamage(float damage);

private:
    int windowWidth{};
    int windowHeight{};
    Texture2D wepon{LoadTexture("Assets/characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};
    float health{100.f};
};
#endif