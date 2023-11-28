#include "Field/Floor.h"
#include "Characters/Character.h"
#include <iostream>
#include <memory>
#include <cmath>
#include <string>


int findClosestEnemyIndex(const std::vector<std::unique_ptr<Enemy>>& vectorEnemies, const Character& targetCharacter) {
    int minDistance = std::numeric_limits<int>::max();
    int closestEnemyIndex = std::numeric_limits<int>::max();

    for (size_t i = 0; i < vectorEnemies.size(); ++i) {
        int distance = targetCharacter.calculateDistance(*vectorEnemies[i]);

        if (distance < minDistance) {
            minDistance = distance;
            closestEnemyIndex = i;
        }
    }

    return closestEnemyIndex;
}


/*int main() {
    Room room(RoomType::Arena);
    room.initVariables();
    room.spawnEnemies();
    std::cout << room.getArrSize() << "\n\n";

    Hero hero;
    hero.setPosX(8);
    hero.setPosY(8);
    hero.setHP(100);
    hero.setSide(Character::Sides::Hero);
    hero.setRadiusAttack(1);
    hero.setDPS(10);
    hero.setAliveStatus(false);

    while (true) {
        int enemy = findClosestEnemyIndex(room.getArr(), hero);
        std::string direction;
        std::cin >> direction; 
        if (direction == "w") {
            room.setMatrixValue(hero.getPosXY()[1], hero.getPosXY()[0], 0);
            hero.setPosY(hero.getPosXY()[1] - 1);
        }

        else if (direction == "s") {
            room.setMatrixValue(hero.getPosXY()[1], hero.getPosXY()[0], 0);
            hero.setPosY(hero.getPosXY()[1] + 1);
        }

        else if (direction == "a") {
            room.setMatrixValue(hero.getPosXY()[1], hero.getPosXY()[0], 0);
            hero.setPosX(hero.getPosXY()[0] - 1);
        }

        else if (direction == "d") {
            room.setMatrixValue(hero.getPosXY()[1], hero.getPosXY()[0], 0);
            hero.setPosX(hero.getPosXY()[0] + 1);
        }
        else if (direction == "c") {
            int x_, y_;
            std::cin >> x_ >> y_;
            for (int i = 0; i < room.getArrSize(); i++) {
                if (room.getArr()[i]->getPosXY()[0] == x_ &&
                    room.getArr()[i]->getPosXY()[1] == y_) {

                    hero.curseSkill(*room.getArr()[i]);
                }
            }
        }
        else if (direction == "n") {
            hero.necromanceSkill(*room.getArr()[enemy]);
        }
        
        for (size_t i = 0; i < room.getArrSize(); i++) {
            room.setMatrixValue(room.getArr()[i]->getPosXY()[1], room.getArr()[i]->getPosXY()[0], 2);
        } 
        
        room.setMatrixValue(hero.getPosXY()[1], hero.getPosXY()[0], 1);

        hero.attack(*room.getArr()[enemy]);
        //std::cout << "Enemt hp: " << enemy.getHP() << "\n\n";
        
        for (int i = 0; i < room.getArrSize(); i++) {
            room.setMatrixValue(room.getArr()[i]->getPosXY()[1], room.getArr()[i]->getPosXY()[0], 0);

            if (room.getArr()[i]->Side == Character::Sides::Hero) {
                room.getArr()[i]->chasing(*room.getArr()[enemy]);
                if (room.getArr()[i]->getAliveStatus())
                    room.setMatrixValue(room.getArr()[i]->getPosXY()[1], room.getArr()[i]->getPosXY()[0], 3);
                else 
                    room.setMatrixValue(room.getArr()[i]->getPosXY()[1], room.getArr()[i]->getPosXY()[0], 4);
            }

            else {
                room.getArr()[i]->chasing(hero);
                if (room.getArr()[i]->getAliveStatus())
                    room.setMatrixValue(room.getArr()[i]->getPosXY()[1], room.getArr()[i]->getPosXY()[0], 3);
                else 
                    room.setMatrixValue(room.getArr()[i]->getPosXY()[1], room.getArr()[i]->getPosXY()[0], 2);
            }
        }
        room.print_t();
    }
}*/


/*int main() {
    Floor flr(10, 10);
    //std::cout << "0000000000\n";
    flr.generateMap();
    //std::cout << "1111111111\n";
    //flr.printMap();
    //std::cout << "2222222222\n";
}*/
