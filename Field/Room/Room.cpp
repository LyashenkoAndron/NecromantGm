#include "Room.h"
#include <iostream>


void Room::initVariables() {
    this->SizeX = 16;
    this->SizeY = 16;
    for (int i = 0; i < SizeX; i++) {
        for (int j = 0; j < SizeY; j++) {
            //Cell cel(0, nullptr);
            matrix[i][j] = 0;
        }
    }
}


void Room::print_t() {
    for (int i = 0; i < SizeX; i++) {
        for (int j = 0; j < SizeY; j++) {
            //Cell cel(0, nullptr);
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}


void Room::spawnEnemies() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int numEnemies = std::rand() % 5 + 1;

    for (int i = 0; i < numEnemies; ++i) {
        int randomSide = std::rand() % 4; 
        int randomX, randomY;

        switch (randomSide) {
            case 0:
                randomX = std::rand() % SizeX;
                randomY = 0;
                break;
            case 1: 
                randomX = SizeX - 1;
                randomY = std::rand() % SizeY;
                break;
            case 2: 
                randomX = std::rand() % SizeX;
                randomY = SizeY - 1;
                break;
            case 3: 
                randomX = 0;
                randomY = std::rand() % SizeY;
                break;
            default:
                break;
        }

        vectorEnemies.push_back(std::make_unique<Character>(randomX, randomY, 0, 2));
        
    }
}
