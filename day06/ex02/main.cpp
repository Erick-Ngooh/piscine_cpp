#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base	*generate(void) {
    srand(time(0));
    int n = rand() % 3;
    Base	*ptr;

    switch(n) {
        case 0:
            ptr = new A;
            std::cout << "Generating a Class A pointer" << std::endl;
            break ;
        case 1:
            ptr = new B;
            std::cout << "Generating a Class B pointer" << std::endl;
            break ;
        case 2:
            ptr = new C;
            std::cout << "Generating a Class C pointer" << std::endl;
            break;
        default:
            break;
    }
    return (ptr);
}

void	identify(Base *p) {
    std::cout << "Identify by pointer" << std::endl;
    if (dynamic_cast<A *>(p))
        std::cout << "p type is A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "p type is B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "p type is C" << std::endl;
    else
        std::cout << "p is not type A, B or C" << std::endl;
}

void	identify(Base &p)
{
    std::cout << "Identify by reference" << std::endl;
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "p type is A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            dynamic_cast<B &>(p);
            std::cout << "p type is B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
            {
                dynamic_cast<C &>(p);
                std::cout << "p type is C" << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << "p is not type A, B or C" << std::endl;
            }
        }
    }
}

int main(void)
{
    Base *p;

    p = generate();
    identify(p);
    identify(*p);

    delete p;
    return (0);
}
