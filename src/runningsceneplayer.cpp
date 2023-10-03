#include "runningsceneplayer.h"

RunningScenePlayer::RunningScenePlayer(std::shared_ptr<sf::RenderWindow> window,
                                       std::shared_ptr<constants::gameState> status) :
        RunningScene(window, status), bird(), score(0), drawDebug(false), aiPlay(false) {
    font.loadFromFile(constants::text::path);
    scoreText.setFont(font);
    scoreText.setCharacterSize(constants::text::textSize);
    scoreText.setFillColor(constants::text::textColor);
    scoreText.setPosition(constants::text::scorePos);
    scoreText.setString(constants::text::textScorePrefix + "0");

    aiPlayText.setFont(font);
    aiPlayText.setCharacterSize(constants::text::textSize);
    aiPlayText.setFillColor(constants::text::textColor);
    aiPlayText.setPosition(constants::text::isPos);
    aiPlayText.setString(constants::text::textAiPlay);


    sensors.emplace_back(Sensor({0, 1}));
    sensors.emplace_back(Sensor({1, 2}));
    sensors.emplace_back(Sensor({1, 0}));
    sensors.emplace_back(Sensor({1, -2}));
    sensors.emplace_back(Sensor({0, -1}));
}

void RunningScenePlayer::deepInput(sf::Event event) {
    if (event.key.code == constants::input::pauseButton) {
        *status = constants::gameState::PAUSED;
    }
    if (event.key.code == constants::input::jumpButton) {
        bird.setVelocity(constants::bird::jumpVelocity);
    }
    if (event.key.code == constants::input::drawDebug) {
        drawDebug = !drawDebug;
    }
    if (event.key.code == constants::input::aiPlay) {
        aiPlay = !aiPlay;
    }
    if (event.key.code == constants::input::changeDirection) {
        if (direktion == FORWARD) {
            direktion = BACKWARD;
        } else if (direktion == BACKWARD) {
            direktion = FORWARD;
        }
    }
}

void RunningScenePlayer::deepUpdate() {
    //update score
    if (not aktivePipe.expired() && not aktivePipe.lock()->getAktive()) {
        score++;
        scoreText.setString(constants::text::textScorePrefix + std::to_string(score));
        aktivePipe.lock()->setAktive();
    }

    //check for gameover
    if (not aktivePipe.expired() && aktivePipe.lock()->collisionOnY(bird)) {
        *status = constants::gameState::GAMEOVER;
    }

    //do Jump with neural Network
    if (not nextPipe.expired() && aiPlay) {
        Network network(constants::runningSceneBot::workingWeights);
        if (network.calculate(nextPipe.lock()->heightDiffernceGapeToBird(bird), bird.getVelocity())) {
            bird.setVelocity(constants::bird::jumpVelocity);
        }
    }

    //change Bird y
    bird.changeVelocity(constants::bird::stepChangeVelocityPerUpdate);

    //update Sensorhitpoint
    for (auto &sensor: sensors) {
        sensor.updateHitPoint(bird.getSchnabelPostion(), pipes);
    }
    if (not nextPipe.expired()) {

        helperFunktions::print(nextPipe.lock()->differnceBirdToPipeX(bird));
    }

}

void RunningScenePlayer::deepDraw() {
    window->draw(bird);
    window->draw(scoreText);

    if (aiPlay) {
        window->draw(aiPlayText);
    }

    if (drawDebug) {
        drawPipeDebug(nextPipe, sf::Color::Blue);
        drawPipeDebug(aktivePipe, sf::Color::Red);
        for (auto const &sensor: sensors) {
            window->draw(sensor);
        }
        drawGapeDiffernce();
    }
}

void RunningScenePlayer::deepReset() {
    score = 0;
    bird.setPosition(constants::bird::startPos);
}

void RunningScenePlayer::drawGapeDiffernce() {
    if (nextPipe.expired()) {
        return;
    }
    auto line = sf::RectangleShape({3, nextPipe.lock()->heightDiffernceGapeToBird(bird)});
    line.setFillColor(sf::Color::Green);
    line.setPosition({nextPipe.lock()->getPos().x, bird.getSchnabelPostion().y});
    line.setPosition(bird.getSchnabelPostion());
    window->draw(line);
}
