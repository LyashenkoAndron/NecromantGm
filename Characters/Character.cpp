#include "Character.h"
#include <math.h>
#include <random>
#include <iostream>

void Character::initVariables() {
    /*std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    this->isDead = false;
    this->XP = dis(gen);
    this->HP = dis(gen);
    this->Difficulty = dis(gen);
    this->DPS = dis(gen);
    this->Intelligence = dis(gen);
    this->MoveSpeed = dis(gen);
    */
}


void Character::attack(Character& enemy, int movementSpeed) {
    if (abs(enemy.getPosXY()[0] - this->PosX) <= this->AttackRadius &&
        abs(enemy.getPosXY()[1] - this->PosY) <= this->AttackRadius &&
        this->isDead == false && this->Side != enemy.getSide()) {
        
        std::cout << "!!!!!!!!!!!!!\n";
        //this->MoveSpeed = 0;

        enemy.setHP(enemy.getHP() - this->DPS);

        
        std::cout << "hero: " << enemy.getHP() << "\n";
        std::cout << "enemy: "<< this->HP << "\n";
    }
    
    else 
        this->MoveSpeed = movementSpeed;

    if (enemy.getHP() <= 0)
            enemy.Death();
}


void Character::takeDamage(int damage) {
    this->HP -= damage;
    if (this->HP <= 0) 
        this->Death();
}


Character::~Character() {
}


void Character::Death() {
    this->isDead = true;
    this->MoveSpeed = 0;
}


std::vector <int> Character::getPosXY() {
    std::vector <int> coords = {PosX, PosY};
    return coords;
} 


int Character::getAttackRadius() { return AttackRadius; }


int Character::getIntelligence() { return Intelligence; }


int Character::getMoveSpeed() { return MoveSpeed; }


int Character::getDPS() { return DPS; }


int Character::getHP() { return HP; }


bool Character::getAliveStatus() { return isDead; }


int Character::getXP() { return XP; }


Character::Sides Character::getSide() { return Side; }