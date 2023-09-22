#pragma once

#include <SFML/Graphics.hpp>
#include "helperFuntions.h"
#include "constants.h"
#include <utility>
#include "bird.h"

class Pipe : public sf::Drawable {
public:
    //functions
    Pipe();

    Pipe(const sf::Vector2f &pos, float distance);

    Pipe(const float xPostion);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setPostion(const sf::Vector2f &pos, float distance);

    void changeX(float step);

    float getX() const;

    virtual bool collision(const std::pair<float, float> &minMax) const;

    bool collision(const Bird &bird) const;


protected:
    //functions
    void updateSprite();

    void updateSpriteTextrue();

protected:
    //variables
    sf::Texture texture;
    sf::Sprite spriteTop;
    sf::Sprite spriteBottom;
    sf::Vector2f postion;

    float distance;
};
