#include "Curse.h"
#include <iostream>


void Curse::initVariables() {
    this->DamageC = 10;
}


void Curse::dealDamageC(Character & enemy) {
    //std::cout << this->getDamageC() << "\n\n";
    enemy.setHP(enemy.getHP() - 1);
}
