#include "breakscene.h"
#include "helperFuntions.h"

void BreakScene::input(sf::Event event) {
    if (event.key.code == constants::input::resumeBreak) {
        *status = constants::gameState::RUNNIING;
        drawn = false;
    }
}

void BreakScene::update() {
    sf::sleep(sf::milliseconds(2));
}

void BreakScene::draw() {
    if (not drawn && *status == constants::gameState::PAUSED) {
        drawn = true;
        window->draw(text);
        window->display();
    }
}

BreakScene::BreakScene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status) : Scene(
        window, status), drawn(false) {
    font.loadFromFile(constants::breakScene::path);
    text.setFont(font);
    text.setCharacterSize(constants::breakScene::textSize);
    text.setString(constants::breakScene::text);
    text.setFillColor(constants::breakScene::textColor);
    text.setPosition(constants::engine::resolution.x / 2 - text.getLocalBounds().getSize().x / 2,
                     constants::engine::resolution.y / 2 - text.getLocalBounds().getSize().y / 2);

}
