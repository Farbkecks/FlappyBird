#pragma once

#include <vector>

#include "runningscene.h"
#include "bird.h"
#include "network.h"

class RunningSceneBot : public RunningScene {
    struct BirdWithNetwork {
        Bird bird;
        Network network;
        std::vector<Sensor> sensors;
    };

public:
    //functions
    RunningSceneBot(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status);


protected:
    //functions
public:
    void deepReset() override;

protected:
    void deepUpdate() override;

    void deepDraw() override;

    void input(sf::Event event) override;

    static std::vector<Sensor> addSensors();


private:
    //variables
    std::vector<BirdWithNetwork> birds;
};
