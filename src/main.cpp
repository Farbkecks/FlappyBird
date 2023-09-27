#include <SFML/Graphics.hpp>

#include "engine.h"
#include "network.h"

int main() {
    srand(static_cast <unsigned> (time(nullptr)));

//    Engine engine;
//    engine.run();

    Network net;
    helperFunktions::print(net.calculate({0.4, 0.1, 0.6, 0.4, 0.9}));


    return 0;
}