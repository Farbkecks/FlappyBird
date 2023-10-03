#pragma once

#include "runningscene.h"
#include "network.h"

class RunningScenePlayer : public RunningScene {
//funktions
public:
    RunningScenePlayer(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status);

//funktions
protected:
    void deepInput(sf::Event event) override;

private:
    void deepUpdate() override;

    void deepReset() override;

    void deepDraw() override;

    void drawGapeDiffernce();

//variables
private:

    Bird bird;
    bool drawDebug;
    bool aiPlay;
    int score;
    sf::Font font;
    sf::Text scoreText;
    sf::Text aiPlayText;

    std::vector<Sensor> sensors;
};
