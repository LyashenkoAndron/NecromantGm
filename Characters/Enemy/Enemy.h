#ifndef ENEMY_H
#define ENEMY_H

#include "../Character.h"
#include <random>


class Enemy : public Character {
private:
    bool IsSummoner;
public:

    void setIsSummoner();

    void chasing(Character & hero);
    void createSlave();
    //virtual void changeCharacteristics();
    void changeSide();
};



#endif