#ifndef SLAVE_H
#define SLAVE_H


#include "../Enemy.h"


class Slave : public Enemy {
public: 

    /*
    destruct
    */
    Slave() = default;
    ~Slave();

    void copyCharacter(Character & enemy);
};


#endif