#include "Field/Floor.h"
#include "Characters/Character.h"
#include <iostream>
#include <string>



int main() {
    //храним матрицу чисел
    Floor floor;
    //floor.generateMap();
    //floor.printMap();
    /*Hero hero;
    Enemy enemy;
    Enemy enemy2;
    enemy.setRadiusAttack(2);
    enemy.setMovementSpeed(1);
    hero.setPosX(1);
    hero.setPosY(1);
    hero.setHP(100);
    hero.setSide(Character::Sides::Hero);
    enemy.setSide(Character::Sides::Enemy);
    hero.setRadiusAttack(1);
    hero.setDPS(2);
    hero.setAliveStatus(false);
    enemy.setAliveStatus(false);
    enemy.setHP(10);
    //std::cout << hero.getHP();
    enemy.setPosX(7);
    enemy.setPosY(7);

    Room room(RoomType::Hallway);
    room.initVariables();
    while (true) {
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
            hero.curseSkill(enemy);
            std::cout << "!!!!!!!!!!!!!\nhero: " << hero.getHP() << "\nenemy: " << enemy.getHP() << std::endl;
        }
        
        else if (direction == "c") {
            hero.curseSkill(enemy);
        }
        else if (direction == "n") {
            hero.necromanceSkill(enemy);
            std::cout << enemy.getAliveStatus() << "\n\n";
        }
        hero.attack(enemy);
        room.setMatrixValue(enemy.getPosXY()[1], enemy.getPosXY()[0], 0);
        enemy.chasing(hero);
        room.setMatrixValue(hero.getPosXY()[1], hero.getPosXY()[0], 1);
        if (enemy.getAliveStatus() == false)
            room.setMatrixValue(enemy.getPosXY()[1], enemy.getPosXY()[0], 2);
        else
            room.setMatrixValue(enemy.getPosXY()[1], enemy.getPosXY()[0], 3); 
        room.print_t();
    }
    */

    Room room;
    room.spawnEnemies();

    Hero hero;
    hero.setPosX(1);
    hero.setPosY(1);
    hero.setHP(100);
    hero.setSide(Character::Sides::Enemy);
    hero.setRadiusAttack(1);
    hero.setDPS(2);

    for (size_t i = 0; i < room.)
    room.print_t();
}
