#pragma once

//#define debug

#include <SFML/Graphics.hpp>
#include "bird.h"
#include "pipe.h"
#include "print.h"
#include <deque>

#include "constants.h"

class Engine {
public:
    //functions
    Engine();

    void input();

    void update();

    void draw();

    void run();

private:
    //functions

private:
    //variables
    sf::RenderWindow window;

    Bird bird;

    sf::Time timeSinceLastMove;

    std::deque<Pipe> pipes;
};
