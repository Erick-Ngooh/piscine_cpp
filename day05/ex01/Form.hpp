#ifndef FORM_HPP
# define FORM_HPP 

#  include <iostream>
#  include <string>
#  include <exception>
#  include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

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
        Form(std::string name, const int gradeSigned, const int gradeExec);

        // Constructeur Copie
        Form(const Form &obj);

        // Destructeur
        virtual ~Form();

        // Accesseur 
        std::string  getName(void) const;
        int          getSigned(void) const;
        int          getExec(void) const;
        bool         getStatus(void) const;
        // Modifieur 

        // surcharge d'asignation
        Form &operator=(const Form &obj);

        // Fonction annexe 
        bool beSigned(const Bureaucrat &obj);

    private:
        bool                _status;
        const std::string   _name;
        const int           _sign; 
        const int           _exec; 

    protected: 
        // [ .... ]
};

// surcharge d'affichage
std::ostream &operator<<(std::ostream &cout, const Form &obj);

#endif
