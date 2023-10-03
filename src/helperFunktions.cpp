#include "helperFuntions.h"

float helperFunktions::randomInt(sf::Vector2f range) {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range.x, range.y);
    return distr(generator);
}

sf::Vector2f helperFunktions::addVector2f(sf::Vector2f &left, const sf::Vector2f &right) {
    left.x += right.x;
    left.y += right.y;
    return left;
}

float helperFunktions::sigmoid(float num) {
#include <cmath>

    return 1 / (1 + std::exp(-num));
}

float helperFunktions::randomFloat(const float LO, const float HI) {
    return LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
}

void helperFunktions::print(const std::vector<float> &vec) {
    int i = 0;
    for (const auto &x: vec) {
        std::cout << x << ",";
    }
    std::cout << std::endl;
}

void helperFunktions::drawHorizontalLine(const sf::Vector2f &pos, std::shared_ptr<sf::RenderWindow> window) {
    auto line = sf::RectangleShape({100, 1});
    line.setPosition(pos);
    line.setFillColor(sf::Color::Red);
    window->draw(line);
}