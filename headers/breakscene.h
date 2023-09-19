#pragma once

#include "scene.h"

class BreakScene : public Scene {
//funktions
public:
    BreakScene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status);

//funktions
protected:
    void input(sf::Event event) override;

    void update() override;

    void draw() override;

//variables
private:
    sf::Font font;
    sf::Text text;
    bool drawn;
};
