#include "engine.h"


void Engine::update() {
    if (timeSinceLastMove.asSeconds() < sf::seconds(.1f / 100).asSeconds()) {
        return;
    }
//    print(timeSinceLastMove.asSeconds());
    bird.goUp(7);
    timeSinceLastMove = sf::Time::Zero;

}
