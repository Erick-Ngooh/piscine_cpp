#include "RobotomyRequestForm.hpp"

/**********************************************/
/*              CONSTRUCTEUR                  */
/**********************************************/
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    try : Form("Robotomy", 72, 45), _target(target) {
}
catch (std::exception &e) {
    throw ;
}

/**********************************************/
/*         CONSTRUCTEUR COPIE                 */
/**********************************************/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
    : Form(obj.getName(), obj.getSigned(), obj.getExec()), _target(obj._target) {
}

/**********************************************/
/*              DESTRUCTEUR                   */
/**********************************************/
RobotomyRequestForm::~RobotomyRequestForm(void) {
}

/**********************************************/
/*                 GETTER                     */
/**********************************************/
std::string RobotomyRequestForm::getTarget(void) const {
    return _target;
}

/**********************************************/
/*                 SETTER                     */
/**********************************************/
void RobotomyRequestForm::setTarget(const std::string target) {
    _target = target;
}

/**********************************************/
/*             SURCHARGE D'OPPERATEUR         */
/**********************************************/
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    _target = obj._target;
    return *this;
}

std::ostream &operator<<(std::ostream &cout, const RobotomyRequestForm &obj) {
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
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getSigned() || executor.getGrade() > getExec())
        throw GradeTooLowException();
    std::cout << "brrrr brrrrr brrrrr brrrrrr brrrrrr" << std::endl;
    srand(time(0));
    int randomNumber = rand() % 2;
    if (!randomNumber)
        std::cout << _target << " are robotomized " << std::endl;
    else
        std::cout << _target << " are not robotomized because the operation failed" << std::endl;
}
