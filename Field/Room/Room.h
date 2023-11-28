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
};




#endif