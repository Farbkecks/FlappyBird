#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

#include "constants.h"

#include "runningscene.h"
#include "breakscene.h"

class Engine {

public:
    //functions
    Engine();

    void run();


private:
    //functions

private:
    //variables
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<constants::gameState> status;
    RunningScene runningScene;
    BreakScene breakScene;
};


