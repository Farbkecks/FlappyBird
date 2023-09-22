#pragma once

#include <SFML/Graphics.hpp>
#include "helperFuntions.h"
#include "constants.h"
#include "pipe.h"

class Sensor : public sf::Drawable {
//funktions
public:
    explicit Sensor(const sf::Vector2f &steps);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::Vector2f getHitPoint() const;

    void updateHitPoint(sf::Vector2f startPoint, const std::weak_ptr<Pipe> &pipe);
//funktions
private:


//variables
private:
    sf::Vector2f hitPoint;
    sf::Vector2f steps;

};
