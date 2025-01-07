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

private:
    int windowWidth{};
    int windowHeight{};
};
#endif