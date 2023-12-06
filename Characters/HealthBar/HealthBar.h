#include <SFML/Graphics.hpp>

class HealthBar {
private:
    float maxHealth;
    float currentHealth;
    sf::RectangleShape bar;

public:
    HealthBar() = default; 
    HealthBar(float maxHealth, const sf::Vector2f& position, const sf::Vector2f& size)
        : maxHealth(maxHealth), currentHealth(maxHealth) {
        bar.setSize(size);
        bar.setFillColor(sf::Color::Red);
        bar.setPosition(position);
    }

    void setCurrentHealth(float health) {
        currentHealth = std::max(0.0f, std::min(maxHealth, health));
        float healthPercentage = currentHealth / maxHealth;
        bar.setSize(sf::Vector2f(bar.getSize().x * healthPercentage, bar.getSize().y));
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(bar);
    }
};
