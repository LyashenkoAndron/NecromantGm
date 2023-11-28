#include <SFML/Graphics.hpp>
#include "Characters/Character.h"  // Подключите заголовочный файл вашего класса Character

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Roguelike Game");
    Character hero(400, 300, 10, 50, false);

    sf::RectangleShape heroShape(sf::Vector2f(30.0f, 30.0f));
    heroShape.setFillColor(sf::Color::Green);

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
                if (event.key.code == sf::Keyboard::A)
                    hero.move(sf::Vector2i(-1, 0));
                else if (event.key.code == sf::Keyboard::D)
                    hero.move(sf::Vector2i(1, 0));
            }
        }

        hero.move(sf::Vector2i(0, 0));  // Обновление без движения, чтобы вызвать проверку границ
        sf::Vector2i pos = hero.getPosXY_();
        pos.x = std::max(0, std::min(pos.x, 800 - 30));  // Ограничение по горизонтали
        pos.y = std::max(0, std::min(pos.y, 600 - 30));  // Ограничение по вертикали
        hero.setPosX(pos.x);
        hero.setPosY(pos.y);

        window.clear();

        // Отрисовка персонажа
        heroShape.setPosition(static_cast<float>(hero.getPosXY()[0]), static_cast<float>(hero.getPosXY()[1]));
        window.draw(heroShape);

        window.display();
    }

    return 0;
}
