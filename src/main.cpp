#include <SFML/Graphics.hpp>

#include "engine.h"

int main() {
    Engine engine(720, 1280, "Test");
    engine.run();

    return 0;
}