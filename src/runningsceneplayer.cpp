#include "runningsceneplayer.h"

RunningScenePlayer::RunningScenePlayer(std::shared_ptr<sf::RenderWindow> window,
                                       std::shared_ptr<constants::gameState> status) :
        RunningScene(window, status), bird(window->getSize()), score(0), drawDebug(false) {
    font.loadFromFile(constants::text::path);
    scoreText.setFont(font);
    scoreText.setCharacterSize(constants::text::textSize);
    scoreText.setFillColor(constants::text::textColor);
    scoreText.setPosition(constants::text::scorePos);
    scoreText.setString(constants::text::textScorePrefix + "0");

    sensors.emplace_back(Sensor({0, 1}));
    sensors.emplace_back(Sensor({1, 2}));
    sensors.emplace_back(Sensor({1, 0}));
    sensors.emplace_back(Sensor({1, -2}));
    sensors.emplace_back(Sensor({0, -1}));
}

void RunningScenePlayer::input(sf::Event event) {
    if (event.key.code == constants::input::pauseButton) {
        *status = constants::gameState::PAUSED;
    }
    if (event.key.code == constants::input::jumpButton) {
        bird.setVelocity(constants::bird::jumpVelocity);
    }
    if (event.key.code == constants::input::drawDebug) {
        drawDebug = !drawDebug;
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

    //change Bird y
    bird.changeVelocity(constants::bird::stepChangeVelocityPerUpdate);
    bird.changeYWithCurrentVelocity();

    for (auto &sensor: sensors) {
        sensor.updateHitPoint(bird.getSchnabelPostion(), pipes);
    }

}

void RunningScenePlayer::deepDraw() {
    window->draw(bird);
    window->draw(scoreText);

    if (drawDebug) {
        drawPipeDebug(aktivePipe, sf::Color::Black);
        drawPipeDebug(nextPipe, sf::Color::Blue);
        for (auto const &sensor: sensors) {
            window->draw(sensor);
        }
    }
}

void RunningScenePlayer::deepReset() {
    score = 0;
    bird.setPosition(constants::bird::startPos);
}
