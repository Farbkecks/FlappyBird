#include "bird.h"

Bird::Bird(const sf::Vector2u &windowSize)
        : windowSize(windowSize), velocity(0) {
    birdUp.loadFromFile(constants::bird::path, constants::bird::birdUpArea);
    birdDown.loadFromFile(constants::bird::path, constants::bird::birdDownArea);

    birdSprite.setTexture(birdUp);
    birdTextureIsUp = true;

    birdSprite.setScale({constants::bird::scale, constants::bird::scale});
    position = constants::bird::startPos;

    updateSprite();
}

void Bird::changeToBirdUp() {
    if (!birdTextureIsUp) {
        birdSprite.setTexture(birdUp);
        birdTextureIsUp = true;
    }
}

void Bird::changeToBirdDown() {
    if (birdTextureIsUp) {
        birdSprite.setTexture(birdDown);
        birdTextureIsUp = false;
    }
}

void Bird::updateSprite() {
    if (velocity > 0) {
        changeToBirdUp();
    } else {
        changeToBirdDown();
    }

    checkPostionBounds();
    birdSprite.setPosition(position);
}

void Bird::setPosition(const sf::Vector2f &pos) {
    position = pos;
    updateSprite();
}

void Bird::changeY(float step) {
    position.y -= step;
    updateSprite();
}

void Bird::checkPostionBounds() {
    if (position.y < 0) {
        position.y = 0;
    }

    if (position.y > (float) windowSize.y - birdSprite.getGlobalBounds().height) {
        position.y = (float) windowSize.y - birdSprite.getGlobalBounds().height;
    }
}

float Bird::checkVelocityBounds(float num) {
    float results;


    if (constants::bird::maxVelocity < constants::bird::minVelocity) {
        print("velocity Bounds incorrect");
    }

    results = num;
    if (num > constants::bird::maxVelocity) {
        results = constants::bird::maxVelocity;
    }
    if (num < constants::bird::minVelocity) {
        results = constants::bird::minVelocity;
    }

    return results;
}

void Bird::setVelocity(float num) {
    velocity = checkVelocityBounds(num);
}

void Bird::changeVelocity(float num) {
    velocity = checkVelocityBounds(velocity += num);
}

void Bird::changeYWithCurrentVelocity() {
    changeY(velocity);
}

void Bird::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(birdSprite);
}

