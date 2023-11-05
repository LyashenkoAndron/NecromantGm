#include <iostream>
#include <ctime>

#include "Player.h"


class Game {
private: 
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event sfmlEvent;
    bool endGame;

    Player player;
    
    void initVariables();
    void initWindow();
public: 
    //constructors 
    Game();
    ~Game();

    // functions
    const bool running() const;
    void pollEvent();

    void update();
    void render();

};