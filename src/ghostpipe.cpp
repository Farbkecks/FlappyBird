#include "ghostpipe.h"

#include <utility>

bool GhostPipe::collisionOnY(const std::pair<float, float> &minMax) const {
    return false;
}


GhostPipe::GhostPipe(std::shared_ptr<constants::ResourceHolder> resourceHolder) : Pipe(std::move(resourceHolder)) {
    updateSpriteTextrue();
}

GhostPipe::GhostPipe(const sf::Vector2f &pos, float distance, std::shared_ptr<constants::ResourceHolder> resourceHolder)
        : Pipe(pos, distance, std::move(resourceHolder)) {
    updateSpriteTextrue();
}

GhostPipe::GhostPipe(const float xPostion, std::shared_ptr<constants::ResourceHolder> resourceHolder)
        : Pipe(xPostion, std::move(resourceHolder)) {
    updateSpriteTextrue();
}

void GhostPipe::updateSpriteTextrue() {
    spriteTop.setTexture(resourceHolder->pipeGhost);
    spriteBottom.setTexture(resourceHolder->pipeGhost);
    transformSpriteTextrue();
}

