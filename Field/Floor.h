#ifndef FLOOR_H
#define FLOOR_H

#include "Room/Room.h"
#include <vector>
#include <memory>
#include <iostream>



class Floor {
private:
    int sizeX;
    std::vector<Room*> rooms;

public:
    Floor() = default;
    Floor(int x) : sizeX(x) {}
    void generateMap() {
        // Генерация комнат
        for (int i = 0; i < sizeX; ++i) {
                //RoomType randomRoomType = static_cast<RoomType>(rand() % static_cast<int>(RoomType::Spawn) + 1);
                Room *rom = new Room(RoomType::Arena, 30, 30);
                rooms.push_back(rom);
        }
    }

    void printMap() const {
        for (int i = 0; i < sizeX; ++i) {
                switch (rooms[i]->getType()) {
                    case RoomType::Empty:
                        std::cout << "E ";
                        break;
                    case RoomType::Hallway:
                        std::cout << "H ";
                        break;
                    case RoomType::LootRoom:
                        std::cout << "L ";
                        break;
                    case RoomType::Arena:
                        std::cout << "A ";
                        break;
                    case RoomType::Spawn:
                        std::cout << "S ";
                        break;
            }
            std::cout << '\n';
        }
    }
};


#endif