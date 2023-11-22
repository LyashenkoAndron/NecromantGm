#ifndef CURSE_H
#define CURSE_H

#include "../Skill.h"
#include "../../Characters/Character.h"
#include <iostream>


class Curse : public Skill {
protected: 
    int DamageC;
public:
    Curse() : DamageC(1) {};

    int getDamageC() { return DamageC; }
    void setDamageC(int dmg) { DamageC = dmg; }
    //void cast(Enemy& target) override;
    void dealDamageC(Character & enemy);
    void initVariables();

};


#endif