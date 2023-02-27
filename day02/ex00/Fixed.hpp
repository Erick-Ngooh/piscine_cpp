#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
   public:
      Fixed(void);
      ~Fixed(void);
      Fixed(const int n);
      Fixed(Fixed const &obj);
      Fixed &operator=(Fixed const & src );
      int   getRawBits(void) const;
      void  setRawBits(int const raw);

   private:
      int   _fix;
      static const int  _lit = 8;
};

#endif
