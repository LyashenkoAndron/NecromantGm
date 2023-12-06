#ifndef ROOM_H
#define ROOM_H

#include "../../Characters/Enemy/Enemy.h"
#include "../../Characters/Hero/Hero.h"
#include "../../template/Matrix.h"
#include "../../Characters/Character.h"
#include <SFML/Graphics.hpp>
#include <filesystem>


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
    float TileSize;
    int matrix[30][30];
    std::vector<std::unique_ptr<Enemy>> vectorEnemies;
    sf::Texture floorTexture;


public:
    Room(RoomType t) : type(t) {}
    Room(RoomType t, int x, int y) : type(t), SizeX(x), SizeY(y) {
        for (int i = 0; i < SizeX; ++i) {
            for (int j = 0; j < SizeY; ++j) {
                if (i == 0 || i == SizeX - 1 || j == 0 || j == SizeY - 1) {
                    matrix[i][j] = 1;  // 1 обозначает стену
                } else {
                    matrix[i][j] = 0;  // 0 обозначает пустую клетку
                }
            }
        }

        if (!floorTexture.loadFromFile("Field/Room/flor.jpeg")) {
            std::string currentDirectory = std::filesystem::current_path().string();
            std::cout << "Current directory: " << currentDirectory << std::endl;

        }

    }

    void setTileSize(float ts) { TileSize = ts; }
    float getTileSize() const { return TileSize; }
    int getMatrixValue(int x, int y) const { return matrix[x][y]; }
    RoomType getType() const { return type; }
    int getArrSize() const { return vectorEnemies.size(); }
    std::vector<std::unique_ptr<Enemy>>& getArr() { return vectorEnemies; }
    void setMatrixValue(int x, int y, int ind) { matrix[x][y] = ind; }
    void  print_t();
    void spawnEnemies(int minEnemies, int maxEnemies);

    //sfml

    void spawnEnemy(int x, int y, int st, int dps, int radius, int ms, bool dead) {
        std::unique_ptr<Enemy> newEnemy = std::make_unique<Enemy>(x, y, st, dps, radius, ms, dead);
        newEnemy->setMovementSpeed(1);
        vectorEnemies.push_back(std::move(newEnemy));
    }

    void draw(sf::RenderWindow& window) const {
        float tileSize = 32.f;

        for (int i = 0; i < SizeX; i++) {
            for (int j = 0; j < SizeY; j++) {
                if (matrix[i][j] == 0) {
                    sf::Sprite floorSprite(floorTexture);
                    floorSprite.setScale(0.01, 0.01);
                    floorSprite.setPosition(i * tileSize, j * tileSize);
                    window.draw(floorSprite);
                }
                if (matrix[i][j] == 1) {
                    sf::RectangleShape floor(sf::Vector2f(tileSize, tileSize));
                    floor.setFillColor(sf::Color::Magenta);
                    floor.setPosition(i * tileSize, j * tileSize);
                    window.draw(floor);
                }
            }
        }

        // Отрисовка противников
        for (const auto& enemy : vectorEnemies) {
            enemy->draw(window);
            sf::RectangleShape healthBarBackground(sf::Vector2f(30.0f, 5.0f));
            healthBarBackground.setFillColor(sf::Color::Black);
            healthBarBackground.setPosition(enemy->getPosXY()[0], enemy->getPosXY()[1] - 10.0f);
            window.draw(healthBarBackground);
            
            if (!enemy->getAliveStatus()) {
                sf::RectangleShape healthBar(sf::Vector2f(enemy->getHealthPercentage() * 30.0f, 5.0f));
                healthBar.setFillColor(sf::Color::Red);
                healthBar.setPosition(enemy->getPosXY()[0], enemy->getPosXY()[1] - 10.0f);
                window.draw(healthBar);
            }

            /*sf::Text healthText;
            healthText.setString("HP: " + std::to_string(enemy->getHP()));
            healthText.setCharacterSize(30);
            healthText.setFillColor(sf::Color::Red);
            healthText.setPosition(10, 10);  // Используйте координаты, которые будут видны вам на экране
            */
            //healthText.setPosition(enemy->getPosXY()[0], enemy->getPosXY()[1] - 10);
            //window.draw(healthText);
        }
    }

    bool isWallCollision(float x, float y) const {
        int tileX = static_cast<int>((x) / TileSize);
        int tileY = static_cast<int>((y) / TileSize);
        /*tileY -= 10;
        tileX -= 10;*/
        return matrix[tileX][tileY] == 1;
    }
};




#endif