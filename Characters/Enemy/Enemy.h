#ifndef ENEMY_H
#define ENEMY_H

#include "../Character.h"
#include <random>
#include <iostream>


class Enemy : public Character {
private:
    bool IsSummoner;
public:
    Enemy(int x, int y, int dps, int radius, bool dead) : Character(x, y, dps, radius, dead) {} 
    void setIsSummoner();

    void chasing(Character & hero);
    void createSlave();
    //virtual void changeCharacteristics();
    void changeSide();



    // sfml



    void chaseHero(Character& hero) {
        sf::Vector2i heroPos = hero.getPosXY_();

        int dx = (heroPos.x > PosX) ? 1 : ((heroPos.x < PosX) ? -1 : 0);
        int dy = (heroPos.y > PosY) ? 1 : ((heroPos.y < PosY) ? -1 : 0);

        int distance = calculateDistance(hero);

        if (distance > AttackRadius) {
            PosX += dx * MoveSpeed;
            PosY += dy * MoveSpeed;
        }

        else {
            this->attack(hero, this->getMoveSpeed());
        }
    }
};



#endif