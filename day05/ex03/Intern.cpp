# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

/**********************************************/
/*              CONSTRUCTEUR                  */
/**********************************************/
Intern::Intern(void) {
    _NameForm[0] = "Shrubbery Creation";
    _NameForm[1] = "Robotomy Request";
    _NameForm[2] = "Presidential Pardon";
}

/**********************************************/
/*         CONSTRUCTEUR COPIE                 */
/**********************************************/
Intern::Intern(const Intern &obj) {
    *this = obj;
}

/**********************************************/
/*              DESTRUCTEUR                   */
/**********************************************/
Intern::~Intern(void) {
}

/**********************************************/
/*             SURCHARGE D'OPPERATEUR         */
/**********************************************/
Intern &Intern::operator=(const Intern &obj) {
    _NameForm[0] = obj._NameForm[0];
    _NameForm[1] = obj._NameForm[1];
    _NameForm[2] = obj._NameForm[2];
    return *this;
}

std::ostream &operator<<(std::ostream &cout, const Intern &obj) {
    static_cast<void>(obj);
    return cout;
}

/**********************************************/
/*             FONCTION ANNEXE                */
/**********************************************/

Form *Intern::makeForm(std::string name, std::string target)
{
    for (int i = 0; i < 3; i++) {
        if (!name.compare(_NameForm[i])) {
            switch (i) {
                case 0: 
                    std::cout << "Intern creates " << name << std::endl;
                    return new ShrubberyCreationForm(target);
                    break ;
                case 1 :
                    std::cout << "Intern creates " << name << std::endl;
                    return new RobotomyRequestForm(target);
                    break ;
                case 2: 
                    std::cout << "Intern creates " << name << std::endl;
                    return new PresidentialPardonForm(target);
                    break ;
            }
        }
    }
    throw FormNotExistException();
}
