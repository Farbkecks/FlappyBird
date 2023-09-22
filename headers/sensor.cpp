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

void Sensor::updateHitPoint(sf::Vector2f startPoint, const std::deque<std::shared_ptr<Pipe>> &pipes) {
#include <vector>

    auto it = begin(pipes);

    std::vector<sf::Vector2f> postions;

    while (it != end(pipes)) {
        if (startPoint.x > (*it)->getX()) {
            it++;
        }
        if ((*it)->collision(startPoint)) {
            postions.emplace_back(startPoint);
        }
        helperFunktions::addVector2f(startPoint, steps);
    }
    if (not postions.empty()) {
        hitPoint = postions.at(0);
    }
}

sf::Vector2f Sensor::getHitPoint() const {
    return hitPoint;
}


