#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    try {
        Intern somerandomIntern;
        Form  *rrf;

        rrf = somerandomIntern.makeForm("Robotomy Request", "bender");
        std::cout << *rrf << std::endl;
        delete rrf;
        rrf = somerandomIntern.makeForm("Presidential Pardon", "bender");
        std::cout << *rrf << std::endl;
        delete rrf;
        rrf = somerandomIntern.makeForm("Shrubbery Creation", "bender");
        std::cout << *rrf << std::endl;
        delete rrf;
        rrf = somerandomIntern.makeForm("Unknown Form", "bender");
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
