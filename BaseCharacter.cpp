#include "BaseCharacter.h"
#include "raylib.h"

BaseCharacter::BaseCharacter(){

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