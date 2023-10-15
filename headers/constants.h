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
        const std::vector<float> workingWeights = {0.218177, 0.763604, 0.187506, 0.0592364, 0.0209357, 0.49971,
                                                   0.840968, 0.181219, 0.171941, 0.749504, 0.660024, 0.232582, 0.187414,
                                                   0.91757, 0.240913, 0.680563, 0.83224, 0.749626, 0.0853908, -0.815241,
                                                   0.0523392, 0.422926, 0.982665, 0.267647, 0.242836, 0.77694, 0.143559,
                                                   0.0541704, 0.1348, 0.12949, 0.394665, 0.528062, 0.704978, 0.215766,
                                                   0.977081, 0.422071, 0.382519, 0.646779, 0.845454, 0.511368, 0.117801,
                                                   0.698019, 0.180212, 0.900632, 0.634297, 0.145573, 0.782403, 0.137974,
                                                   0.0976592, 0.109745, -0.853877, 0.24601, -0.159459, 0.894803,
                                                   0.370678, 0.357921, 0.0542924, 0.787896, 0.59096, 0.169927, 0.198859,
                                                   0.0772118, 0.248146, 0.0601215, 0.173803, 0.152501, 0.093997,
                                                   0.833461, 0.10593, 0.759636, 0.665761, 0.188208, -0.838557, 0.654744,
                                                   -0.709159, 0.0303049, -0.684683, 0.747765, 0.164342, 0.216742,
                                                   0.370464, 0.283517, 0.356822, -0.830195,};
    }

    namespace network {
        const int inputLayerCount = 6;
        const int hiddenLayerCount = 12;
        const int outputLayerCount = 1;
    }
}
