#ifndef SPAN_HPP
# define SPAN_HPP 

#include <algorithm> // std::min_element and std::max_element
#include <exception>
#include <iostream>
#include <cstdlib>
#include <vector>

class Span {

    public:
        //exception 

        class maxCapacityForSpan : public std::exception {
            public: 
                virtual char const *what(void) const throw() {
                    return "Error : Max capacity for Span";
                }
        };
        
        class distanceNotFoundSpan : public std::exception {
            public: 
                virtual char const *what(void) const throw() {
                    return "Error : Distance not found in Span";
                }
        };

        // Constructeur
        Span(unsigned int N);

        // Constructeur Copie
        Span(const Span &obj);

        // Destructeur
        virtual ~Span(void);

        // surcharge d'asignation
        Span &operator=(const Span &obj);

        // fonction annexe
        int     longestSpan(void);
        int     shortestSpan(void);
        void    addNumber(unsigned int nbr);
        void    addNumberRange(const std::vector<int>::iterator &first, const std::vector<int>::iterator &last);

    private:
        unsigned int                _N;
        unsigned int                _size;
        std::vector<int>            _vec;

        // [ .... ]

    protected: 
        // [ .... ]
};

// surcharge d'affichage
std::ostream &operator<<(std::ostream &cout, const Span &obj);

#endif
