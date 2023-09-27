#include <SFML/Graphics.hpp>

#include "engine.h"
#include "network.h"

int main() {
    srand(static_cast <unsigned> (time(nullptr)));

    Engine engine;
    engine.run();


    return 0;
}