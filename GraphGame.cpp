#include <SFML/Graphics.hpp>
#include "Characters/Character.h"
#include "Characters/Enemy/Enemy.h"
#include "Characters/Hero/Hero.h"
#include "Field/Room/Room.h"
#include "Field/Floor.h"
#include <memory>


bool isPointInsideObject(const sf::Vector2f& point, const sf::FloatRect& objectBounds) {
    return objectBounds.contains(point);
}

/*void relocate(Hero hero, Floor floor, Room room) {
    bool allEnemiesDead = true;
    for (const auto& enemy : room.getArr()) {
        if (enemy->getAliveStatus()) {
            allEnemiesDead = false;
            break;
        }
    }

    if (allEnemiesDead) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(0, 100);
        int randomNum = distribution(gen);
        if (room.getType() == RoomType::Arena && randomNum > 33) {
            room.setType(RoomType::LootRoom);
        }
        // relocate to the floor.h

    }

}*/

int main() {
    sf::RenderWindow window(sf::VideoMode(1800, 1200), "My Roguelike Game");
    Floor floor(6);
    floor.generateMap();

    Hero hero(400, 300, 20, 10, 500, false);
    hero.setHP(1000);
    hero.setSide(Character::Sides::Hero);

    Room room(RoomType::Empty, 30, 30);  // Создаем комнату (замените на ваш способ создания комнаты)
    room.setTileSize(32.f);
    room.spawnEnemies(1, 3);
    hero.setMovementSpeed(7);
    for (auto& enemy : room.getArr()) {
        enemy->setEnemySpeed(3.0f);
        enemy->setSide(Character::Sides::Enemy);
    }

    // Основной цикл приложения
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                
                if (event.key.code == sf::Keyboard::W) {
                    if (!room.isWallCollision(hero.getPosXY()[0] + 0, hero.getPosXY()[1] - hero.getMoveSpeed()))
                        hero.move(sf::Vector2i(0, -1));
                }
                else if (event.key.code == sf::Keyboard::S) {
                    if (!room.isWallCollision(hero.getPosXY()[0] + 0, hero.getPosXY()[1]  + hero.getMoveSpeed()))
                        hero.move(sf::Vector2i(0, 1));
                }
                else if (event.key.code == sf::Keyboard::A) {
                    if (!room.isWallCollision(hero.getPosXY()[0] - hero.getMoveSpeed(), hero.getPosXY()[1] + 0))
                        hero.move(sf::Vector2i(-1, 0));
                }
                else if (event.key.code == sf::Keyboard::D) {
                    if (!room.isWallCollision(hero.getPosXY()[0] + hero.getMoveSpeed(), hero.getPosXY()[1] + 0))
                        hero.move(sf::Vector2i(1, 0));
                }
                else if (event.key.code == sf::Keyboard::N) {
                    room.resurrectRandomDeadEnemy(hero.getPosXY()[0], hero.getPosXY()[1], hero.getAttackRadius());

                    //enemy_const->setMovementSpeed(7);
                }
            }

            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Проверка, находится ли курсор мыши над противником
                for (auto& enemy : room.getArr()) {
                    sf::FloatRect enemyBounds(enemy->getPosXY_().x, enemy->getPosXY_().y, 30.0f, 30.0f);
                    if (isPointInsideObject(sf::Vector2f(mousePos), enemyBounds)) {
                        // Атаковать противника
                        hero.attack(*enemy);
                    }
                }
            }
        }


        /*if (hero.getPosXY()[0] == 10 && hero.getPosXY()[1] == 12) {
            relocate(hero, floor, room);
        }*/

        std::vector <int> index;
        for (int i = 0; const auto& enemy : room.getArr()) {
            if (enemy->getSide() == Character::Sides::Enemy) 
                index.push_back(i);
            i++;
        }

            

        for (auto& enemy : room.getArr()) {
            if (enemy->getSide() == Character::Sides::Enemy)
                enemy->chaseHero(hero);

            else {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> distribution(0, index.size() - 1);
                int randomIndex = distribution(gen);
                enemy->chaseHero(*room.getArr()[index[randomIndex]]);
            }
        }
        window.clear();

        room.draw(window);

        // Отрисовка персонажа
        hero.draw(window);

        // Отрисовка противников
        /*for (auto& enemy : room.getArr()) {
            sf::RectangleShape enemyShape(sf::Vector2f(30.0f, 30.0f));
            enemyShape.setFillColor(sf::Color::Red);
            enemyShape.setPosition(static_cast<float>(enemy->getPosXY_().x), static_cast<float>(enemy->getPosXY_().y));
            window.draw(enemyShape);
        }*/

        window.display();
        sf::sleep(sf::milliseconds(20));
    }

    return 0;
}
