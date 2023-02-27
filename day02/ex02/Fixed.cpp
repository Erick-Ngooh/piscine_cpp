#include "Fixed.hpp" 

Fixed::Fixed(void) : _fix(0) {
//    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
 //   std::cout << "Copy constructor called" << std::endl;
    *this = obj;
} 

Fixed::Fixed(const float f) {
  //  std::cout << "Float constructor called" << std::endl;
    _fix = roundf(f * (1 << _bits));
}

Fixed::Fixed(const int n) {
   // std::cout << "Int constructor called" << std::endl;
    _fix = n << _bits;
}

Fixed::~Fixed(void) {
   // std::cout << "Destructor called" << std::endl;
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

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2) {
    return (obj1 < obj2) ? obj1 : obj2;
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2) {
    return (obj1 < obj2) ? obj1 : obj2;
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2) {
    return (obj1 > obj2) ? obj1 : obj2;
}

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2) {
    return (obj1 > obj2) ? obj1 : obj2;
}

/* --------------------------------------------------------------------------------------- */

Fixed &Fixed::operator=(const Fixed &obj) {
    //std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(obj.getRawBits());
    return *this;
}

bool Fixed::operator>(const Fixed &obj) const {
    return _fix > obj.getRawBits();
}

bool Fixed::operator<(const Fixed &obj) const {
    return _fix < obj.getRawBits();
}

bool    Fixed::operator>=(const Fixed &obj) const {
    return _fix >= obj.getRawBits();
}

bool    Fixed::operator<=(const Fixed &obj) const {
    return _fix <= obj.getRawBits();
}

bool Fixed::operator==(const Fixed &obj) const {
    return _fix == obj.getRawBits();
}

bool Fixed::operator!=(const Fixed &obj) const {
    return _fix != obj.getRawBits();
}

Fixed Fixed::operator+(const Fixed &obj) {
    return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed &obj) {
    return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed &obj) {
    return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj) {
    return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed &Fixed::operator++(void) {
    this->setRawBits(_fix + 1);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->setRawBits(_fix + 1);
    return tmp;
}

Fixed &Fixed::operator--(void) {
    this->setRawBits(_fix - 1);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->setRawBits(_fix - 1);
    return tmp;
}

/* --------------------------------------------------------------------------------------- */

std::ostream &operator<<(std::ostream &out, const Fixed &obj) {
    out << obj.toFloat();
    return out;
}
