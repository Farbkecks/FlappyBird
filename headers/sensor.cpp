#include "sensor.h"

Sensor::Sensor(const sf::Vector2f &steps) :
        hitPoint(0, 0), steps(steps) {

}

void Sensor::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    auto x = sf::RectangleShape({10, 10});
    x.setPosition(hitPoint);
    x.setFillColor(sf::Color::Red);
    target.draw(x);
}

void Sensor::updateHitPoint(sf::Vector2f startPoint, const std::vector<std::shared_ptr<Pipe>> &pipes) {
    auto it = begin(pipes);
    while (it != end(pipes)) {
        if ((*it)->collision(startPoint)) {
            hitPoint = startPoint;
            return;
        }
        helperFunktions::addVector2f(startPoint, steps);
        if (startPoint.x > (*it)->getX()) {
            it++;
        }
    }
}

sf::Vector2f Sensor::getHitPoint() const {
    return hitPoint;
}



