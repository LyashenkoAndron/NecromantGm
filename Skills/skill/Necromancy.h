/**
 * Project Untitled
 */


#ifndef _NECROMANCY_H
#define _NECROMANCY_H

#include "../Skill.h"
#include "../../Character/Enemy/Enemy.h"


class Necromancy: public Skill {
public:     
    
void MakeSlave();
    
void ChangeInteligence();
    
void ChangeFraction();
    
void ChangeCharacter();
private: 
    std::vector<Enemy> AchivedEnemies;
};

#endif //_NECROMANCY_H