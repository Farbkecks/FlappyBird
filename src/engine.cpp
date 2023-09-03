#include "engine.h"

Engine::Engine(unsigned int height, unsigned int width, const sf::String &title)
        : resolution(height, width),
          window(sf::VideoMode(resolution.y, resolution.x), title) {

    //TODO make better path
    bird.loadFromFile("assets/FlappyBird.png");
    sprite.setTexture(bird);

}

void Engine::run() {
    while (window.isOpen()) {
        window.clear(sf::Color::White);
        window.draw(sprite);
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


