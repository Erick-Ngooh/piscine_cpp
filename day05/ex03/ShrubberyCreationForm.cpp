#include "ShrubberyCreationForm.hpp"

/**********************************************/
/*              CONSTRUCTEUR                  */
/**********************************************/
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    try : Form("Shrubbery Creation", 145, 137), _target(target) {
}
catch (std::exception &e) {
    throw ;
}

/**********************************************/
/*         CONSTRUCTEUR COPIE                 */
/**********************************************/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
    : Form(obj.getName(), obj.getSigned(), obj.getExec()), _target(obj._target) {
}

/**********************************************/
/*              DESTRUCTEUR                   */
/**********************************************/
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

/**********************************************/
/*                 GETTER                     */
/**********************************************/
std::string ShrubberyCreationForm::getTarget(void) const {
    return _target;
}

/**********************************************/
/*                 SETTER                     */
/**********************************************/
void ShrubberyCreationForm::setTarget(const std::string target) {
    _target = target;
}

/**********************************************/
/*             SURCHARGE D'OPPERATEUR         */
/**********************************************/
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    _target = obj._target;
    return *this;
}

std::ostream &operator<<(std::ostream &cout, const ShrubberyCreationForm &obj) {
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
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getSigned() || executor.getGrade() > getExec())
        throw GradeTooLowException();
    std::string tree =
"       _-_       \n"       
"    /~~   ~~\\    \n"          
" /~~         ~~\\ \n"      
"{               }\n"      
" \\  _-     -_  / \n"      
"   ~  \\ //  ~   \n"      
"_- -   | | _- _  \n"       
"  _ -  | |   -_  \n"         
"      // \\      \n";
    std::string fileName = _target + "_shrubbery";
    std::ofstream file;
    file.open(fileName.c_str());
    if (!file.is_open())
        throw std::exception();
    file << tree << "  " << tree << "  " << tree << "  " << std::endl;
    file.close();
}
