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
    std::vector<std::vector<std::unique_ptr<Room>>> rooms;

public:
    Floor(int x, int y) : sizeX(x), sizeY(y), rooms(x, std::vector<std::unique_ptr<Room>>(y, nullptr)) {}

    void generateMap() {
        // Генерация комнат
        for (int i = 0; i < sizeX; ++i) {
            for (int j = 0; j < sizeY; ++j) {
                RoomType randomRoomType = static_cast<RoomType>(rand() % static_cast<int>(RoomType::Spawn) + 1);
                rooms[i][j] = std::make_unique<Room>(randomRoomType);
            }
        }

        // Создание коридоров
        for (int i = 0; i < sizeX; ++i) {
            for (int j = 0; j < sizeY; ++j) {
                createCorridor(i, j, (i + 1) % sizeX, j); // Горизонтальный коридор
                createCorridor(i, j, i, (j + 1) % sizeY); // Вертикальный коридор
            }
        }
    }

    void printMap() const {
        for (int i = 0; i < sizeX; ++i) {
            for (int j = 0; j < sizeY; ++j) {
                switch (rooms[i][j]->getType()) {
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
            }
            std::cout << '\n';
        }
    }

private:
    void createCorridor(int x1, int y1, int x2, int y2) {
        // Логика создания коридора между комнатами (x1, y1) и (x2, y2)
        // Пример простой логики; можно настроить под свои требования
        RoomType type1 = rooms[x1][y1]->getType();
        RoomType type2 = rooms[x2][y2]->getType();

        if (type1 != RoomType::Empty && type2 != RoomType::Empty) {
            std::cout << "Создание коридора между (" << x1 << ", " << y1 << ") и (" << x2 << ", " << y2 << ")\n";
            // Добавить логику для заполнения коридора или соединения существующих комнат
        }
    }
};


#endif