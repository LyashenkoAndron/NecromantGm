/**
 * Project Untitled
 */


#ifndef _HERO_H
#define _HERO_H

#include "../Character.h"
#include "../../Skills/Skill.h"


class Hero: public Character {
public: 
    
void Desiccation();
    
void Curse();
    
void Necromancy();
    
void Morphism();
    
void AddXpFromDead();
    
void LvlUp();
    
void TakeXP();
private: 
    int MaxHP;
    int MaxIntelligence;
    int XP;
    int LvlXP;
    int Essention;
    std::vector <Skill> Skills;
    int SkillPoints;
    int MaxSlaves;
};

#endif //_HERO_H