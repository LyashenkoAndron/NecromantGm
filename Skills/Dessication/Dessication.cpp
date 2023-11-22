#include "Dessication.h"


// so, we need to check radius of action in Hero.cpp, when we call dessication()
int Dessication::recycleEnemy(int choice, Enemy& enemy) {
    if (choice == 1) { //addHP 
        return addHp(enemy);
    }
    else {
        return addIntelligence(enemy);
    }
}


int Dessication::addHp(Enemy& enemy) {
    return enemy.getIntelligence();
}


int Dessication::addIntelligence(Enemy& enemy) {
    return enemy.getHP();
}