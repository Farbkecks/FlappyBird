#pragma once

#include <SFMl/Graphics.hpp>

namespace constants {
    enum class gameState {
        RUNNIINGPLAYER, RUNNINGBOT, PAUSED, GAMEOVER
    };

    struct ResourceHolder {
        sf::Texture birdUp;
        sf::Texture birdDown;
        sf::Texture pipe;
        sf::Texture pipeGhost;

        ResourceHolder();
    };

    namespace engine {
        const unsigned int fps = 144;
        const sf::String titel = "Test";
        const sf::Vector2u resolution = {1280, 720};
        const auto updateCycle = 0.01;
        const sf::Color background = sf::Color::Black;
        const auto aktiveSceneStart = constants::gameState::RUNNIINGPLAYER;
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
        const sf::Vector2f PipeYPostionRange = {300, 500};
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
        const auto aiPlay = sf::Keyboard::A;
        const auto slower = sf::Keyboard::S;
        const auto faster = sf::Keyboard::W;
        const auto botScene = sf::Keyboard::O;
        const auto playerScene = sf::Keyboard::P;
    }

    namespace text {
        const sf::String path = "assets/ArialBlack.ttf";
        const int textSize = 30;
        const auto textColor = sf::Color::Red;
        const sf::Vector2f scorePos = {20, 10};
        const sf::Vector2f isPos = {300, 10};
        const sf::String textBreak = "Jump: Space\nDirektion: Enter\nClose: Backspace\nai play: A\ndraw debug: D\nBot Scene: O\nPlayer Scene: P\n\npress space to continue";
        const sf::String textGameover = "press enter to restart";
        const sf::String textScorePrefix = "Score: ";
        const sf::String textAiPlay = "ai plays";
    }

    namespace runningSceneBot {
        //muss 9,16,25,36 sein
        const int birdAmount = 100;
        const std::vector<float> workingWeights = {0.234596, -0.790765, 0.570452, -0.0184026, 0.524461, -0.61919,
                                                   0.241462, 0.809137, 0.172826, 0.164006, 0.936216, 0.290445,
                                                   -0.692984, 0.619983, 0.660634, -0.941832, -0.798212, -0.955443,
                                                   -0.559374, 0.085696};
    }

    namespace network {
        const int inputLayerCount = 3;
        const int hiddenLayerCount = 5;
        const int outputLayerCount = 1;
    }
}
