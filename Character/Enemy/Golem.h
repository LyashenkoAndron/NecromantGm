/**
 * Project Untitled
 */


#ifndef _GOLEM_H
#define _GOLEM_H

#include "Enemy.h"

class Golem: public Enemy {
public: 
    
void ShowAnomaly();
    
void MissDirection();
private: 
    enum class Type {Fire, Curse, Ice};
};

#endif //_GOLEM_H