#include "pipe.h"
#include "helperFuntions.h"

Pipe::Pipe() {

    texture.loadFromFile(constants::pipe::path);
    spriteTop.setTexture(texture);
    spriteTop.setScale(constants::pipe::scale, constants::pipe::scale);
    spriteTop.setRotation(180);
    spriteBottom.setTexture(texture);
    spriteBottom.setScale(constants::pipe::scale, constants::pipe::scale);

}

void Pipe::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(spriteTop);
    target.draw(spriteBottom);
}

void Pipe::setPostion(const sf::Vector2f &pos, float distance) {
    postion = pos;
    this->distance = distance;
    updateSprite();
}

bool Pipe::collision(const std::pair<float, float> &minMax) const {
    float min, max;
    std::tie(min, max) = minMax;
    if (spriteTop.getGlobalBounds().top + spriteTop.getGlobalBounds().height > min) {
        return true;
    }
    if (spriteBottom.getGlobalBounds().top < max) {
        return true;
    }
    return false;
}

Pipe::Pipe(const sf::Vector2f &pos, float distance) :
Pipe(){
    setPostion(pos, distance);
    updateSprite();
}

Pipe::Pipe(const float xPostion)
:Pipe(
        {xPostion, helperFunktions::randomNum(constants::pipe::PipeYPostionRange)},
        helperFunktions::randomNum(constants::pipe::pipeDistanceRange)
        )
{}

void Pipe::updateSprite() {
    spriteTop.setPosition({postion.x + spriteTop.getGlobalBounds().width, postion.y - distance / 2});
    spriteBottom.setPosition({postion.x, postion.y + distance / 2});
}

void Pipe::changeX(float step) {
    postion.x += step;
    updateSprite();
}

float Pipe::getX() const {
    return postion.x;
}
