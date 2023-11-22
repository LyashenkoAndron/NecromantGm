#ifndef ALIVE_ENEMY_H
#define ALIVE_ENEMY_H


#include "../Enemy.h"


class AliveEnemy : public Enemy {
public:
    AliveEnemy() = default;
    ~AliveEnemy();

    void Death() override;
};



#endif