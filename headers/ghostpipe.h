#pragma once

#include "pipe.h"

class GhostPipe : public Pipe {
//funktions
public:
    GhostPipe(std::shared_ptr<constants::ResourceHolder> resourceHolder);

    GhostPipe(const sf::Vector2f &pos, float distance, std::shared_ptr<constants::ResourceHolder> resourceHolder);

    GhostPipe(float xPostion, std::shared_ptr<constants::ResourceHolder> resourceHolder);


    bool collisionOnY(const std::pair<float, float> &minMax) const override;

private:
    void updateSpriteTextrue() override;
};
