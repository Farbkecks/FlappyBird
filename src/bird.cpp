#include "bird.h"

Bird::Bird()
        : velocity(0), death(false), score(0) {
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

    if (position.y > (float) constants::engine::resolution.y - birdSprite.getGlobalBounds().height) {
        position.y = (float) constants::engine::resolution.y - birdSprite.getGlobalBounds().height;
    }
}

float Bird::checkVelocityBounds(float num) {
    float results;


    if (constants::bird::maxVelocity < constants::bird::minVelocity) {
        helperFunktions::print("velocity Bounds incorrect");
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
    changeYWithCurrentVelocity();
}

void Bird::changeVelocity(float num) {
    velocity = checkVelocityBounds(velocity += num);
    changeYWithCurrentVelocity();
}

void Bird::changeYWithCurrentVelocity() {
    changeY(velocity);
}

void Bird::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(birdSprite);
}

std::pair<float, float> Bird::getMinMaxY() const {
    return {
            birdSprite.getGlobalBounds().top,
            birdSprite.getGlobalBounds().top + birdSprite.getGlobalBounds().height
    };
}

sf::Vector2f Bird::getPostion() const {
    return position;

}

sf::Vector2f Bird::getSchnabelPostion() const {
    auto pos = getPostion();
    helperFunktions::addVector2f(pos, {constants::bird::birdWidth, constants::bird::birdHeight / 2});
    return pos;
}

void Bird::setDeath() {
    this->death = true;
}

bool Bird::getDeath() const {
    return death;
}


int Bird::getScore() const {
    return score;
}

void Bird::incrementScore(int score) {
    this->score += score;
}

//Bird &Bird::operator=(const Bird &other) {
//    birdSprite = other.birdSprite;
//    birdTextureIsUp = other.birdTextureIsUp;
//    position = other.position;
//    velocity = other.velocity;
//    score = other.score;
//    death = other.death;
//    return *this;
//}

void Bird::reset() {
    death = false;
    score = 0;
    position = constants::bird::startPos;
}

float Bird::getVelocity() const {
    return velocity;
}

