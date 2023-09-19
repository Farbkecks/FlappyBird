#pragma once

#include "scene.h"
#include "bird.h"
#include "pipe.h"
#include "ghostpipe.h"
#include "helperFuntions.h"

#include <deque>

class RunningScene : public Scene {
//funktions
public:
    RunningScene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status);

//funktions
protected:
    void input(sf::Event event) override;

    void update() override;

    void draw() override;

//variables
private:
    Bird bird;

    sf::Time timeSinceLastBirdMove;

    std::deque<std::shared_ptr<Pipe>> pipes;

    std::shared_ptr<Pipe> aktivePipeIndex;

};
