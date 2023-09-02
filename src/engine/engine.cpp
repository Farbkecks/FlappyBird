#include "engine.h"

Engine::Engine(unsigned int height, unsigned int width, const sf::String &title)
        : resolution(height, width),
          window(sf::VideoMode(resolution.x, resolution.y), title) {
}

void Engine::run() {
    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        window.display();
        input();
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
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }
        }
    }
}


