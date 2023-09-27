#include "network.h"

Network::Network(const v3Float &weights)
        : weights(weights) {
}

Network::Network() {
    weights = {
            {5, std::vector<float>(5)},
            {2, std::vector<float>(5)}
    };
    for (auto &i: *this) {
        i = helperFunktions::randomFloat(-1, 1);
    }
}

Network::v3Float Network::getWeights() const {
    return weights;
}

bool Network::calculate(const std::vector<float> &inputs) const {
    if (inputs.size() != 5) {
        helperFunktions::print("Network calculate wrong input size");
        std::exit(1);
    }


    std::vector<float> hiddenlayer(5);
    for (int i = 0; i < hiddenlayer.size(); i++) {
        hiddenlayer.at(i) = calculateNote(weights.at(0).at(i), inputs);
    }

    v1Float outLayer(2);
    for (int i = 0; i < outLayer.size(); i++) {
        outLayer.at(i) = calculateNote(weights.at(1).at(i), hiddenlayer);
    }

    return outLayer.at(0) > outLayer.at(1);
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