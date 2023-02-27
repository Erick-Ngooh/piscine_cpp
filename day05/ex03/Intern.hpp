#ifndef INTERN_HPP
# define INTERN_HPP 

#  include "Form.hpp"
#  include <iostream>

class Intern {

    public:
        class FormNotExistException : public std::exception {
            virtual const char* what(void) const throw() {
                return "form does not exist";
            };
        };
        
        // Constructeur Copie
        Intern(void);

        // Constructeur Copie
        Intern(const Intern &obj);

        // Destructeur
        ~Intern();

        // surcharge d'asignation
        Intern &operator=(const Intern &obj);

        // fonction annexe
        Form *makeForm(std::string name, std::string target);

    private:
        std::string     _NameForm[3];

    protected: 
        // [ .... ]
};

// surcharge d'affichage
std::ostream &operator<<(std::ostream &cout, const Intern &obj);

#endif
