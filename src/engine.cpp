#include "engine.h"

Engine::Engine()
        : window(std::make_shared<sf::RenderWindow>(
        sf::VideoMode(constants::engine::resolution.x, constants::engine::resolution.y),
        constants::engine::titel,
        sf::Style::Close)),
          status(std::make_shared<constants::gameState>(constants::engine::aktiveSceneStart)),
          resourceHolder(std::make_shared<constants::ResourceHolder>()),
          runningScenePlayer(window, status, resourceHolder),
          runningSceneBot(window, status, resourceHolder),
          breakScene(window, status, resourceHolder),
          gameOverScene(window, status, resourceHolder) {
    window->setFramerateLimit(constants::engine::fps);

}

void Engine::run() {
    sf::Clock clock;
    while (window->isOpen()) {
        auto timeSinceLastMove = clock.restart();
        switch (*status) {
            case constants::gameState::RUNNIINGPLAYER:
                runningScenePlayer.run(timeSinceLastMove);
                break;
            case constants::gameState::RUNNINGBOT:
                runningSceneBot.run(timeSinceLastMove);
                break;
            case constants::gameState::PAUSED:
                breakScene.run(timeSinceLastMove);
                break;
            case constants::gameState::GAMEOVER: {
                runningScenePlayer.reset();
                gameOverScene.run(timeSinceLastMove);
                break;
            }
        }
    }
}
