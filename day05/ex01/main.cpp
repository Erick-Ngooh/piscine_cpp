#include "Bureaucrat.hpp"

int main(void) {
    try
    {
        Form    formtest1("formtest1", 1, 8);
        std::cout << formtest1 << std::endl;
        Form    formtest2("formtest2", 33, 10);
        std::cout << formtest2 << std::endl;
        Form    formtest3("formtest3", 6, 12);
        std::cout << formtest3 << std::endl;
        Form    formtest4("formtest4", -1, 88);
        std::cout << formtest4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl << std::endl;
    }

    std::cout << "************************************************" << std::endl;

    try
    {
        Bureaucrat Bob("Bob", 1);
        std::cout << Bob << std::endl;

        Form    formAugmentation("formAugmentation", 100, 100);
        std::cout << formAugmentation << std::endl;
        formAugmentation.beSigned(Bob);
        Bob.signForm(formAugmentation);
        std::cout << formAugmentation << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    
    std::cout << "************************************************" << std::endl;

    try
    {
        Bureaucrat Carl("Carl", 100);
        std::cout << Carl << std::endl;
        
        Form    formAugmentation("formAugmentation", 102, 10);
        std::cout << formAugmentation << std::endl;
        formAugmentation.beSigned(Carl);
        Carl.signForm(formAugmentation);
        std::cout << formAugmentation << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    std::cout << "************************************************" << std::endl;

    try
    {
        Bureaucrat Patric("Patric", 10);  
        std::cout << Patric  << std::endl;
        
        Form    formAugmentation("formAugmentation", 1, 10);
        std::cout << formAugmentation << std::endl;
        Patric.signForm(formAugmentation);
        formAugmentation.beSigned(Patric);
        std::cout << formAugmentation << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl << std::endl;
    }

    std::cout << "************************************************" << std::endl;

    try
    {
        Bureaucrat Frank("Frank", 150); 
        std::cout << Frank  << std::endl;
        
        Form    formAugmentation("formAugmentation", 10, 10);
        std::cout << formAugmentation << std::endl;
        formAugmentation.beSigned(Frank);
        Frank.signForm(formAugmentation);
        std::cout << formAugmentation << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    return 0;
}
