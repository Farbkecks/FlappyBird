#include "ghostpipe.h"

bool GhostPipe::collision(const std::pair<float, float> &minMax) const {
    return false;
}

bool GhostPipe::collision(const Bird &bird) const {
    return false;
}

GhostPipe::GhostPipe() : Pipe() {
    updateTexture();
}

GhostPipe::GhostPipe(const sf::Vector2f &pos, float distance) : Pipe(pos, distance) {
    updateTexture();
}

GhostPipe::GhostPipe(const float xPostion) : Pipe(xPostion) {
    updateTexture();
}

void GhostPipe::updateTexture() {
    texture.loadFromFile(constants::ghostPipe::path);
    updateSpriteTextrue();
}
