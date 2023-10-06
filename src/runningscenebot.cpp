#include "runningscenebot.h"

RunningSceneBot::RunningSceneBot(std::shared_ptr<sf::RenderWindow> window,
                                 std::shared_ptr<constants::gameState> status,
                                 std::shared_ptr<constants::ResourceHolder> resourceHolder) :
        RunningScene(window, status, resourceHolder), death(0) {
    addBirdWithNetworkVector();
}

void RunningSceneBot::addBirdWithNetworkVector() {
    for (int i = 0; i < constants::runningSceneBot::birdAmount; i++) {
        birdsWithNetwork.emplace_back(resourceHolder);
    }
}

void RunningSceneBot::deepReset() {
    std::sort(birdsWithNetwork.begin(), birdsWithNetwork.end());
    auto it = birdsWithNetwork.end();
    std::vector<Network> best;
    for (int i = 0; i < sqrt(constants::runningSceneBot::birdAmount); i++) {
        best.emplace_back((--it)->network);
    }

    //Debug
    std::vector<float> weights;
    for (auto &x: best.front()) {
        weights.emplace_back(x);
    }
    helperFunktions::print(weights);
    helperFunktions::print("\n\n");

    death = 0;
    int index = 0;
    //TODO den scheiß const iterator for network schreiben
    for (auto &network1: best) {
        for (auto &network2: best) {
            birdsWithNetwork.at(index++).network = Network(network1, network2);
        }
    }
    for (auto &bird: birdsWithNetwork) {
        bird.bird.reset();
    }
}

void RunningSceneBot::deepUpdate() {
    for (auto &bird: birdsWithNetwork) {
        if (bird.bird.getDeath()) {
            continue;
        }
        bird.bird.incrementScore(1);

        float differnceGape = nextPipe.expired() ? 0 : nextPipe.lock()->differnceGapeToBirdY(bird.bird);
        float differnceX = nextPipe.expired() ? 0 : nextPipe.lock()->differnceBirdToPipeX(bird.bird);
        if (bird.network.calculate(differnceGape, bird.bird.getVelocity(), differnceX)) {
            bird.bird.setVelocity(constants::bird::jumpVelocity);
        }


        bird.bird.changeVelocity(constants::bird::stepChangeVelocityPerUpdate);

        if (not aktivePipe.expired() && aktivePipe.lock()->collisionOnY(bird.bird)) {
            bird.bird.setDeath();
            death++;
        }
    }
    if (death >= constants::runningSceneBot::birdAmount) {
        reset();
    }
}

void RunningSceneBot::deepDraw() {
    for (auto const &bird: birdsWithNetwork) {
        if (not bird.bird.getDeath()) {
            window->draw(bird.bird);
        }
    }
}

void RunningSceneBot::deepInput(sf::Event event) {
    if (event.key.code == constants::input::pauseButton) {
        *status = constants::gameState::PAUSED;
    }
}

std::vector<Sensor> RunningSceneBot::addSensors() {
    std::vector<Sensor> sensors;
    sensors.emplace_back(Sensor({0, 1}));
    sensors.emplace_back(Sensor({1, 2}));
    sensors.emplace_back(Sensor({1, 0}));
    sensors.emplace_back(Sensor({1, -2}));
    sensors.emplace_back(Sensor({0, -1}));
    return sensors;
}

bool RunningSceneBot::BirdWithNetwork::operator<(const RunningSceneBot::BirdWithNetwork &rhs) const {
    return bird.getScore() < rhs.bird.getScore();
}

RunningSceneBot::BirdWithNetwork::BirdWithNetwork(std::shared_ptr<constants::ResourceHolder> resourceHolder)
        : bird(resourceHolder) {

}

