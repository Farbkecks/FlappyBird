#include "gameoverscene.h"
#include "helperFuntions.h"

void GameOverScene::input(sf::Event event) {
    if (event.key.code == constants::input::resumeBreak) {
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
    font.loadFromFile(constants::breakAndGameoverScene::path);
    text.setFont(font);
    text.setCharacterSize(constants::breakAndGameoverScene::textSize);
    text.setString(constants::breakAndGameoverScene::textGameover);
    text.setFillColor(constants::breakAndGameoverScene::textColor);
    text.setPosition(constants::engine::resolution.x / 2 - text.getLocalBounds().getSize().x / 2,
                     constants::engine::resolution.y / 2 - text.getLocalBounds().getSize().y / 2);

}
