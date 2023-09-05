#include "engine.h"

Engine::Engine()
        : window(
        sf::VideoMode(constants::engine::resolution.y, constants::engine::resolution.x),
        constants::engine::titel,
        sf::Style::Close),
          bird(window.getSize()) {
    window.setFramerateLimit(constants::engine::fps);
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
            if (event.key.code == constants::input::jumpButton) {
                bird.setVelocity(constants::bird::jumpVelocity);
            }
        }
    }
}


