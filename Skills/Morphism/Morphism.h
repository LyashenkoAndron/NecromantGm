#ifndef MORPHISM_H
#define MORPHISM_H


#include "../Skill.h"


class Morphism : public Skill {
public:
    void ChangeCharacteristicsEnemy();
    void ChangeCharactiristicsSlave();
    void cast(Enemy& target) override;
};



#endif