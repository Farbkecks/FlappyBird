#pragma once

#include "pipe.h"

class GhostPipe : public Pipe {
//funktions
public:
    GhostPipe();

    GhostPipe(const sf::Vector2f &pos, float distance);

    GhostPipe(float xPostion);


    bool collisionOnY(const std::pair<float, float> &minMax) const override;

private:
    void updateTexture();
};
