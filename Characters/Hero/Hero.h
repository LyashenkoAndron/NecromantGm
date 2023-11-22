#ifndef HERO_H
#define HERO_H

#include "../Character.h"
#include <cmath>
#include <random> 
class Curse;
class Necromancy;

class Hero : public Character{
protected:
    int MaxHP;
    int MaxIntelligence;
    int Essention;
    int SkillPoints;
    int Lvl;
    int MaxSlaves;
    Curse *curse;
    Necromancy *necromancy;
public:
    Hero() { this->initVariables(); }

    //void upgradeSkill(Skill & skill);
    void initVariables() override;
    void attack(Character &enemy, int movementSpeed = 0) override;
    void lvlUp();
    void takeXP(int xp);

    //skills
    // крч, нам нахуй не нужен класс slave
    // тк мы можем просто изменять принадлежность касте (менять с hero на slave)
    void dessicationSkill(Character& enemy);
    void morphismSkill();

    void curseSkill(Character& enemy);
    void necromanceSkill(Character& enemy);
};


#endif