#include "engine.h"


void Engine::update() {
    if (timeSinceLastMove.asSeconds() < constants::engine::updateCycle) {
        return;
    }

#ifdef debug
    helperFunktions::print(aktivePipeIndex->collision(bird.getMinMaxY()));
#else
    bird.changeVelocity(constants::bird::stepChangeVelocityPerUpdate);
    bird.changeYWithCurrentVelocity();
#endif

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
    timeSinceLastMove = sf::Time::Zero;

}
