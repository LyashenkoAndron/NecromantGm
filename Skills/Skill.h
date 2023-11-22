#ifndef SKILL_H
#define SKILL_H

#include "../Characters/Hero/Hero.h"
#include "../Characters/Enemy/Enemy.h"


class Skill {
protected:
    int Lvl;
    int MaxLvl;
    int NeededXP;

public:
    void addLvl();
    //virtual void cast(Enemy& target);
};


#endif