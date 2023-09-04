#pragma once

#include <SFML/Graphics.hpp>

#include "print.h"


class Bird {
//public:
//    template<typename T>
//    struct Range {
//        T number = 0;
//        const T maxNumber = 20;
//        const T minNumber = -10;
//
//        void changeNumberInBounds(T x) {
//            number = x > maxNumber ? maxNumber : x;
//            number = x < minNumber ? minNumber : x;
//        }
//    };

public:
    //functions
    explicit Bird(const sf::Vector2f &pos, const sf::String &path, const sf::Vector2u &windowSize);

    void changeToBirdUp();

    void changeToBirdDown();

    void setPosition(const sf::Vector2f &pos);

    void changeY(float step);

    sf::Sprite getSprite() const;

    void setVelocity(float num);

    void changeVelocity(float num);

    void change();

private:
    //functions
    void update();

    void checkForBounds();

    float static checkVelocityBounds(float num);

private:
    //variables
    sf::Texture birdUp;
    sf::Texture birdDown;
    sf::Sprite birdSprite;
    sf::Vector2f position;
    const sf::Vector2u windowSize;
    float velocity;
};
