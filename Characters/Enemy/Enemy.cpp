#include "Enemy.h"
#include <iostream>


void Enemy::setIsSummoner() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    int roll = dis(gen);

    if (roll <= 2) this->IsSummoner = true;
    else this->IsSummoner = false; 
}


void Enemy::chasing(Character & hero) {
    /* imagine we have room 100 x 100
    there will be 100 cells 10 x 10
    .*
    ..
    so we need that 
    if hero stays perpendicular the enemy will go in 1 direction
    in other way he will go to the diagonal
    */
    std::cout << this->MoveSpeed << "\n";
    if (this->MoveSpeed != 0 && this->isDead == false && this->Side != hero.getSide()) {
        int x = this->PosX, y = this->PosY;
        int xHero = hero.getPosXY()[0], yHero = hero.getPosXY()[1];
        
        if (x > xHero && y > yHero) {
            this->PosX = x - 1;
            this->PosY = y - 1;
        }

        else if (x < xHero && y < yHero) {
            this->PosX = x + 1;
            this->PosY = y + 1;
        }

        else if (x > xHero && y < yHero) {
            this->PosX = x - 1;
            this->PosY = y + 1;
        }

        else if (x < xHero && y > yHero) {
            this->PosX = x + 1;
            this->PosY = y - 1;
        }

        else if (x == xHero && y > yHero)
            this->PosY = y - 1;

        else if (x == xHero && y < yHero)
            this->PosY = y + 1;
        
        else if (x > xHero && y == yHero)
            this->PosX = x - 1;
        else if (x < xHero && y == yHero)
            this->PosX = x + 1;
        std::cout << "----------------\n";
    }
    this->attack(hero, this->getMoveSpeed());
}


void Enemy::createSlave() {
    if (this->IsSummoner == true) {

        // summon a new enemy on field
    } 
}


void Enemy::changeSide() {
    if (this->Side == Character::Sides::Enemy)
        this->Side = Character::Sides::Hero;
    else 
        this->Side = Character::Sides::Enemy;
}