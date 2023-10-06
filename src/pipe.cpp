#include "pipe.h"

#include <utility>
#include "helperFuntions.h"

Pipe::Pipe(std::shared_ptr<constants::ResourceHolder> resourceHolder)
        : wasAktive(false), resourceHolder(std::move(resourceHolder)) {
    updateSpriteTextrue();

}

Pipe::Pipe(const sf::Vector2f &pos, float distance, std::shared_ptr<constants::ResourceHolder> resourceHolder) :
        Pipe(std::move(resourceHolder)) {
    setPostion(pos, distance);
    updateSprite();
}

Pipe::Pipe(float xPostion, std::shared_ptr<constants::ResourceHolder> resourceHolder)
        : Pipe(
        {xPostion, helperFunktions::randomInt(constants::pipe::PipeYPostionRange)},
        helperFunktions::randomInt(constants::pipe::pipeDistanceRange), std::move(resourceHolder)) {}

void Pipe::updateSpriteTextrue() {
    spriteTop.setTexture(resourceHolder->pipe);
    spriteBottom.setTexture(resourceHolder->pipe);
    transformSpriteTextrue();
}

void Pipe::transformSpriteTextrue() {
    spriteTop.setScale(constants::pipe::scale, constants::pipe::scale);
    spriteTop.setRotation(180);
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

bool Pipe::collisionOnY(const std::pair<float, float> &minMax) const {
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

bool Pipe::collisionOnY(const Bird &bird) const {
    return collisionOnY(bird.getMinMaxY());
}

bool Pipe::collision(const sf::Vector2f &pos) const {
    if (pos.x > getX() && pos.x < getX() + constants::pipe::pipeWidth) {
        return Pipe::collisionOnY({pos.y, pos.y});
    }
    return false;
}

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

void Pipe::setAktive() {
    wasAktive = true;
}

bool Pipe::getAktive() const {
    return wasAktive;
}

sf::Vector2f Pipe::getPos() const {
    return postion;
}

float Pipe::differnceGapeToBirdY(const Bird &bird) const {
    return postion.y - bird.getSchnabelPostion().y;
}

float Pipe::differnceBirdToPipeX(const Bird &bird) const {
    auto diff = getX() - bird.getSchnabelPostion().x;
    return diff > 0 ? diff : 0;
}
