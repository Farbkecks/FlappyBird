#include "helperFuntions.h"

float helperFunktions::randomNum(sf::Vector2f range) {
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>    distr(range.x, range.y);
        return distr(generator);
    }