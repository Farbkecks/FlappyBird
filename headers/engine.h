#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

#include "constants.h"

#include "breakscene.h"
#include "gameoverscene.h"
#include "runningsceneplayer.h"

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
    RunningScenePlayer runningScenePlayer;
    BreakScene breakScene;
    GameOverScene gameOverScene;
};


