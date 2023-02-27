#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <ostream>
#include <string>

template<typename T>
void    swap(T &val1, T &val2) {
    T   tmp;

    tmp = val1;
    val1 = val2;
    val2 = tmp;
}

template<typename T>
T const &min(T const &x, T const &y) {
    return x <= y ? x : y;
}

template<typename T>
T const &max(T const &x, T const &y) {
    return x >= y ? x : y;
}

#endif
