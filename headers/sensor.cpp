#include "sensor.h"

Sensor::Sensor(const sf::Vector2f &steps) :
        hitPoint(0, 0), steps(steps), stepsToDraw(steps) {
    if (stepsToDraw.x == 0) {
        stepsToDraw.x = 1;
    }
    if (stepsToDraw.y == 0) {
        stepsToDraw.y = 1;
    }
}

void Sensor::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    auto addLine = [&](const sf::Vector2f &pos) {
        auto x = sf::RectangleShape(this->stepsToDraw);
        x.setPosition(pos);
        x.setFillColor(sf::Color::Red);
        target.draw(x);
    };

    sf::Vector2f point = startPoint;
    while (point != hitPoint) {
        addLine(point);
        helperFunktions::addVector2f(point, steps);

    }
}

void Sensor::updateHitPoint(sf::Vector2f point, const std::vector<std::shared_ptr<Pipe>> &pipes) {
    this->startPoint = point;
    this->hitPoint = point;
    auto it = begin(pipes);
    while (it != end(pipes)) {
        if ((*it)->collision(point)) {
            if (point.x >= constants::engine::resolution.x ||
                point.x < 0 ||
                point.y >= constants::engine::resolution.y ||
                point.y < 0) {
                this->hitPoint = this->startPoint;
            } else {

                this->hitPoint = point;
            }
            return;
        }
        helperFunktions::addVector2f(point, steps);
        if (point.x > (*it)->getX()) {
            it++;
        }
    }
}

sf::Vector2f Sensor::getHitPoint() const {
    return hitPoint;
}



