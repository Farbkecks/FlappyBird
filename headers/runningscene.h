#pragma once

#include "scene.h"
#include "bird.h"
#include "pipe.h"
#include "ghostpipe.h"
#include "helperFuntions.h"
#include "sensor.h"
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

    void findeAktivePipe(const std::shared_ptr<Pipe> &pipe);

    void findNextPipe(const std::shared_ptr<Pipe> &pipe);

    void findLastPipe(const std::shared_ptr<Pipe> &pipe);

    void drawPipeDebug(std::weak_ptr<Pipe> pipe, sf::Color color);

//variables
private:

    Bird bird;

    sf::Time timeSinceLastBirdMove;

    std::deque<std::shared_ptr<Pipe>> pipes;
    std::weak_ptr<Pipe> aktivePipe;
    std::weak_ptr<Pipe> nextPipe;
    std::weak_ptr<Pipe> lastPipe;

    Direktion direktion;

    std::vector<Sensor> sensoren;

    int score;
    sf::Font font;
    sf::Text scoreText;
};
