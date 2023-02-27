#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP 

#  include <iostream>
#  include "Form.hpp"

class PresidentialPardonForm : public Form {

    public:
        // Constructeur
        PresidentialPardonForm(std::string target);

        // Constructeur Copie
        PresidentialPardonForm(const PresidentialPardonForm &obj);

        // Destructeur
        virtual ~PresidentialPardonForm();

        // Accesseur 
        std::string getTarget(void) const;

        // Modifieur 
        void setTarget(const std::string target);

        // surcharge d'asignation
        PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);

        // fonction annexe
        virtual void execute(Bureaucrat const &executor) const;

    private:
        std::string _target;

    protected: 
        // [ .... ]
};

// surcharge d'affichage
std::ostream &operator<<(std::ostream &cout, const PresidentialPardonForm &obj);

#endif
