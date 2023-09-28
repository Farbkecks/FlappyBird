#pragma once

#include "scene.h"
#include "bird.h"
#include "pipe.h"
#include "ghostpipe.h"
#include "helperFuntions.h"
#include "sensor.h"
#include <deque>

class RunningScene : public Scene {
protected:
    enum Direktion {
        FORWARD, BACKWARD
    };
//funktions
public:
    RunningScene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status);

    void reset();

    virtual void deepReset() = 0;

//funktions
protected:

    void update() override;

    virtual void deepUpdate() = 0;

    void draw() override;

    virtual void deepDraw() = 0;

    void addStartetPipes();

    static int dirketionToInt(Direktion direktion);

    void findeAktivePipe(const std::shared_ptr<Pipe> &pipe);

    void drawPipeDebug(std::weak_ptr<Pipe> pipe, sf::Color color);

//variables
protected:
    sf::Time timeSinceLastUpdateCycle;
    std::deque<std::shared_ptr<Pipe>> pipes;
    std::weak_ptr<Pipe> aktivePipe;

    Direktion direktion;


};
