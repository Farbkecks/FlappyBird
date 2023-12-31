#include "gameoverscene.h"
#include "helperFuntions.h"

void GameOverScene::input(sf::Event event) {
    if (event.key.code == constants::input::restartButton) {
        *status = constants::gameState::RUNNIING;
        drawn = false;
    }
}

void GameOverScene::update() {
    sf::sleep(sf::milliseconds(2));
}

void GameOverScene::draw() {
    if (not drawn && *status == constants::gameState::GAMEOVER) {
        drawn = true;
        window->draw(text);
        window->display();
    }
}

GameOverScene::GameOverScene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status)
        : Scene(
        window, status), drawn(false) {
    font.loadFromFile(constants::text::path);
    text.setFont(font);
    text.setCharacterSize(constants::text::textSize);
    text.setString(constants::text::textGameover);
    text.setFillColor(constants::text::textColor);
    text.setPosition(constants::engine::resolution.x / 2 - text.getLocalBounds().getSize().x / 2,
                     constants::engine::resolution.y / 2 - text.getLocalBounds().getSize().y / 2);

}
