#pragma once

namespace constants {
    enum class gameState {
        RUNNIINGPLAYER, RUNNINGBOT, PAUSED, GAMEOVER
    };

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
        const int birdHeight = 54;
        const sf::IntRect birdUpArea = {0, 0, 255, 180};
        const sf::IntRect birdDownArea = {255, 0, 255, 180};
        const sf::Vector2f startPos = {(float) engine::resolution.x / 2, 400};
        const float scale = 0.3;

        const float jumpVelocity = 12;
        const float stepChangeVelocityPerUpdate = -1;
        const float maxVelocity = 20;
        const float minVelocity = -10;
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
    namespace ghostPipe {
        const sf::String path = "assets/pipeGhost.png";
    }

    namespace input {
        const auto closeButton = sf::Keyboard::BackSpace;
        const auto jumpButton = sf::Keyboard::Space;
        const auto pauseButton = sf::Keyboard::Escape;
        const auto resumeBreak = sf::Keyboard::Space;
        const auto restartButton = sf::Keyboard::Enter;
        const auto changeDirection = sf::Keyboard::Enter;
        const auto drawDebug = sf::Keyboard::D;
    }

    namespace text {
        const sf::String path = "assets/ArialBlack.ttf";
        const int textSize = 30;
        const auto textColor = sf::Color::Red;
        const sf::Vector2f scorePos = {20, 10};
        const sf::String textBreak = "Jump: Space\nDirektion: Enter\nClose: Backspace\n\npress space to continue";
        const sf::String textGameover = "press enter to restart";
        const sf::String textScorePrefix = "Score: ";
    }
}
