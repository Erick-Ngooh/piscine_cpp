#include "Dog.hpp"

Dog::Dog(void)  {
    _type = "Dog";
    std::cout << BGRN << "Constructor Dog" << std::endl << reset;
}

Dog::Dog(const Dog &obj)  : Animal() {
    *this = obj;
}

Dog::~Dog(void) {
    std::cout << BRED << "Destructor Dog" << std::endl << reset;
}

Dog &Dog::operator=(const Dog &obj) {
    static_cast<void>(obj);
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << BGRN << "Dog make sound : Whouaf Whouaf ! " << std::endl << reset;
}

 std::string   Dog::getType(void) const {
    return _type;
}
