#ifndef HERO_H
#define HERO_H

#include "../Character.h"
#include <cmath>
#include <random> 
#include <iostream>
#include <filesystem>
class Curse;
class Necromancy;

class Hero : public Character{
protected:
    int MaxHP;
    int MaxIntelligence;
    int Essention;
    int SkillPoints;
    int Lvl;
    int MaxSlaves;
    Curse *curse;
    Necromancy *necromancy;
    sf::Texture heroTexture;
public:
    Hero() { this->initVariables(); }

    Hero(int x, int y, int st, int dps, int radius, bool dead) : Character(x, y, st, dps, radius, dead) {
        if (!heroTexture.loadFromFile("Characters/Hero/hero.png")) {
            std::string currentDirectory = std::filesystem::current_path().string();
            std::cout << "Current directory: " << currentDirectory << std::endl;

        }
    } 
    //void upgradeSkill(Skill & skill);
    void initVariables() override;
    void attack(Character &enemy, int movementSpeed = 0) override;
    void lvlUp();
    void takeXP(int xp);


    //skills
    // крч, нам нахуй не нужен класс slave
    // тк мы можем просто изменять принадлежность касте (менять с hero на slave)
    //void dessicationSkill(Character& enemy);
    //void morphismSkill();

    //void curseSkill(Character& enemy);
    void necromanceSkill(Character& enemy);


    void draw(sf::RenderWindow& window) const {
        sf::Sprite heroSprite(heroTexture);
        heroSprite.setScale(0.03, 0.03);
        heroSprite.setPosition(PosX, PosY);
        window.draw(heroSprite);
    }
};


#endif