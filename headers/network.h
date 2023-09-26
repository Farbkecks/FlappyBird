#pragma once

#include "helperFuntions.h"
#include <vector>
#include <cstdlib>

class Network {
public:
    typedef std::vector<std::vector<std::vector<float>>> typeWeights;
    typedef std::vector<float> typeLayer;
//funktions
public:
    explicit Network(const typeWeights &weights);


    //5 input float
    bool calculate(const std::vector<float> &inputs) const;

    typeWeights getWeights() const;

//funktions
private:

    static float calculateNote(const Network::typeLayer &weight, const Network::typeLayer &input);
    //variables
private:
    typeWeights weights;


};
