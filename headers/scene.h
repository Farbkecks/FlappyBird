#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "constants.h"

class Scene {
//funktions
public:
    explicit Scene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status);

    void run(const sf::Time &timeSinceLast);

//funktions
protected:
    virtual void input(sf::Event event) = 0;

    virtual void update() = 0;

    virtual void draw() = 0;


//variables
protected:
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<constants::gameState> status;
    sf::Time timeSinceLast;
};
