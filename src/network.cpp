#include "network.h"

Network::Network(const v3Float &weights)
        : weights(weights) {
}

Network::Network() {
    weights = {
            createRandomFloatVector(5, 5),
            createRandomFloatVector(5, 2)
    };
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

Network::v1Float Network::createRandomFloatVector(int n) {
    v1Float output(n);
    for (auto &note: output) {
        note = helperFunktions::randomInt({-1, 1});
    }
    return output;
}

Network::v2Float Network::createRandomFloatVector(int n, int l) {
    v2Float output(l);
    for (auto &note: output) {
        note = createRandomFloatVector(n);
    }
    return output;
}