#include "Hero.h"
#include "../../Skills/Curse/Curse.h"
#include "../../Skills/Necromancy/Necromancy.h"
#include <iostream>

void Hero::initVariables() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    this->setXP(dis(gen));
    //this->setHP(dis(gen));
    this->setDPS (dis(gen));
    this->setIntelligence(dis(gen));
    this->setMovementSpeed(dis(gen));

    //curse->setDamageC(1); ///!!!!!!!
    Curse *curse = new Curse(); 
    curse->setDamageC(1);

    Necromancy *necromancy = new Necromancy(); 

    this->MaxHP = 1000;
    this->MaxIntelligence = 1000;
    this->MaxSlaves = 1000;
    this->Lvl = 1;
    this->setSide(Character::Sides::Hero);
    // need there init of each class of skill, then add
    // this->Skills.push_back(Curse);
}


void Hero::takeXP(int xp) {
    this->setXP(this->getXP() + xp);
    if (this->getXP() > 100) {
        this->lvlUp();
        this->XP = this->XP - 100;
    }
}


void Hero::lvlUp() {
    this->SkillPoints += 1;
    this->Lvl += 1;
}


void Hero::attack(Character &enemy, int movementSpeed) {
    if (abs(enemy.getPosXY()[0] - this->PosX) <= this->AttackRadius &&
        abs(enemy.getPosXY()[1] - this->PosY) <= this->AttackRadius && 
        this->isDead == false) {
        //std::cout << "!!!!!!!!!!\n";
        enemy.setHP(enemy.getHP() - this->DPS);

        if (enemy.getHP() <= 0) {
            enemy.Death();
            this->takeXP(enemy.getXP());
            this->Essention += 10;
        }
    }
}


/*void Hero::upgradeSkill(Skill & skill) {
    // need to choose skill
    skill.addLvl();
}


// in this func we will call func of Skills


void Hero::dessicationSkill() {}


void Hero::morphismSkill() {}
*/

void Hero::necromanceSkill(Character& enemy) {

    // fix  here radius
    if (abs(enemy.getPosXY()[0] - this->PosX) <= this->AttackRadius &&
        abs(enemy.getPosXY()[1] - this->PosY) <= this->AttackRadius && 
        enemy.getAliveStatus() == true) {
        
        std::cout << "@@@@@@@@@@\n";
        necromancy->changeFraction(enemy);
    }
}


void Hero::curseSkill(Character& enemy) {
    curse->dealDamageC(enemy);
    if (enemy.getHP() <= 0) {
        enemy.Death();
        this->takeXP(enemy.getXP());
        this->Essention += 10;
    }
}