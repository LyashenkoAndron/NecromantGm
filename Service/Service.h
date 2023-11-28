#ifndef SERVICE_H
#define SERVICE_H


#include "../Characters/Character.h"
#include "../Characters/Hero/Hero.h"


class Service
{
private:
    /* data */
public:
    Service();
    ~Service();

    void attaking(std::vector<std::unique_ptr<Character>> arr);
    void movingEnemies(std::vector<std::unique_ptr<Character>> &arr);
    void movingHero(Hero &hero);
    void updateMap(std::vector<std::unique_ptr<Character>> arr, Hero &hero);
};



#endif