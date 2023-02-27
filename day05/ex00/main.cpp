#include "Bureaucrat.hpp"

int main(void) {
    try
    {
        Bureaucrat Bob("Bob", 1);
        std::cout << Bob << std::endl;
        std::cout << "Bureaucrat Disgrade ." << std::endl;
        for (int i = 1; i < 100; i++)
            Bob.setDisgrade();
        std::cout << Bob << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    
    try
    {
        Bureaucrat Carl("Carl", 100);
        std::cout << Carl << std::endl;
        std::cout << "Bureaucrat Upgrade ." << std::endl;
        for (int i = 100; i > 1; i--)
            Carl.setUpgrade();
        std::cout << Carl << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat Patric("Patric", 1);
        
        std::cout << Patric << std::endl;
        std::cout << "Bureaucrat Upgrade ." << std::endl;
        Patric.setUpgrade();
        std::cout << Patric  << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl << std::endl;
    }

    try
    {
        Bureaucrat Frank("Frank", 150); 
        std::cout << Frank << std::endl;
        std::cout << "Bureaucrat Disgrade ." << std::endl;
        Frank.setDisgrade();
        std::cout << Frank  << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    return 0;
}
