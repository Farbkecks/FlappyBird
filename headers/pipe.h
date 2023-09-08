#pragma once

#include <SFML/Graphics.hpp>
#include "print.h"
#include "constants.h"
#include <utility>

class Pipe : public sf::Drawable {
public:
    //functions
    Pipe();
    Pipe(const sf::Vector2f &pos, float distance);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setPostion(const sf::Vector2f &pos, float distance);

    void changeX(float step);
    float getX() const;

    bool collision(const std::pair<float, float> &minMax) const;

private:
    //functions
    void updateSprite();

private:
    //variables
    sf::Texture texture;
    sf::Sprite spriteTop;
    sf::Sprite spriteBottom;
    sf::Vector2f postion;
    float distance;
};
