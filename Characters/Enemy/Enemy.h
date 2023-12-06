#ifndef ENEMY_H
#define ENEMY_H

#include "../Character.h"
#include <random>
#include <iostream>


class Enemy : public Character {
private:
    bool IsSummoner;
    float EnemySpeed;
public:
    Enemy(int x, int y, int st, int dps, int radius, int ms, bool dead) : Character(x, y, st, dps, radius, ms, dead) {} 
    void setIsSummoner();
     void setEnemySpeed(float speed) { EnemySpeed = speed; }

    void chasing(Character & hero);
    void createSlave();
    //virtual void changeCharacteristics();
    void changeSide();



    // sfml

    void chaseHero(Character& hero) {
        sf::Vector2i heroPos = hero.getPosXY_();

        int dx = (heroPos.x > PosX) ? 1 : ((heroPos.x < PosX) ? -1 : 0);
        int dy = (heroPos.y > PosY) ? 1 : ((heroPos.y < PosY) ? -1 : 0);

        int distance = calculateDistance(hero);

        if (distance > AttackRadius) {
            float speed = EnemySpeed;
            PosX += dx * MoveSpeed;
            PosY += dy * MoveSpeed;
        }

        else {
            //this->attack(hero, this->getMoveSpeed());
        }
    }


    void draw(sf::RenderWindow& window) const {
        sf::CircleShape enemyShape(15.f);
        enemyShape.setFillColor(sf::Color::Blue);
        enemyShape.setPosition(PosX, PosY);
        window.draw(enemyShape);
    }
};



#endif