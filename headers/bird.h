#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "helperFuntions.h"
#include <utility>


class Bird : public sf::Drawable {

public:
    //functions
    explicit Bird(const sf::Vector2u &windowSize);

    void setPosition(const sf::Vector2f &pos);

    void changeY(float step);

    void setVelocity(float num);

    void changeVelocity(float num);

    void changeYWithCurrentVelocity();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    std::pair<float, float> getMinMaxY() const;


private:
    //functions

    void changeToBirdUp();

    void changeToBirdDown();

    void updateSprite();

    void checkPostionBounds();

    float static checkVelocityBounds(float num);

private:
    //variables
    sf::Texture birdUp;
    sf::Texture birdDown;
    bool birdTextureIsUp;
    sf::Sprite birdSprite;
    sf::Vector2f position;
    const sf::Vector2u windowSize;
    float velocity;
};
