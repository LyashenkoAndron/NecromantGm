#ifndef UNDEAD_H
#define UNDEAD_H


#include "../Enemy.h"


class Undead : public Enemy {   
public:
    Undead() = default;
    ~Undead();
    void Death() override;
};



#endif