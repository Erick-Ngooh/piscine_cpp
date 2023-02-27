#include "Dog.hpp"

Dog::Dog(void)  {
    _type = "Dog";
    std::cout << BGRN << "Constructor Dog" << std::endl << reset;
}

Dog::Dog(const Dog &obj)  : Animal() {
    *this = obj;
    std::cout << BGRN << "Constructor Copy Dog" << std::endl << reset;
}

Dog::~Dog(void) {
    std::cout << BRED << "Destructor Dog" << std::endl << reset;
}

Dog &Dog::operator=(const Dog &obj) {
    _type = obj._type;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << BGRN << "Dog make sound : Whouaf Whouaf ! " << std::endl << reset;
}

 std::string   Dog::getType(void) const {
    return _type;
}
