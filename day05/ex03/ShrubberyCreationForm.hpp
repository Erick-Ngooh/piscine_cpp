#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP 

#  include <fstream>
#  include <iostream>
#  include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form {

    public:
        // Constructeur
        ShrubberyCreationForm(std::string target);

        // Constructeur Copie
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);

        // Destructeur
        virtual ~ShrubberyCreationForm();

        // Accesseur 
        std::string getTarget(void) const;

        // Modifieur 
        void setTarget(const std::string target);

        // surcharge d'asignation
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

        // fonction annexe
        virtual void execute(Bureaucrat const &executor) const;

    private:
        std::string _target;

    protected: 
        // [ .... ]
};

// surcharge d'affichage
std::ostream &operator<<(std::ostream &cout, const ShrubberyCreationForm &obj);

#endif
