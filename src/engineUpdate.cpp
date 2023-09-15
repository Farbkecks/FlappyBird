#include "engine.h"


void Engine::update() {
    if (timeSinceLastMove.asSeconds() < constants::engine::updateCycle) {
        return;
    }

#ifdef debug
    helperFunktions::print(pipes.at(aktivePipeIndex).collision(bird.getMinMaxY()));
#else
    bird.changeVelocity(constants::bird::stepChangeVelocityPerUpdate);
    bird.changeYWithCurrentVelocity();
#endif

    for (int i = 0; i < pipes.size(); i++) {
        pipes.at(i).changeX(constants::pipe::pipeStepPerUpdate);
        if (
                pipes.at(i).getX() + constants::pipe::pipeWidth ==
                constants::bird::startPos.x
                ) {
            aktivePipeIndex = i;
        }
    }
    if (pipes.front().getX() > (float) constants::pipe::pipesDistance * (constants::pipe::startAmountPipes)) {
        pipes.pop_front();
        pipes.emplace_back(-constants::pipe::pipesDistance);
    }
    timeSinceLastMove = sf::Time::Zero;

}
