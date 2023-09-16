#pragma once

//#define debug

#include <SFML/Graphics.hpp>
#include "bird.h"
#include "pipe.h"
#include "helperFuntions.h"
#include <deque>

#include <memory>

#include "constants.h"

class Engine {

    enum class gameState {
        RUNNIING, PAUSED, GAMEOVER
    };
public:
    //functions
    Engine();

    void input();

    void update();

    void draw();

    void run();

    void pause();

private:
    //functions

private:
    //variables
    sf::RenderWindow window;

    Bird bird;

    sf::Time timeSinceLastMove;

    std::deque<std::shared_ptr<Pipe>> pipes;

    std::shared_ptr<Pipe> aktivePipeIndex;

    gameState status;
};


