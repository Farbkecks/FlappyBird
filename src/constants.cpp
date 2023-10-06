#include "constants.h"

constants::ResourceHolder::ResourceHolder() {
    birdUp.loadFromFile(constants::bird::path, constants::bird::birdUpArea);
    birdDown.loadFromFile(constants::bird::path, constants::bird::birdDownArea);
}