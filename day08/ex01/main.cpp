#include "Span.hpp"

int main(void)
{
    srand(time(0));
    {
        std::cout << "------ Standard test ------" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl << std::endl;
    }
    {
        std::cout << "------ Main test ------" << std::endl;

        try {
            Span sp(10000);
            for (int i = 0; i < 10000; i++)
                sp.addNumber(i + (rand() % 20000));
        
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl << std::endl;
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::cout << "------ Main test ------" << std::endl;

        try {
            Span sp(100);
            for (int i = 0; i < 10000; i++)
                sp.addNumber(i + (rand() % 20000));
        
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl << std::endl;
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl << std::endl;
        }
    }
    {
        std::cout << "------ Main test ------" << std::endl;

        try {
            Span sp(1);
            sp.addNumber(rand() % 100);
        
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl << std::endl;
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}
