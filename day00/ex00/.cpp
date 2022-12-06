#include "ricko.hpp"

/*************************************************************/
/*                          CONSTRUCTOR                      */
/*************************************************************/
ricko::ricko( void )
{
   _x = 0;
   std::cout << "hello world";
}

ricko::ricko( ricko const & src )
{
    *this = src;
}

/*************************************************************/
/*                         DESTRUCTOR                        */
/*************************************************************/
ricko::~ricko( void )
{
   free(x);
}

/*************************************************************/
/*                      ASSIGNMENT OPERATOR                  */
/*************************************************************/
ricko & ricko::operator=( ricko const & src )
{
   _x = src._x;
    return (*this);
}


ricko a;

a.setx(12);

ricko b(a);
