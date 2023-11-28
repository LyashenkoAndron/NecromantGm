#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>


class Character {
protected:
    int HP;
    int XP;
    int Difficulty;
    int DPS;
    int Intelligence;
    int PosX;
    int PosY;
    int AttackRadius;
    int MoveSpeed;
    bool isDead;

    //sfml
    float step;

public:
    enum class Sides {Hero , Enemy};
    Character::Sides Side;

    Character(int x, int y, int dps, int ra, bool dead) : PosX(x), PosY(y), DPS(dps), AttackRadius(ra), isDead(dead), Side(Sides::Enemy), HP(50), step(5.0f) {}
    Character() {}
    //destructor
    virtual ~Character();

    // getters
    std::vector <int> getPosXY();
    int getAttackRadius();
    int getMoveSpeed();
    int getDPS();
    int getHP();
    int getXP();
    int getIntelligence();
    bool getAliveStatus();
    Character::Sides getSide();

    // setters
    void setMovementSpeed(int moveSpeed) { this->MoveSpeed = moveSpeed; }
    void setHP(int hp) {this->HP = hp; }
    void setXP(int xp) {this->XP = xp; }
    void setPosX(int x) {this->PosX = x; }
    void setPosY(int y) {this->PosY = y; }
    void setSide(Character::Sides side) { this->Side = side; }
    void setDPS(int dps) {this->DPS = dps; }
    void setIntelligence(int intel) {this->Intelligence = intel; }
    void setRadiusAttack(int r) { this->AttackRadius = r; }
    void setAliveStatus(bool b) { this->isDead = b; }

    virtual void Death();
    virtual void initVariables();
    virtual void attack(Character & enemy, int movementSpeed);
    void takeDamage(int damage);
    int calculateDistance(const Character& other) const { return std::sqrt(std::pow(PosX - other.PosX, 2) + std::pow(PosY - other.PosY, 2)); }


    // sfml

    void move(sf::Vector2i direction) {
    // Обновляем позицию персонажа с использованием значения шага
        PosX += step * direction.x;
        PosY += step * direction.y;
    }   

    sf::Vector2i getPosXY_() const {
        return sf::Vector2i(PosX, PosY);
    }
};





#endif