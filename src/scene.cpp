#include "scene.h"

void Scene::run(const sf::Time &timeSinceLast) {
    using namespace sf;
    this->timeSinceLast = timeSinceLast;
    Event event{};
    while (window->pollEvent(event)) {
        // Window closed
        if (event.type == Event::Closed) {
            window->close();
        }

        // Handle Keyboard Input
        if (event.type == Event::KeyPressed) {
            // Quit
            if (event.key.code == constants::input::closeButton) {
                window->close();
            }
            input(event);
        }
    }

    update();

    draw();
}

Scene::Scene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status)
        : window(window), status(status) {}
