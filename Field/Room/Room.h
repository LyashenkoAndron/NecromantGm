#ifndef ROOM_H
#define ROOM_H

#include "../../Characters/Enemy/Enemy.h"
#include "../../Characters/Hero/Hero.h"
#include "../../template/Matrix.h"
#include "../../Characters/Character.h"


enum class RoomType {
    Empty,
    Hallway,
    LootRoom,
    Arena,
    Spawn
};



// крч, будем использовать комнату, для того, чтобы отрисовывать в будущем все (пол, стены, препятствия сундуки)
class Room {
protected: 
    int SizeX;
    int SizeY;
    RoomType type;
    int matrix[16][16];
    std::vector<std::unique_ptr<Enemy>> vectorEnemies;


public:
    Room(RoomType t) : type(t) {}

    RoomType getType() const { return type; }
    int getArrSize() const { return vectorEnemies.size(); }
    std::vector<std::unique_ptr<Enemy>>& getArr() { return vectorEnemies; }
    void setMatrixValue(int x, int y, int ind) { matrix[x][y] = ind; }
    void initVariables();
    void  print_t();
    void spawnEnemies();

    //sfml

    void spawnEnemy(int x, int y, int dps, int radius, bool dead) {
        std::unique_ptr<Enemy> newEnemy = std::make_unique<Enemy>(x, y, dps, radius, dead);
        newEnemy->setMovementSpeed(1);
        vectorEnemies.push_back(std::move(newEnemy));
    }
};




#endif