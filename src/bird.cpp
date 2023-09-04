#include "bird.h"

Bird::Bird(const sf::Vector2f &pos, const sf::String &path) {
    birdUp.loadFromFile(path, {0, 0, 255, 180});
    birdDown.loadFromFile(path, {255, 0, 255, 180});
    birdSprite.setTexture(birdUp);
    position = pos;
    update();
}

void Bird::changeToBirdUp() {
    birdSprite.setTexture(birdUp);
}

void Bird::changeToBirdDown() {
    birdSprite.setTexture(birdDown);
}

sf::Sprite Bird::getSprite() const {
    return birdSprite;
}

void Bird::update() {
    birdSprite.setPosition(position);
}

void Bird::setPosition(const sf::Vector2f &pos) {
    position = pos;
    update();
}

void Bird::goUp(unsigned int step) {
    position.y -= step;
    update();
}

