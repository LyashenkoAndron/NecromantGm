/**
 * Project Untitled
 */


#ifndef _ENEMY_H
#define _ENEMY_H

#include "../Character.h"


class Enemy: public Character{
public: 
    
void GetCharacteristics();
    
void ChangeCharacteristics();
    
void AttackClosest();
    
void CreateSlave();
private: 
    bool IsSummoner;
    bool IsDead;
};

#endif //_ENEMY_H