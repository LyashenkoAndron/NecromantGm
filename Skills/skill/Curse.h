/**
 * Project Untitled
 */


#ifndef _CURSE_H
#define _CURSE_H

#include "../Skill.h"


class Curse: public Skill {
public: 
    
void DeakDamage();
private: 
    void TakeAim();
    int AimX;
    int AimY;
};

#endif //_CURSE_H