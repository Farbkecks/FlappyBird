#include "engine.h"

Engine::Engine()
        : window(
        sf::VideoMode(constants::engine::resolution.x, constants::engine::resolution.y),
        constants::engine::titel,
        sf::Style::Close),
          bird(window.getSize()){
    window.setFramerateLimit(constants::engine::fps);
    for(int i=-1; i<constants::pipe::startAmountPipes; i++){
        sf::Vector2f pos = {(float)i*constants::pipe::pipesDistance,(float) constants::engine::resolution.y/2};
        pipes.emplace_front(pos, 400);
    }
}

void Engine::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        timeSinceLastMove += clock.restart();
        input();
        update();
        draw();
    }
}


void Engine::input() {
    using namespace sf;
    Event event{};

    while (window.pollEvent(event)) {
        // Window closed
        if (event.type == Event::Closed) {
            window.close();
        }

        // Handle Keyboard Input
        if (event.type == Event::KeyPressed) {
            // Quit
            if (event.key.code == constants::input::closeButton) {
                window.close();
            }
#ifdef debug
            if (event.key.code == sf::Keyboard::W) {
                bird.changeY(10);
            }
            if (event.key.code == sf::Keyboard::S) {
                bird.changeY(-10);
            }
#else
            if (event.key.code == constants::input::jumpButton) {
                bird.setVelocity(constants::bird::jumpVelocity);
            }
#endif
        }
    }
}