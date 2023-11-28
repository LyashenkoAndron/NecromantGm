#ifndef NECROMANCY_H
#define NECROMANCY_H


#include "../Skill.h"


class Necromancy : public Skill {
private:
    std::vector <Enemy> AchivedEnemies;

public:
    Necromancy() {}
    //void changeIntelligence(Enemy & character);
    void changeFraction(Character & character);
    //void cast(Enemy& target) override;
};



#endif