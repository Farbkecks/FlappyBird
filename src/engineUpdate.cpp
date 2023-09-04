#include "engine.h"


void Engine::update() {
    if (timeSinceLastMove.asSeconds() < constants::engine::updateCycle) {
        return;
    }
    bird.changeVelocity(constants::bird::stepChangeVelocityPerUpdate);
    bird.change();
    pipe.setPostion({200, 400}, 200);
    timeSinceLastMove = sf::Time::Zero;

}
