#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    Shrubberytest(void) {
    Bureaucrat  bob("Bob", 22);
    try {
        std::cout << bob << std::endl;
        ShrubberyCreationForm shrubberyCreationForm("Garden");
        std::cout << shrubberyCreationForm << std::endl;
        shrubberyCreationForm.beSigned(bob);
        bob.signForm(shrubberyCreationForm);
        bob.executeForm(shrubberyCreationForm);
    }
    catch (std::exception &e){
        throw ;
    }

    std::cout << std::endl;

    Bureaucrat  carl("Carl", 139); 
    try {
        std::cout << carl << std::endl;
        ShrubberyCreationForm shrubberyCreationForm("Private Garden");
        std::cout << shrubberyCreationForm << std::endl;
        shrubberyCreationForm.beSigned(carl);
        carl.signForm(shrubberyCreationForm);
        carl.executeForm(shrubberyCreationForm);
    }
    catch (std::exception &e){
        throw ;
    }
}

void    Robotomytest(void) {
    Bureaucrat  bob("Bob", 22);
    try {
        std::cout << bob << std::endl;
        RobotomyRequestForm robotomyRequestForm("Chien");
        std::cout << robotomyRequestForm << std::endl;
        robotomyRequestForm.beSigned(bob);
        bob.signForm(robotomyRequestForm);
        bob.executeForm(robotomyRequestForm);
    }
    catch (std::exception &e){
        throw ;
    }

    std::cout << std::endl;

    Bureaucrat  carl("Carl", 53); 
    try {
        std::cout << carl << std::endl;
        RobotomyRequestForm robotomyRequestForm("Chat");
        std::cout << robotomyRequestForm << std::endl;
        robotomyRequestForm.beSigned(carl);
        carl.signForm(robotomyRequestForm);
        carl.executeForm(robotomyRequestForm);
    }
    catch (std::exception &e){
        throw ;
    }
}

void    PresidentialPardontest(void) {
    Bureaucrat  bob("Obama", 1);
    try {
        std::cout << bob << std::endl;
        PresidentialPardonForm presidentialPardonForm("Prisonnier");
        std::cout << presidentialPardonForm << std::endl;
        presidentialPardonForm.beSigned(bob);
        bob.signForm(presidentialPardonForm);
        bob.executeForm(presidentialPardonForm);
    }
    catch (std::exception &e){
        throw ;
    }

    std::cout << std::endl;

    Bureaucrat  carl("Carl", 15); 
    try {
        std::cout << carl << std::endl;
        PresidentialPardonForm presidentialPardonForm("Traite");
        std::cout << presidentialPardonForm << std::endl;
        presidentialPardonForm.beSigned(carl);
        carl.signForm(presidentialPardonForm);
        carl.executeForm(presidentialPardonForm);
    }
    catch (std::exception &e){
        throw ;
    }
}

int main(void) {
    try {
        Shrubberytest();
        Robotomytest();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Robotomytest();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        PresidentialPardontest();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
