/**
 * Project Untitled
 */


#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <vector>

class Character {
public: 
    
void TakeDamage();
    
void DealDamage();
private: 
    int HP;
    int Armor;
    int Strengh;
    int Intelligence;
    enum class Fraction {Heroes, Goblins, Skeletons, Golems};
    int PosX;
    int PosY;
};

#endif //_CHARACTER_H