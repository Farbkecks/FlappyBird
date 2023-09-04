#pragma once

#include <SFML/Graphics.hpp>

class Bird {
public:
    //functions
    explicit Bird(const sf::Vector2f &pos, const sf::String &path);

    void changeToBirdUp();

    void changeToBirdDown();

    void setPosition(const sf::Vector2f &pos);

    void goUp(unsigned int step);

    sf::Sprite getSprite() const;

private:
    //functions
    void update();

private:
    //variables
    sf::Texture birdUp;
    sf::Texture birdDown;
    sf::Sprite birdSprite;
    sf::Vector2f position;
};
