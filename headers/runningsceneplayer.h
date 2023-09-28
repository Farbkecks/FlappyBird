#pragma once

#include "runningscene.h"

class RunningScenePlayer : public RunningScene {
//funktions
public:
    RunningScenePlayer(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status);

//funktions
protected:
    void input(sf::Event event) override;

private:
    void deepUpdate() override;

    void deepReset() override;

    void deepDraw() override;

//variables
private:

    Bird bird;

    int score;
    sf::Font font;
    sf::Text scoreText;

};
