#include "pipe.h"

Pipe::Pipe(const sf::String &path) {
    float scale = 0.5;

    texture.loadFromFile(path);
    spriteTop.setTexture(texture);
    spriteTop.setScale(scale, scale);
    spriteTop.setRotation(180);
    spriteBottom.setTexture(texture);
    spriteBottom.setScale(scale, scale);

}

void Pipe::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(spriteTop);
    target.draw(spriteBottom);
}

void Pipe::setPostion(const sf::Vector2f &pos, float distance) {
    spriteTop.setPosition({pos.x + spriteTop.getGlobalBounds().width, pos.y - distance / 2});
    spriteBottom.setPosition({pos.x, pos.y + distance / 2});
}
