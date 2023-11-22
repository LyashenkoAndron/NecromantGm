#ifndef GOLEM_H
#define GOLEM_H


#include "../Enemy.h"


class Golem : public Enemy {
private: 
    enum class Type {Efir , Stone};
public:
    Golem() = default;

    void MissDirection();
};



#endif