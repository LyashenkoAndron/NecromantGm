#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>


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

public:
    enum class Sides {Hero , Enemy};
    Character::Sides Side;

    Character(int x, int y, int dps, int ra) : PosX(x), PosY(y), DPS(dps), AttackRadius(ra) {}

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

    //hooks
    // virtual void onDamage(...) {}
    // virtual void onDeath(...) {}
    // virtual void onHeal(...) {}
    // virtual void onAttack(...) {}
};





#endif