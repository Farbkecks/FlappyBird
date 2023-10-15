#pragma once

#include "helperFuntions.h"
#include "constants.h"
#include <vector>
#include <cstdlib>

class Network {
public:
    typedef std::vector<std::vector<std::vector<float>>> v3Float;
    typedef std::vector<std::vector<float>> v2Float;
    typedef std::vector<float> v1Float;


    //Iterator
    struct Iterator {
        struct Coord {
            int layer, note, y;

            bool operator==(Coord const &rhs) const;

            bool operator!=(Coord const &rhs) const;
        };

        Iterator(Coord coord, v3Float &weight) : coord(coord), weight(weight) {};

        float &operator*() const;

        bool operator==(const Iterator &other) { return (coord == other.coord); };

        bool operator!=(const Iterator &other) { return (coord != other.coord); };

        // Prefix increment
        Iterator &operator++();

        // Suffix operator
        Iterator operator++(int);

    private:
        Coord coord;
        v3Float &weight;
    };

    auto begin() { return Iterator({0, 0, 0}, weights); }

    auto end() { return Iterator({(int) weights.size(), 0, 0}, weights); }

//funktions
public:
    Network();

    explicit Network(const v1Float &weights);

    Network(Network &lhs, Network &rhs);

    bool calculate(float velocity, float heightDifferenceToNextPipe, float heightNextPipe,
                   float heightDifferenceToSecondNextPipe, float heightSecondNextPipe, float xDifference) const;

    v3Float getWeights() const;

//funktions
private:

    static float calculateNote(const Network::v1Float &weight, const Network::v1Float &input);

    static v3Float emptyWeights();

    //variables
private:
    v3Float weights;


};
