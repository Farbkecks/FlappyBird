#include "engine.h"

#include <iostream>

void Engine::draw() {
    window.clear(sf::Color::White);

    window.draw(bird);
    window.display();
}
