#include "engine.h"


void Engine::update() {
    //TODO put usefully numbers
    if (timeSinceLastMove.asSeconds() < sf::seconds(.1f / 7.2).asSeconds()) {
        return;
    }
    bird.changeVelocity(-1);
    bird.change();
    timeSinceLastMove = sf::Time::Zero;

}
