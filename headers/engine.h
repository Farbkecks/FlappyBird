#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Engine {
public:
    //functions
    Engine(unsigned int height, unsigned int width, const sf::String &title);

    void input();

    void run();

private:
    //functions

private:
    //variables
    sf::Vector2f resolution;
    sf::RenderWindow window;
    sf::Texture birdUp;
    sf::Texture birdDown;
    sf::Sprite birdSprite;

};
