#include "engine.h"

Engine::Engine()
        : window(std::make_shared<sf::RenderWindow>(
        sf::VideoMode(constants::engine::resolution.x, constants::engine::resolution.y),
        constants::engine::titel,
        sf::Style::Close)),
          status(std::make_shared<constants::gameState>(constants::engine::aktiveSceneStart)),
          runningScenePlayer(window, status),
          runningSceneBot(window, status),
          breakScene(window, status),
          gameOverScene(window, status) {
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
