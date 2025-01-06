#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int winWith, int winHeight);

    void tick(float detltaTime);

private:
};