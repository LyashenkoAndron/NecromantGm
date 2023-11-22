#ifndef FLOOR_H
#define FLOOR_H

#include "Room/Room.h"
#include <vector>
#include <memory>
#include <iostream>


class Floor {
private:
    int sizeX;
    int sizeY;
    std::vector<std::vector<std::shared_ptr<Room>>> rooms;

public:
    /*void generateMap() {
        for (int i = 0; i < sizeX; ++i) {
            for (int j = 0; j < sizeY; ++j) {
                /*if (!rooms[i][j]) {
                    RoomType roomType = getRandomRoomType();
                    rooms[i][j] = std::make_shared<Room>(roomType);

                    if (roomType == RoomType::Empty) {
                        addHallways(i, j);
                    }
                }
                //rooms[i][j] = std::make_shared<Room>(RoomType::Arena);
            }
        }
    }

    RoomType getRandomRoomType() {
        int randNum = rand() % 5; // 0-4
        switch (randNum) {
            case 0: return RoomType::Empty;
            case 1: return RoomType::Hallway;
            case 2: return RoomType::LootRoom;
            case 3: return RoomType::Arena;
            case 4: return RoomType::Spawn;
            default: return RoomType::Empty;
        }
    }

    void addHallways(int x, int y) {
        addHallway(x - 1, y);
        addHallway(x + 1, y);
        addHallway(x, y - 1);
        addHallway(x, y + 1);
    }

    void addHallway(int x, int y) {
        if (x >= 0 && x < sizeX && y >= 0 && y < sizeY && !rooms[x][y]) {
            rooms[x][y] = std::make_shared<Room>(RoomType::Hallway);
        }
    }

    void printMap() {
        for (int i = 0; i < sizeX; ++i) {
            for (int j = 0; j < sizeY; ++j) {
                char roomSymbol = getRoomSymbol(rooms[i][j]->getType());
                std::cout << roomSymbol << " ";
            }
            std::cout << std::endl;
        }
    }

    char getRoomSymbol(RoomType type) {
        switch (type) {
            case RoomType::Empty: return '0';
            case RoomType::Hallway: return 'h';
            case RoomType::LootRoom: return 'l';
            case RoomType::Arena: return 'a';
            case RoomType::Spawn: return 's';
            default: return '?';
        }
    }*/
};




#endif