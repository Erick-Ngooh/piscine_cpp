#include "Form.hpp"

/**********************************************/
/*              CONSTRUCTEUR                  */
/**********************************************/
Form::Form(std::string name, int sign, int exec) : _status(false), _name(name), _sign(sign), _exec(exec) {
    if (_sign < 1 || _exec < 1)
        throw GradeTooHighException();
    else if (_sign > 150 || _exec > 150) 
        throw GradeTooLowException(); 
}

/**********************************************/
/*         CONSTRUCTEUR COPIE                 */
/**********************************************/
Form::Form(const Form &obj) : _status(false), _name(obj._name), _sign(obj._sign), _exec(obj._exec) {
}

/**********************************************/
/*              DESTRUCTEUR                   */
/**********************************************/
Form::~Form(void) {
}

/**********************************************/
/*                 GETTER                     */
/**********************************************/
std::string Form::getName(void) const {
    return _name;
}

int Form::getSigned(void) const {
    return _sign;
}

int Form::getExec(void) const {
    return _exec;
}

bool Form::getStatus(void) const {
    return _status;
}

/**********************************************/
/*                 SETTER                     */
/**********************************************/

/**********************************************/
/*             SURCHARGE D'OPPERATEUR         */
/**********************************************/
Form &Form::operator=(const Form &obj) {
    static_cast<void>(obj);
    return *this;
}

std::ostream &operator<<(std::ostream &cout, const Form &obj) {
    std::cout << "Name : " << obj.getName() << std::endl;
    std::cout << "Status : " << std::boolalpha << obj.getStatus() << std::endl;
    std::cout<< "required grade for signature : " << obj.getSigned() << std::endl;
    std::cout<< "required grade for execution : " << obj.getSigned() << std::endl;
    return cout;
}

/**********************************************/
/*             FONCTION ANNEXE                */
/**********************************************/

bool Form::beSigned(const Bureaucrat &obj) {
    if (obj.getGrade() > _sign)
        throw GradeTooLowException();
    _status = true;
    return _status;
}
