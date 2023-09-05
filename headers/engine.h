#pragma once

//#define debug

#include <SFML/Graphics.hpp>
#include "bird.h"
#include "pipe.h"
#include "print.h"

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

    Pipe pipe;

    sf::Time timeSinceLastMove;
};
