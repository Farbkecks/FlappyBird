#include "network.h"

Network::Network(const typeWeights &weights)
        : weights(weights) {
}

Network::typeWeights Network::getWeights() const {
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

    typeLayer outLayer(2);
    for (int i = 0; i < outLayer.size(); i++) {
        outLayer.at(i) = calculateNote(weights.at(1).at(i), hiddenlayer);
    }

    return outLayer.at(0) > outLayer.at(1);
}

float Network::calculateNote(const Network::typeLayer &weight, const Network::typeLayer &input) {
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