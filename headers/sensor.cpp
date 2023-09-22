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

void Sensor::updateHitPoint(sf::Vector2f startPoint, const std::weak_ptr<Pipe> &pipe) {
    if (pipe.expired()) {
        helperFunktions::print("sensor wurde nullptr übergenen");
        return;
    }

    while (startPoint.x < 10000 && startPoint.x > -10000) {
        if (pipe.lock()->collision(startPoint)) {
            hitPoint = startPoint;
            return;
        }
        helperFunktions::addVector2f(startPoint, steps);
    }
}

sf::Vector2f Sensor::getHitPoint() const {
    return hitPoint;
}


