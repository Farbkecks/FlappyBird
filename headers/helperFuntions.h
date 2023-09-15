#pragma once

#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

namespace detail {
    template<typename T, typename... Tail>
    void print_impl(const T &t, const Tail &... tail) {
        using namespace std::literals;
        std::cout << t;
        (..., (std::cout << " "sv << tail));
    }
}  // namespace detail

namespace helperFunktions{
    template<typename... Tail>
    void print(const Tail &... tail) {
        if constexpr (sizeof...(tail) != 0) {
            detail::print_impl(tail...);
        }
        std::cout << std::endl;
    }
    template<typename T>
    T randomNum(T bottom, T top) {
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(bottom, top);
        return distr(generator);
    }

    float randomNum(sf::Vector2f range);
}
