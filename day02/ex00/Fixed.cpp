#include "Fixed.hpp" 

Fixed::Fixed(void) : _fix(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
} 

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fix;
}

void Fixed::setRawBits(int const raw) {
    _fix = raw;
}

Fixed &Fixed::operator=(const Fixed &obj) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(obj.getRawBits());
    return *this;
}
