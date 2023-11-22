#ifndef DESSICATION_H
#define DESSICATION_H

#include "../Skill.h"
#include "../../Characters/Enemy/Enemy.h"


class Dessication : public Skill {
private:
    int RadiusOfSkill;

public:
    int recycleEnemy(int choice, Enemy& enemy);
    int addIntelligence(Enemy& enemy);
    int addHp(Enemy& enemy);
    void cast(Enemy& target) override;
};



#endif