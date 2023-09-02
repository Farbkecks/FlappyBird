#include <SFML/Graphics.hpp>

#include "engine.h"

int main() {
    Engine engine(500, 500, "Test");
    engine.run();

    return 0;
}