#include "engine.h"

Engine::Engine(unsigned int height, unsigned int width, const sf::String &title)
        : resolution(height, width),
          window(sf::VideoMode(resolution.y, resolution.x), title) {

    //TODO make better path
    birdUp.loadFromFile("assets/FlappyBird.png", {0, 0, 255, 180});
    birdDown.loadFromFile("assets/FlappyBird.png", {255, 0, 255, 180});
//    bird.loadFromFile("assets/FlappyBird.png");
    birdSprite.setTexture(birdUp);

}

void Engine::run() {
    while (window.isOpen()) {
        window.clear(sf::Color::White);
        window.draw(birdSprite);
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
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::A) {
                birdSprite.setTexture(birdUp);
            }
            if (event.key.code == sf::Keyboard::D) {
                birdSprite.setTexture(birdDown);
            }
        }
    }
}


