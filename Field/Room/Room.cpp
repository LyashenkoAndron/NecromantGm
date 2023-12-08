#include "Room.h"
#include <iostream>
#include <ctime>


void Room::print_t() {
    for (int i = 0; i < SizeX; i++) {
        for (int j = 0; j < SizeY; j++) {
            //Cell cel(0, nullptr);
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}


void Room::spawnEnemies(int minEnemies, int maxEnemies) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int numEnemies = std::rand() % (maxEnemies - minEnemies + 1) + minEnemies;

    for (int i = 0; i < numEnemies; ++i) {
        int x = std::rand() % SizeX * TileSize; 
        int y = std::rand() % SizeY * TileSize;

        int st = std::rand() % 10 + 1;
        int dps = std::rand() % 5 + 1;
        int ms = std::rand() % 7 + 1;
        int radius = std::rand() % 50 + 50;
        int vd = std::rand() % 500 + 50;
        bool dead = false;

        spawnEnemy(x, y, st, dps, radius, ms, dead, vd);
    }
}


