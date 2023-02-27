#include "Span.hpp"

/**********************************************/
/*              CONSTRUCTEUR                  */
/**********************************************/
Span::Span(unsigned int N) {
    _N = N >= 1 ? N : 0;
    _size = _N;
    _vec.reserve(_N);
}

/**********************************************/
/*         CONSTRUCTEUR COPIE                 */
/**********************************************/
Span::Span(const Span &obj) {
    *this = obj;
}

/**********************************************/
/*              DESTRUCTEUR                   */
/**********************************************/
Span::~Span(void) {
}

/**********************************************/
/*             SURCHARGE D'OPPERATEUR         */
/**********************************************/
Span &Span::operator=(const Span &obj) {
    _N = obj._N;
    _vec = obj._vec;
    return *this;
}

std::ostream &operator<<(std::ostream &cout, const Span &obj) {
    static_cast<void>(obj);
    static_cast<void>(cout);
    return cout;
}

/**********************************************/
/*             FONCTION ANNEXE                */
/**********************************************/
int Span::shortestSpan(void) {
    if (_size <= 1)
        throw(distanceNotFoundSpan());

    std::sort(_vec.begin(), _vec.end());

    int minDis = _vec[1] - _vec[0];
    for (std::vector<int>::iterator it = _vec.begin() + 1; it != _vec.end(); ++it)
    {
        int dis = *it - *(it - 1);
        if (dis < minDis) 
            minDis = dis;
    }
    return minDis;
}

int     Span::longestSpan(void) {
    if (_size <= 1)
        throw(distanceNotFoundSpan());
    std::vector<int>::iterator iMax;
    std::vector<int>::iterator iMin;

    iMax = std::max_element(_vec.begin(), _vec.end());
    iMin = std::min_element(_vec.begin(), _vec.end());
    return *iMax - *iMin;
}

void Span::addNumber(unsigned int nbr) {
        !_N ? throw (maxCapacityForSpan()) : _vec.push_back(nbr);
        _N--;
}

void    Span::addNumberRange(const std::vector<int>::iterator &first, const std::vector<int>::iterator &last) { 
    std::distance(first, last) >= _N ? _vec.assign(first, last) : throw(maxCapacityForSpan()) ;
    _N -= std::distance(first, last);
}
