#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {
//    std::cout << "constructor abstract AMateria" << std::endl;
}

AMateria::~AMateria(void) {
 //   std::cout << "destructor abstract AMateria" << std::endl;
}

std::string const &AMateria::getType() const {
    return _type;
}

/* ------------------------------------------------------------------------ */

Ice::Ice(void) : AMateria("ice") {
  //  std::cout << "constructor concrete Ice" << std::endl;
}

Ice::Ice(const Ice &obj) : AMateria(obj.getType()) {
    *this = obj;
   // std::cout << "constructor copy concrete Cure" << std::endl;
}

Ice &Ice::operator=(const Ice &obj) {
    static_cast<void>(obj);
    return *this;
}

Ice::~Ice(void) {
    //std::cout << "destructor concrete Ice" << std::endl;
}

AMateria *Ice::clone(void) const {
    Ice *ptr = new Ice();
    return ptr ? ptr : NULL;
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/* ------------------------------------------------------------------------ */

Cure::Cure(void) : AMateria("cure") {
    //std::cout << "constructor concrete Cure" << std::endl;
}

Cure::Cure(const Cure &obj) : AMateria(obj.getType()) {
    *this = obj;
    //std::cout << "constructor copy concrete Cure" << std::endl;
}

Cure &Cure::operator=(const Cure &obj) {
    static_cast<void>(obj);
    return *this;
}

Cure::~Cure(void) {
    //std::cout << "destructor concrete Cure" << std::endl;
}

AMateria *Cure::clone(void) const {
    Cure *ptr = new Cure();
    return ptr ? ptr : NULL;
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
