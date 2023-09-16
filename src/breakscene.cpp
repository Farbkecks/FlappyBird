#include "breakscene.h"

void BreakScene::input(sf::Event event) {
    if (event.key.code == constants::input::resumeBreak) {
        *status = constants::gameState::RUNNIING;
    }
}

void BreakScene::update() {
    sf::sleep(sf::milliseconds(2));
}

void BreakScene::draw() {

}

BreakScene::BreakScene(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<constants::gameState> status) : Scene(
        window, status) {

}
