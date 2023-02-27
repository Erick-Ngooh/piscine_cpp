#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP 

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;
class ShrubberyCreationForm;

class Bureaucrat {

    public:
        // exception
        class GradeTooHighException : public std::exception {
            virtual const char* what(void) const throw() {
                return "Grade is too high";
            };
        };

        class GradeTooLowException : public std::exception {
            virtual const char* what(void) const throw() {
                return "Grade is too low";
            };
        };

        // Constructeur
        Bureaucrat(std::string name, int grade);

        // Constructeur Copie
        Bureaucrat(const Bureaucrat &obj);

        // Destructeur
        virtual ~Bureaucrat();

        // Accesseur 
        std::string getName(void) const;
        int getGrade(void) const;

        // Modifieur 
        void setUpgrade(void);
        void setDisgrade(void);

        // surcharge d'asignation
        Bureaucrat &operator=(const Bureaucrat &obj);

        // fonction annexe 
        void signForm(Form &form) const;
        void executeForm(Form const & form);

    private:
        const std::string _name;
        int         _grade;
};

// surcharge d'affichage
std::ostream &operator<<(std::ostream &cout, const Bureaucrat &obj);

#endif
