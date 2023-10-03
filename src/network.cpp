#include "network.h"

Network::Network(const v3Float &weights)
        : weights(weights) {
}

Network::Network() {
    weights = emptyWeights();
    for (auto &i: *this) {
        i = helperFunktions::randomFloat(-1, 1);
    }
}

//TODO const iteraotr implementieren
//eigentlic müssten lhs und rhs const sein aber keine Lust einen const iteraotr zu schreiben
Network::Network(Network &lhs, Network &rhs) {
    weights = emptyWeights();

    auto lhsit = std::begin(lhs);
    auto rhsit = std::begin(rhs);
    for (auto &i: *this) {
        auto percentage = helperFunktions::randomFloat(0, 1);
        if (percentage < 0.1) {
            i = helperFunktions::randomFloat(-1, 1);
        } else if (percentage >= 0.1 && percentage < 0.55) {
            i = *lhsit;
        } else if (percentage >= 0.55) {
            i = *rhsit;
        }
        lhsit++;
        rhsit++;
    }

    if (lhsit != std::end(lhs) || rhsit != std::end(rhs)) {
        helperFunktions::print("Network mutation constructor iterator wrong");
        std::exit(1);
    }
}

Network::v3Float Network::getWeights() const {
    return weights;
}

bool Network::calculate(float difernceToGape, float velocity) const {
    v1Float inputs = {difernceToGape, velocity};
    std::vector<float> hiddenlayer(5);
    for (int i = 0; i < hiddenlayer.size(); i++) {
        hiddenlayer.at(i) = calculateNote(weights.at(0).at(i), inputs);
    }

    v1Float outLayer(1);
    for (int i = 0; i < outLayer.size(); i++) {
        outLayer.at(i) = calculateNote(weights.at(1).at(i), hiddenlayer);
    }

    return outLayer.at(0) > 0.5;
}

float Network::calculateNote(const Network::v1Float &weight, const Network::v1Float &input) {
    if (weight.size() != input.size()) {
        helperFunktions::print("Network calculateNote wrong input size");
        std::exit(1);
    }
    float note = 0;
    for (int i = 0; i < weight.size(); i++) {
        note += weight.at(i) * input.at(i);
    }
    return helperFunktions::sigmoid(note);
}

Network::v3Float Network::emptyWeights() {
    return {
            {5, std::vector<float>(2)},
            {1, std::vector<float>(5)}
    };;
}

Network::Iterator Network::Iterator::operator++(int) {
    auto temp(*this);
    ++(*this);
    return temp;
}

Network::Iterator &Network::Iterator::operator++() {
    coord.y++;
    if (weight.at(coord.layer).at(coord.note).size() == coord.y) {
        coord.y = 0;
        coord.note++;
    }
    if (weight.at(coord.layer).size() == coord.note) {
        coord.note = 0;
        coord.layer++;
    }
    return *this;
}

bool Network::Iterator::Coord::operator==(const Network::Iterator::Coord &rhs) const {
    return layer == rhs.layer && note == rhs.note && y == rhs.y;
}

bool Network::Iterator::Coord::operator!=(const Network::Iterator::Coord &rhs) const {
    return layer != rhs.layer || note != rhs.note || y != rhs.y;
}

float &Network::Iterator::operator*() const {
    return weight.at(coord.layer).at(coord.note).at(coord.y);
}