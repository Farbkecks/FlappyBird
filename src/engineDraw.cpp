#include "engine.h"

void Engine::draw() {
    window.clear(sf::Color::White);

    window.draw(bird);
    for(auto const & pipe: pipes){
        window.draw(pipe);
    }
    window.display();
}

float Engine::randomNum(sf::Vector2f range) {
    return randomNum(range.x, range.y);
}
