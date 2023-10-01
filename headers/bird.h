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

    sf::Vector2f getPostion() const;

    sf::Vector2f getSchnabelPostion() const;

    void changeY(float step);

    void setVelocity(float num);

    void changeVelocity(float num);

    void changeYWithCurrentVelocity();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    std::pair<float, float> getMinMaxY() const;

    void setDeath();

    bool getDeath() const;

    void incrementScore(int score);


    int getScore() const;

    Bird &operator=(const Bird &other);

    void reset();


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
    const sf::Vector2u windowSize;
    sf::Sprite birdSprite;
    bool birdTextureIsUp;
    sf::Vector2f position;
    float velocity;
    int score;
    bool death;
};
