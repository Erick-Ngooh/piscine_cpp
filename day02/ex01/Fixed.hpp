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
      int   getRawBits(void) const;
      void  setRawBits(int const raw);

   private:
      int               _fix;
      static const int  _bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);
#endif
