#include "Necromancy.h"
#include "../../Characters/Character.h"


void Necromancy::changeFraction(Character & character) {
    character.setSide(Character::Sides::Hero);
    character.setAliveStatus(false);
    character.setDPS(character.getDPS() * 1);
}


