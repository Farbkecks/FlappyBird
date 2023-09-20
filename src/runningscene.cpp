#include "runningscene.h"

void RunningScene::input(sf::Event event) {
    if (event.key.code == constants::input::pauseButton) {
        *status = constants::gameState::PAUSED;
    }
    if (event.key.code == constants::input::jumpButton) {
        bird.setVelocity(constants::bird::jumpVelocity);
    }
    if (event.key.code == constants::input::changeDirection) {
        if (direktion == FORWARD) {
            direktion = BACKWARD;
        } else if (direktion == BACKWARD) {
            direktion = FORWARD;
        }
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
        pipe->changeX(constants::pipe::pipeStepPerUpdate * dirketionToInt(direktion));
        findeAktivePipe(pipe);
    }

    if (pipes.front()->getX() > (float) constants::pipe::pipesDistance * constants::pipe::startAmountPipes) {
        pipes.pop_front();
        pipes.push_back(std::make_shared<Pipe>(-constants::pipe::pipesDistance));
    }

    if (pipes.back()->getX() < (float) -constants::pipe::pipesDistance) {
        pipes.pop_back();
        pipes.push_front(std::make_shared<Pipe>(constants::pipe::pipesDistance * constants::pipe::startAmountPipes));
    }

    if (not aktivePipe.expired() && aktivePipe.lock()->collision(bird)) {
        *status = constants::gameState::GAMEOVER;
    }

    timeSinceLastBirdMove = sf::Time::Zero;

}

void RunningScene::findeAktivePipe(const std::shared_ptr<Pipe> &pipe) {
    if (pipe->getX() + constants::pipe::pipeWidth == constants::bird::startPos.x) {
        switch (direktion) {
            case FORWARD:
                aktivePipe.reset();
                break;
            case BACKWARD:
                aktivePipe = pipe;
                break;
        }
    } else if (pipe->getX() == constants::bird::startPos.x + constants::bird::birdWidth) {
        switch (direktion) {
            case FORWARD:
                aktivePipe = pipe;
                break;
            case BACKWARD:
                aktivePipe.reset();
                break;
        }
    }

}


void RunningScene::draw() {
    window->clear(sf::Color::Blue);

    window->draw(bird);
    for (auto const &pipe: pipes) {
        window->draw(*pipe);
    }

    //TODO Remove
    //Debug draw aktiv pipe
    if (not aktivePipe.expired()) {
        auto x = sf::RectangleShape({1, 2000});
        x.setPosition(aktivePipe.lock()->getX(), 0);
        window->draw(x);

        auto y = sf::RectangleShape({1, 2000});
        y.setPosition(aktivePipe.lock()->getX() + constants::pipe::pipeWidth, 0);
        window->draw(y);
    }

    window->display();
}

RunningScene::RunningScene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status)
        : Scene(window, status), bird(window->getSize()), direktion(FORWARD) {
    addStartetPipes();
}

void RunningScene::addStartetPipes() {
    for (int i = -1; i < constants::pipe::startAmountPipes; i++) {
        pipes.push_front(std::__1::make_shared<GhostPipe>((float) i * constants::pipe::pipesDistance));
    }
}

void RunningScene::reset() {
    direktion = FORWARD;
    bird.setPosition(constants::bird::startPos);
    pipes.clear();
    addStartetPipes();
}

int RunningScene::dirketionToInt(RunningScene::Direktion direktion) {
    switch (direktion) {
        case FORWARD:
            return 1;
        case BACKWARD:
            return -1;
    }
}
