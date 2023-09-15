#include "engine.h"

void Engine::draw() {
    window.clear(sf::Color::Blue);

    window.draw(bird);
    for (auto const &pipe: pipes) {
        window.draw(*pipe);
    }
#ifdef debug
    auto x = sf::RectangleShape({1, 2000});
    x.setPosition(aktivePipeIndex->getX(), 0);
    window.draw(x);

    auto y = sf::RectangleShape({1, 2000});
    y.setPosition(aktivePipeIndex->getX() + constants::pipe::pipeWidth, 0);
    window.draw(y);
#endif

    window.display();
}

