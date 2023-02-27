/* 
   $> ./a.out
   Default constructor called
   Int constructor called
   Float constructor called
   Copy constructor called
   Copy assignment operator called
   Float constructor called
   Copy assignment operator called
   Destructor called
   a is 1234.43
   b is 10
   c is 42.4219
   d is 10
   a is 1234 as integer
   b is 10 as integer
   c is 42 as integer
   d is 10 as integer
   Destructor called
   Destructor called
   Destructor called
   Destructor called
   $>
   */
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "operator<<(std::cout, a) = ";
    operator<<(std::cout, a) << std::endl << std::endl;

    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl << std::endl;

    std::cout << "max(a, b) = " << Fixed::max( a, b ) << std::endl;
    std::cout << "min(a, b) = " << Fixed::min( a, b ) << std::endl << std::endl;

    std::cout << "b.toFloat() = " << b.toFloat() << std::endl;
    std::cout << "b.toInt() = " << b.toInt() << std::endl << std::endl;

    std::cout << std::boolalpha;
    std::cout << "a < b : " << (a < b) << std::endl;
    std::cout << "a > b : " << (a > b) << std::endl;
    std::cout << "a <= b : " << (a <= b) << std::endl;
    std::cout << "a >= b : " << (a >= b) << std::endl;
    std::cout << "a == b : " << (a == b) << std::endl;
    std::cout << "a != b : " << (a != b) << std::endl << std::endl;

    std::cout << "a + b : " << (a + b) << std::endl;
    std::cout << "a - b : " << (a - b) << std::endl;
    std::cout << "a * b : " << (a * b) << std::endl;
    std::cout << "a / b : " << (a / b) << std::endl;
    return 0;
}
