#pragma once

#include <SFML/Graphics.hpp>
#include "bird.h"
#include "print.h"

class Engine {
public:
    //functions
    Engine(unsigned int height, unsigned int width, const sf::String &title);

    void input();

    void update();

    void draw();

    void run();

private:
    //functions

private:
    //variables
    sf::Vector2<unsigned int> resolution;
    sf::RenderWindow window;

    Bird bird;

    sf::Time timeSinceLastMove;
};
