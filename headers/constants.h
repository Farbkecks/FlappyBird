#pragma once

namespace constants {
    namespace engine {
        const unsigned int fps = 144;
        const sf::String titel = "Test";
        const sf::Vector2u resolution = {1280, 720};
        //TODO put usefully numbers
        const auto updateCycle = sf::seconds(.1f / 7.2).asSeconds();
    }
    namespace bird {
        const sf::String path = "assets/FlappyBird.png";
        const int birdWidth = 76;
        const sf::IntRect birdUpArea = {0, 0, 255, 180};
        const sf::IntRect birdDownArea = {255, 0, 255, 180};
        const sf::Vector2f startPos = {(float) engine::resolution.x / 2, 400};
        const float scale = 0.3;

        const float jumpVelocity = 15;
        const float stepChangeVelocityPerUpdate = -1;
        const float maxVelocity = 20;
        const float minVelocity = -13;
    }

    namespace pipe {
        const sf::String path = "assets/pipe.png";
        const int pipeWidth = 80;
        const float scale = 0.5;
        const int startAmountPipes = 6;
        const int pipesDistance = 300;
        const float pipeStepPerUpdate = -1;
        const sf::Vector2f pipeDistanceRange = {200, 400};
        const sf::Vector2f PipeYPostionRange = {300, 600};
    }

    namespace input {
        const auto closeButton = sf::Keyboard::Escape;
        const auto jumpButton = sf::Keyboard::Space;
    }
}
