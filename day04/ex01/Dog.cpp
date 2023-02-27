#include "Dog.hpp"

Dog::Dog(void)  {
    _type = "Dog";
    std::cout << BGRN << "Constructor Dog" << std::endl << reset;
    _brain = new Brain();
}

Dog::Dog(const Dog &obj)  : Animal() {
    *this = obj;
    std::cout << BGRN << "Constructor Copy Dog" << std::endl << reset;
}

Dog::~Dog(void) {
    delete _brain;
    std::cout << BRED << "Destructor Dog" << std::endl << reset;
}

Dog &Dog::operator=(const Dog &obj) {
    _brain = new Brain(*obj._brain);
    _type = obj._type;
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << BGRN << "Dog make sound : Whouaf Whouaf ! " << std::endl << reset;
}

 std::string   Dog::getType(void) const {
    return _type;
}

void    Dog::getBrain(int i) const {
    std::cout << _brain->getIdea(i) << std::endl;
}

void    Dog::setBrain(std::string str) {
    for (int i = 0; i < 100; i++) {
        _brain->setIdea(i, str);
    }
}
