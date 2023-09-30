#include "runningscenebot.h"

RunningSceneBot::RunningSceneBot(std::shared_ptr<sf::RenderWindow> window,
                                 std::shared_ptr<constants::gameState> status) :
        RunningScene(window, status) {
    for (int i = 0; i < constants::runningSceneBot::birdAmount; i++) {
        birds.emplace_back(BirdWithNetwork({
                                                   .bird = Bird(window->getSize()),
                                                   .sensors = addSensors()
                                           }));
    }
}

void RunningSceneBot::deepReset() {

}

void RunningSceneBot::deepUpdate() {
    for (auto &bird: birds) {

        std::vector<float> sensorData;
        for (auto &sen: bird.sensors) {
            sen.updateHitPoint(bird.bird.getSchnabelPostion(), pipes);
            sensorData.emplace_back(sen.getDistance());
        }

        if (bird.network.calculate(sensorData)) {
            bird.bird.setVelocity(constants::bird::jumpVelocity);
        }


        bird.bird.changeVelocity(constants::bird::stepChangeVelocityPerUpdate);
        bird.bird.changeYWithCurrentVelocity();

    }
}

void RunningSceneBot::deepDraw() {
    for (auto const &bird: birds) {
        window->draw(bird.bird);
    }
}

void RunningSceneBot::input(sf::Event event) {
    if (event.key.code == constants::input::pauseButton) {
        *status = constants::gameState::PAUSED;
    }
}

std::vector<Sensor> RunningSceneBot::addSensors() {
    std::vector<Sensor> sensors;
    sensors.emplace_back(Sensor({4, 1}));
    sensors.emplace_back(Sensor({2, 1}));
    sensors.emplace_back(Sensor({1, 0}));
    sensors.emplace_back(Sensor({2, -1}));
    sensors.emplace_back(Sensor({4, -1}));
    return sensors;
}
