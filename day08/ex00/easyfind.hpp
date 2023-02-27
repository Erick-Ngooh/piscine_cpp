#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm> // std::min_element and std::max_element
#include <exception>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>

class noMatch : public std::exception {
    public:
        virtual char const *what(void) const throw() {
            return "no match found";
        }
};

template <typename T>
typename T::iterator easyfind(T &c, const int &nbr) {

    typename T::iterator it;

    if ((it = find(c.begin(), c.end(), nbr)) == c.end())
        throw noMatch();
    return it;
}

#endif
