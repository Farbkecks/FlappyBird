#include "runningscene.h"

void RunningScene::input(sf::Event event) {
    if (event.key.code == constants::input::pauseButton) {
        *status = constants::gameState::PAUSED;
    }
    if (event.key.code == constants::input::jumpButton) {
        bird.setVelocity(constants::bird::jumpVelocity);
    }
}

void RunningScene::update() {
    timeSinceLastBirdMove += timeSinceLast;
    if (timeSinceLastBirdMove.asSeconds() < constants::engine::updateCycle) {
        return;
    }

    bird.changeVelocity(constants::bird::stepChangeVelocityPerUpdate);
    bird.changeYWithCurrentVelocity();

    for (auto const &pipe: pipes) {
        pipe->changeX(constants::pipe::pipeStepPerUpdate);
        if (
                pipe->getX() + constants::pipe::pipeWidth == constants::bird::startPos.x ||
                pipe->getX() == constants::bird::startPos.x + constants::bird::birdWidth
                ) {
            aktivePipeIndex = pipe;
        }
    }

    if (pipes.front()->getX() > (float) constants::pipe::pipesDistance * constants::pipe::startAmountPipes) {
        pipes.pop_front();
        pipes.push_back(std::make_shared<Pipe>(-constants::pipe::pipesDistance));
    }

    if (pipes.back()->getX() < (float) -constants::pipe::pipesDistance) {
        pipes.pop_back();
        pipes.push_front(std::make_shared<Pipe>(constants::pipe::pipesDistance * constants::pipe::startAmountPipes));
    }

    helperFunktions::print(aktivePipeIndex->collision(bird));
    if (aktivePipeIndex->collision(bird)) {
        *status = constants::gameState::GAMEOVER;
    }

    timeSinceLastBirdMove = sf::Time::Zero;

}

void RunningScene::draw() {
    window->clear(sf::Color::Blue);

    window->draw(bird);
    for (auto const &pipe: pipes) {
        window->draw(*pipe);
    }

    //TODO Remove
    //Debug draw aktiv pipe
//    auto x = sf::RectangleShape({1, 2000});
//    x.setPosition(aktivePipeIndex->getX(), 0);
//    window->draw(x);
//
//    auto y = sf::RectangleShape({1, 2000});
//    y.setPosition(aktivePipeIndex->getX() + constants::pipe::pipeWidth, 0);
//    window->draw(y);

    window->display();
}

RunningScene::RunningScene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status)
        : Scene(window, status), bird(window->getSize()) {
    for (int i = -1; i < constants::pipe::startAmountPipes; i++) {
        pipes.push_front(std::make_shared<Pipe>((float) i * constants::pipe::pipesDistance));
    }
    aktivePipeIndex = pipes.back();
}
