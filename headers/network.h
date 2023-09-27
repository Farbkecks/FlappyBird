#pragma once

#include "helperFuntions.h"
#include <vector>
#include <cstdlib>

class Network {
public:
    typedef std::vector<std::vector<std::vector<float>>> v3Float;
    typedef std::vector<std::vector<float>> v2Float;
    typedef std::vector<float> v1Float;
//funktions
public:
    explicit Network(const v3Float &weights);

    Network();


    //5 input float
    bool calculate(const std::vector<float> &inputs) const;

    v3Float getWeights() const;

//funktions
private:

    static float calculateNote(const Network::v1Float &weight, const Network::v1Float &input);

    static v1Float createRandomFloatVector(int n);

    static v2Float createRandomFloatVector(int n, int l);
    //variables
private:
    v3Float weights;


};
