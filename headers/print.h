#pragma once

#include <iostream>

namespace detail {
    template<typename T, typename... Tail>
    void print_impl(const T &t, const Tail &... tail) {
        using namespace std::literals;
        std::cout << t;
        (..., (std::cout << " "sv << tail));
    }
}  // namespace detail

template<typename... Tail>
void print(const Tail &... tail) {
    if constexpr (sizeof...(tail) != 0) {
        detail::print_impl(tail...);
    }
    std::cout << std::endl;
}
