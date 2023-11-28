#ifndef ENEMY_H
#define ENEMY_H

#include "../Character.h"
#include <random>


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
};



#endif