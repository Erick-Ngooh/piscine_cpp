#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
   public:
      Fixed(void);
      ~Fixed(void);
      Fixed(const int n);
      Fixed(const float f);
      Fixed(Fixed const &obj);
      float toFloat(void) const;
      int toInt(void) const;
      Fixed &operator=(const Fixed &obj);
      bool operator>(const Fixed &obj) const;
      bool operator<(const Fixed &obj) const;
      bool operator>=(const Fixed &obj) const;
      bool operator<=(const Fixed &obj) const;
      bool operator==(const Fixed &obj) const;
      bool operator!=(const Fixed &obj) const;
      Fixed operator+(const Fixed &obj);
      Fixed operator-(const Fixed &obj);
      Fixed operator*(const Fixed &obj);
      Fixed operator/(const Fixed &obj);
      Fixed &operator++(void);
      Fixed operator++(int);
      Fixed &operator--(void);
      Fixed operator--(int);
      static Fixed &min(Fixed &obj1, Fixed &obj2);
      static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
      static Fixed &max(Fixed &obj1, Fixed &obj2);
      static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
      int   getRawBits(void) const;
      void  setRawBits(int const raw);

   private:
      int               _fix;
      static const int  _bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);
#endif
