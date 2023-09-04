#include "bird.h"

Bird::Bird(const sf::Vector2f &pos, const sf::String &path, const sf::Vector2u &windowSize)
        : windowSize(windowSize), velocity(0) {
    birdUp.loadFromFile(path, {0, 0, 255, 180});
    birdDown.loadFromFile(path, {255, 0, 255, 180});
    birdSprite.setTexture(birdUp);
    birdSprite.setScale({0.3, 0.3});
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
    checkForBounds();
    birdSprite.setPosition(position);
}

void Bird::setPosition(const sf::Vector2f &pos) {
    position = pos;
    update();
}

void Bird::changeY(float step) {
    position.y -= step;
    update();
}

void Bird::checkForBounds() {
    if (position.y < 0) {
        position.y = 0;
    }

    if (position.y > (float) windowSize.y - birdSprite.getGlobalBounds().height) {
        position.y = (float) windowSize.y - birdSprite.getGlobalBounds().height;
    }
}

float Bird::checkVelocityBounds(float num) {
    float results;
    const float maxNumber = 20;
    const float minNumber = -13;

    if (maxNumber < minNumber) {
        print("velocity Bounds incorrect");
    }

    results = num;
    if (num > maxNumber) {
        results = maxNumber;
    }
    if (num < minNumber) {
        results = minNumber;
    }

    return results;
}

void Bird::setVelocity(float num) {
    velocity = checkVelocityBounds(num);
}

void Bird::changeVelocity(float num) {
    velocity = checkVelocityBounds(velocity += num);
}

void Bird::change() {
    changeY(velocity);
}

