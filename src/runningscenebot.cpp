#include "runningscenebot.h"

RunningSceneBot::RunningSceneBot(std::shared_ptr<sf::RenderWindow> window,
                                 std::shared_ptr<constants::gameState> status) :
        RunningScene(window, status), bird(window->getSize()) {
    sensors.emplace_back(Sensor({4, 1}));
    sensors.emplace_back(Sensor({2, 1}));
    sensors.emplace_back(Sensor({1, 0}));
    sensors.emplace_back(Sensor({2, -1}));
    sensors.emplace_back(Sensor({4, -1}));
}

void RunningSceneBot::deepReset() {

}

void RunningSceneBot::deepUpdate() {
    std::vector<float> sensorData;
    for (auto &sen: sensors) {
        sen.updateHitPoint(bird.getSchnabelPostion(), pipes);
        sensorData.emplace_back(sen.getDistance());
    }
    helperFunktions::print(sensorData);
    if (network.calculate(sensorData)) {
        helperFunktions::print("true");
        bird.setVelocity(constants::bird::jumpVelocity);
    } else {
        helperFunktions::print("false");
    }


    bird.changeVelocity(constants::bird::stepChangeVelocityPerUpdate);
    bird.changeYWithCurrentVelocity();

}

void RunningSceneBot::deepDraw() {
    window->draw(bird);

    for (auto const &sen: sensors) {
        window->draw(sen);
    }
}

void RunningSceneBot::input(sf::Event event) {
    if (event.key.code == constants::input::pauseButton) {
        *status = constants::gameState::PAUSED;
    }
}
