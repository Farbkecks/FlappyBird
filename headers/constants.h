#pragma once

namespace constants {
    namespace bird {
        const sf::String path = "assets/FlappyBird.png";
        const sf::IntRect birdUpArea = {0, 0, 255, 180};
        const sf::IntRect birdDownArea = {255, 0, 255, 180};
        const sf::Vector2f startPos = {200, 400};
        const float scale = 0.3;

        const float jumpVelocity = 15;
        const float stepChangeVelocityPerUpdate = -1;
        const float maxVelocity = 20;
        const float minVelocity = -13;
    }
    namespace pipe {
        const sf::String path = "assets/pipe.png";
        const float scale = 0.5;
    }

    namespace engine {
        const unsigned int fps = 144;
        const sf::String titel = "Test";
        const sf::Vector2u resolution = {720, 1280};
        //TODO put usefully numbers
        const auto updateCycle = sf::seconds(.1f / 7.2).asSeconds();
    }
}
