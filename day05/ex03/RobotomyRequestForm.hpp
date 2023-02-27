#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP 
#  include <cstdlib>
#  include <ctime>
#  include <iostream>
#  include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form {

    public:
        // Constructeur
        RobotomyRequestForm(std::string target);

        // Constructeur Copie
        RobotomyRequestForm(const RobotomyRequestForm &obj);

        // Destructeur
        virtual ~RobotomyRequestForm();

        // Accesseur 
        std::string getTarget(void) const;

        // Modifieur 
        void setTarget(const std::string target);

        // surcharge d'asignation
        RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);

        // fonction annexe
        virtual void execute(Bureaucrat const &executor) const;

    private:
        std::string _target;

    protected: 
        // [ .... ]
};

// surcharge d'affichage
std::ostream &operator<<(std::ostream &cout, const RobotomyRequestForm &obj);

#endif
