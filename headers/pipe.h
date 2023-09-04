#pragma once

#include <SFML/Graphics.hpp>
#include "print.h"
#include "constants.h"

class Pipe : public sf::Drawable {
public:
    //functions
    explicit Pipe();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setPostion(const sf::Vector2f &pos, float distance);

private:
    //functions

private:
    //variables
    sf::Texture texture;
    sf::Sprite spriteTop;
    sf::Sprite spriteBottom;

};
