#pragma once

#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <memory>

namespace detail {
    template<typename T, typename... Tail>
    void print_impl(const T &t, const Tail &... tail) {
        using namespace std::literals;
        std::cout << t;
        (..., (std::cout << " "sv << tail));
    }
}  // namespace detail

namespace helperFunktions {
    template<typename... Tail>
    void print(const Tail &... tail) {
        if constexpr (sizeof...(tail) != 0) {
            detail::print_impl(tail...);
        }
        std::cout << std::endl;
    }

    void print(const std::vector<float> &vec);

    float randomInt(sf::Vector2f range);

    float randomFloat(const float LO, const float HI);

    sf::Vector2f addVector2f(sf::Vector2f &left, const sf::Vector2f &right);

    //return number between 0 and 1
    float sigmoid(float num);

    void drawHorizontalLine(const sf::Vector2f &pos, std::shared_ptr<sf::RenderWindow> window);
}
