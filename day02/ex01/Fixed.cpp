#include "Fixed.hpp" 

Fixed::Fixed(void) : _fix(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
} 

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    _fix = roundf(f * (1 << _bits));
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _fix = n << _bits;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

/* --------------------------------------------------------------------------------------- */

int Fixed::getRawBits(void) const {
    return _fix;
}

void Fixed::setRawBits(int const raw) {
    _fix = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_fix) / static_cast<float>(1 << _bits);
}

int Fixed::toInt(void) const {
    return _fix >> _bits;
}

/* --------------------------------------------------------------------------------------- */

Fixed &Fixed::operator=(const Fixed &obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(obj.getRawBits());
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
    out << obj.toFloat();
    return out;
}
