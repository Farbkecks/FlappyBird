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


    timeSinceLastMove = sf::Time::Zero;

}
