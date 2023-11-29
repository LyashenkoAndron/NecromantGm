#include <SFML/Graphics.hpp>
#include "Characters/Character.h"
#include "Characters/Enemy/Enemy.h"
#include "Field/Room/Room.h"  // Предполагаем, что у вас есть класс Room

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Roguelike Game");

    Character hero(400, 300, 10, 50, false);

    Room room(RoomType::Empty);  // Создаем комнату (замените на ваш способ создания комнаты)
    room.spawnEnemy(100, 100, 8, 100, false);  // Пример заспавна противника в комнате

    // Основной цикл приложения
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W)
                    hero.move(sf::Vector2i(0, -1));
                else if (event.key.code == sf::Keyboard::S)
                    hero.move(sf::Vector2i(0, 1));
                else if (event.key.code == sf::Keyboard::A)
                    hero.move(sf::Vector2i(-1, 0));
                else if (event.key.code == sf::Keyboard::D)
                    hero.move(sf::Vector2i(1, 0));
            }
        }

        // Проходим по всем противникам и вызываем метод chaseHero
        for (auto& enemy : room.getArr()) {
            enemy->chaseHero(hero);
        }

        window.clear();

        // Отрисовка персонажа
        sf::RectangleShape heroShape(sf::Vector2f(30.0f, 30.0f));
        heroShape.setFillColor(sf::Color::Green);
        heroShape.setPosition(static_cast<float>(hero.getPosXY_().x), static_cast<float>(hero.getPosXY_().y));
        window.draw(heroShape);

        // Отрисовка противников
        for (auto& enemy : room.getArr()) {
            sf::RectangleShape enemyShape(sf::Vector2f(30.0f, 30.0f));
            enemyShape.setFillColor(sf::Color::Red);
            enemyShape.setPosition(static_cast<float>(enemy->getPosXY_().x), static_cast<float>(enemy->getPosXY_().y));
            window.draw(enemyShape);
        }

        window.display();
    }

    return 0;
}
