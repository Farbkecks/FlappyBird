#pragma once

#include <SFML/Graphics.hpp>
#include "helperFuntions.h"
#include "constants.h"
#include "pipe.h"
#include <deque>
#include <vector>
#include <memory>

class Sensor : public sf::Drawable {
//funktions
public:
    explicit Sensor(const sf::Vector2f &steps);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::Vector2f getHitPoint() const;

    void updateHitPoint(sf::Vector2f point, std::deque<std::shared_ptr<Pipe>> pipes);

    float getDistance() const;

//funktions
private:


//variables
private:
    sf::Vector2f hitPoint;
    sf::Vector2f steps;
    sf::Vector2f stepsToDraw;
    sf::Vector2f startPoint;

};
