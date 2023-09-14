#include "engine.h"


void Engine::update() {
    if (timeSinceLastMove.asSeconds() < constants::engine::updateCycle) {
        return;
    }

#ifdef debug
    print(pipe.collision(bird.getMinMaxY()));
#else
    bird.changeVelocity(constants::bird::stepChangeVelocityPerUpdate);
    bird.changeYWithCurrentVelocity();
#endif
    for(auto & pipe: pipes){
        pipe.changeX(constants::pipe::pipeStepPerUpdate);
    }
    if(pipes.front().getX() > (float) constants::pipe::pipesDistance * (constants::pipe::startAmountPipes-1)){
        pipes.pop_front();
        pipes.emplace_back((sf::Vector2f ){-constants::pipe::pipesDistance,(float) constants::engine::resolution.y/2}, 400);
    }

    timeSinceLastMove = sf::Time::Zero;

}
