#include "PresidentialPardonForm.hpp"

/**********************************************/
/*              CONSTRUCTEUR                  */
/**********************************************/
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    try : Form("Presidential Pardon", 25, 5), _target(target) {
}
catch (std::exception &e) {
    throw ;
}

/**********************************************/
/*         CONSTRUCTEUR COPIE                 */
/**********************************************/
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
    : Form(obj.getName(), obj.getSigned(), obj.getExec()), _target(obj._target) {
}

/**********************************************/
/*              DESTRUCTEUR                   */
/**********************************************/
PresidentialPardonForm::~PresidentialPardonForm(void) {
}

/**********************************************/
/*                 GETTER                     */
/**********************************************/
std::string PresidentialPardonForm::getTarget(void) const {
    return _target;
}

/**********************************************/
/*                 SETTER                     */
/**********************************************/
void PresidentialPardonForm::setTarget(const std::string target) {
    _target = target;
}

/**********************************************/
/*             SURCHARGE D'OPPERATEUR         */
/**********************************************/
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    _target = obj._target;
    return *this;
}

std::ostream &operator<<(std::ostream &cout, const PresidentialPardonForm &obj) {
    std::cout << "Name                         : " << obj.getName() << std::endl;
    std::cout << "Status                       : " << std::boolalpha << obj.getStatus() << std::endl;
    std::cout<< "required grade for signature : " << obj.getSigned() << std::endl;
    std::cout<< "required grade for execution : " << obj.getExec() << std::endl;
    std::cout << "Target                       : " << obj.getTarget();
    return cout;
}

/**********************************************/
/*             FONCTION ANNEXE                */
/**********************************************/
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getSigned() || executor.getGrade() > getExec())
        throw GradeTooLowException();
    std::cout << _target << " has been forgiven by Zaphod Beeblebrox " << std::endl;
}
