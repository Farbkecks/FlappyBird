#include "ghostpipe.h"

bool GhostPipe::collisionOnY(const std::pair<float, float> &minMax) const {
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
