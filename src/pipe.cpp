#include "pipe.h"

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
    spriteTop.setPosition({pos.x + spriteTop.getGlobalBounds().width, pos.y - distance / 2});
    spriteBottom.setPosition({pos.x, pos.y + distance / 2});
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
