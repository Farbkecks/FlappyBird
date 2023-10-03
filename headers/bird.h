#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "helperFuntions.h"
//#include "pipe.h"
#include <utility>
#include <memory>


class Bird : public sf::Drawable {

public:
    //functions
    explicit Bird();


    void setPosition(const sf::Vector2f &pos);

    sf::Vector2f getPostion() const;

    sf::Vector2f getSchnabelPostion() const;

    std::pair<float, float> getMinMaxY() const;


    void changeY(float step);


    void setVelocity(float num);

    void changeVelocity(float num);


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    Bird &operator=(const Bird &other);


    void setDeath();

    bool getDeath() const;


    void incrementScore(int score);

    int getScore() const;


    void reset();


private:
    //functions

    void changeToBirdUp();

    void changeToBirdDown();

    void updateSprite();

    void checkPostionBounds();

    float static checkVelocityBounds(float num);

    void changeYWithCurrentVelocity();

private:
    //variables
    sf::Texture birdUp;
    sf::Texture birdDown;
    sf::Sprite birdSprite;
    bool birdTextureIsUp;
    sf::Vector2f position;
    float velocity;
    int score;
    bool death;
};
