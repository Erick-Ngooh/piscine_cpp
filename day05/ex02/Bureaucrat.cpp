#include "Bureaucrat.hpp"

/**********************************************/
/*              CONSTRUCTEUR                  */
/**********************************************/
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150) 
        throw GradeTooLowException(); 
    _grade = grade;
}

/**********************************************/
/*         CONSTRUCTEUR COPIE                 */
/**********************************************/
Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
    *this = obj;
}

/**********************************************/
/*              DESTRUCTEUR                   */
/**********************************************/
Bureaucrat::~Bureaucrat(void) {
}

/**********************************************/
/*                 GETTER                     */
/**********************************************/
std::string Bureaucrat::getName(void) const {
    return _name;
}

int Bureaucrat::getGrade(void) const {
    return _grade;
}
/**********************************************/
/*                 SETTER                     */
/**********************************************/
void Bureaucrat::setUpgrade(void) {
    _grade - 1 < 1 ? throw GradeTooHighException() : _grade--;
}

void Bureaucrat::setDisgrade(void) {
    _grade + 1 > 150 ? throw GradeTooLowException() : _grade++;
}

/**********************************************/
/*             SURCHARGE D'OPPERATEUR         */
/**********************************************/
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    _grade = obj._grade;
    return *this;
}

std::ostream &operator<<(std::ostream &cout, const Bureaucrat &obj) {
    std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return cout;
}

/**********************************************/
/*             FONCTION ANNEXE                */
/**********************************************/

void Bureaucrat::signForm(Form &form) const {
    if (_grade > form.getSigned()) {
        std::cout << "bureaucrat " << _name << " couldn’t sign form " << form.getName() << "because ";
        std::cout << " grade is too low." << std::endl;
    }
    std::cout << _name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(Form const &form) {
    try {
        form.execute(*this);
    } 
    catch (std::exception &e) {
        throw ;
    }
    std::cout << _name <<  " executed " << form.getName() << std::endl;
}
