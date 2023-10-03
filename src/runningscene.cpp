#include "runningscene.h"
#include <string>

void RunningScene::update() {
    timeSinceLastUpdateCycle += timeSinceLast;
    if (timeSinceLastUpdateCycle.asSeconds() < constants::engine::updateCycle) {
        return;
    }


    //movePipe and find relevant pipe
    for (auto const &pipe: pipes) {
        pipe->changeX(constants::pipe::pipeStepPerUpdate * dirketionToInt(direktion));
        findeAktivePipe(pipe);
        findNextPipe(pipe);
    }

    //delete and generate Pipes
    if (pipes.back()->getX() > (float) constants::pipe::pipesDistance * constants::pipe::startAmountPipes) {
        pipes.pop_back();
        pipes.push_front(std::make_shared<Pipe>(-constants::pipe::pipesDistance));
    }

    if (pipes.front()->getX() < (float) -constants::pipe::pipesDistance) {
        pipes.pop_front();
        pipes.push_back(std::make_shared<Pipe>(constants::pipe::pipesDistance * constants::pipe::startAmountPipes));
    }


    deepUpdate();

    timeSinceLastUpdateCycle = sf::Time::Zero;

}

void RunningScene::draw() {
    window->clear(constants::engine::background);

    for (auto const &pipe: pipes) {
        window->draw(*pipe);
    }

    deepDraw();

    window->display();
}

void RunningScene::drawPipeDebug(std::weak_ptr<Pipe> pipe, sf::Color color) {
    if (not pipe.expired()) {
        auto x = sf::RectangleShape({1, 2000});
        x.setFillColor(color);
        x.setPosition(pipe.lock()->getX(), 0);
        window->draw(x);

        auto y = sf::RectangleShape({1, 2000});
        y.setFillColor(color);
        y.setPosition(pipe.lock()->getX() + constants::pipe::pipeWidth, 0);
        window->draw(y);
    }
}


RunningScene::RunningScene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status)
        : Scene(window, status), direktion(FORWARD) {
    addStartetPipes();
}

void RunningScene::addStartetPipes() {
    int const MID = constants::pipe::startAmountPipes / 2;
    for (int i = -1; i < constants::pipe::startAmountPipes; i++) {
        if (i == MID - 1) {
            pipes.push_back(std::make_shared<GhostPipe>((float) i * constants::pipe::pipesDistance));
        } else {
            pipes.push_back(std::make_shared<Pipe>((float) i * constants::pipe::pipesDistance));
        }
    }
}

void RunningScene::reset() {
    direktion = FORWARD;
    pipes.clear();
    addStartetPipes();
    deepReset();
}

int RunningScene::dirketionToInt(RunningScene::Direktion direktion) {
    switch (direktion) {
        case FORWARD:
            return 1;
        case BACKWARD:
            return -1;
    }
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

void RunningScene::findNextPipe(const std::shared_ptr<Pipe> &pipe) {
    if (pipe->getX() < constants::bird::startPos.x) {
        return;
    }
    if (pipe->getX() + constants::bird::birdWidth > constants::bird::startPos.x + constants::pipe::pipesDistance) {
        return;
    }
    nextPipe = pipe;
}