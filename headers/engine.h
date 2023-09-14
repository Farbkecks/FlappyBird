#pragma once

//#define debug

#include <SFML/Graphics.hpp>
#include "bird.h"
#include "pipe.h"
#include "print.h"
#include <deque>
#include <random>

#include "constants.h"

class Engine {
public:
    //functions
    Engine();

    void input();

    void update();

    void draw();

    void run();

    template<typename T>
    static T randomNum(T bottom, T top);

    static float randomNum(sf::Vector2f range);


private:
    //functions

private:
    //variables
    sf::RenderWindow window;

    Bird bird;

    sf::Time timeSinceLastMove;

    std::deque<Pipe> pipes;
};

template<typename T>
T Engine::randomNum(T bottom, T top) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(bottom, top);
    return distr(generator);
}
