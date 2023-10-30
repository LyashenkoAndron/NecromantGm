/**
 * Project Untitled
 */


#ifndef _ARENA_H
#define _ARENA_H

#include "../Room.h"
#include "../../Character/Enemy/Enemy.h"
#include <vector>

class Arena: public Room {
public: 
    
void SpawnEnemies();
private: 
    std::vector <Enemy> AllEnemies;
};

#endif //_ARENA_H