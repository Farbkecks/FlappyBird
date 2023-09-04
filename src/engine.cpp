#include "engine.h"

Engine::Engine(unsigned int height, unsigned int width, const sf::String &title)
        : resolution(height, width),
          window(sf::VideoMode(resolution.y, resolution.x), title, sf::Style::Close),
          bird({200, 400}, "assets/FlappyBird.png", window.getSize()),
          pipe("assets/pipe.png") {
    window.setFramerateLimit(144);
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
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::Space) {
                bird.setVelocity(15);
            }
        }
    }
}


