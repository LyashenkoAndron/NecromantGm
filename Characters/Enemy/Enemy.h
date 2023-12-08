#ifndef ENEMY_H
#define ENEMY_H

#include "../Character.h"
#include <random>
#include <SFML/Graphics.hpp>
#include <iostream>


class Enemy : public Character {
private:
    bool IsSummoner;
    float EnemySpeed;
    float VisibilityDistance; 
    sf::Time attackCooldown;
public:
    Enemy(int x, int y, int st, int dps, int radius, int ms, bool dead, float vd) : Character(x, y, st, dps, radius, ms, dead), VisibilityDistance(vd) {} 
    void setIsSummoner();
    void setEnemySpeed(float speed) { EnemySpeed = speed; }
    void setVisibilityDistance(float vd) { VisibilityDistance = vd; }
    float getVisibilityDistance() { return VisibilityDistance; }

    void chasing(Character & hero);
    void createSlave();
    //virtual void changeCharacteristics();
    void changeSide();



    // sfml
    bool isHeroVisible(const Character& hero) const {
        int distance = calculateDistance(hero);
        return distance <= VisibilityDistance;
    }

    void chaseHero(Character& hero) {
        sf::Vector2i heroPos = hero.getPosXY_();

        int dx = (heroPos.x > PosX) ? 1 : ((heroPos.x < PosX) ? -1 : 0);
        int dy = (heroPos.y > PosY) ? 1 : ((heroPos.y < PosY) ? -1 : 0);

        int distance = calculateDistance(hero);

        if (distance <= VisibilityDistance) {
            if (distance > AttackRadius) {
                float speed = EnemySpeed;
                PosX += dx * MoveSpeed;
                PosY += dy * MoveSpeed;
            } else {
                static sf::Clock clock; 
                sf::Time elapsed = clock.restart();

                update(elapsed, hero);
            }
        }
    }



    void draw(sf::RenderWindow& window) const {
        sf::CircleShape enemyShape(15.f);
        enemyShape.setFillColor(sf::Color::Blue);
        enemyShape.setPosition(PosX, PosY);
        window.draw(enemyShape);
    }


    void update(sf::Time elapsed, Character & hero) {
        attackCooldown -= elapsed;
        if (attackCooldown <= sf::Time::Zero) {
            attack(hero, this->MoveSpeed);
            resetAttackCooldown();
        }
    }


    void resetAttackCooldown() {
        attackCooldown = sf::milliseconds(rand() % 3000 + 1000);  // Атака раз в диапазоне 1-4 секунд
    }
};



#endif