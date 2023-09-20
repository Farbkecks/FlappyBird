#pragma once

#include "scene.h"
#include "bird.h"
#include "pipe.h"
#include "ghostpipe.h"
#include "helperFuntions.h"

#include <deque>

class RunningScene : public Scene {

    enum Direktion {
        FORWARD, BACKWARD
    };
//funktions
public:
    RunningScene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status);

    void reset();

//funktions
protected:
    void input(sf::Event event) override;

    void update() override;

    void draw() override;

private:
    void addStartetPipes();

    static int dirketionToInt(Direktion direktion);

//variables
private:

    Bird bird;

    sf::Time timeSinceLastBirdMove;

    std::deque<std::shared_ptr<Pipe>> pipes;

    std::shared_ptr<Pipe> aktivePipeIndex;

    Direktion direktion;

    void findeAktivePipe(const std::shared_ptr<Pipe> &pipe);
};
