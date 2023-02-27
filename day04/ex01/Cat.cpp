#include "Cat.hpp"

Cat::Cat(void) {
    _type = "Cat";
    std::cout << BGRN << "Constructor Cat" << std::endl << reset;
    _brain = new Brain();
}

Cat::Cat(const Cat &obj) : Animal() {
    *this = obj;
    std::cout << BGRN << "Constructor Copy Cat" << std::endl << reset;
}

Cat::~Cat(void) {
    delete _brain;
    std::cout << BRED << "Destructor Cat" << std::endl << reset;
}

Cat &Cat::operator=(const Cat &obj) {
    _brain = new Brain(*obj._brain);
    _type = obj._type;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << BGRN << "Cat make sound : Miaou Miaou ! " << std::endl << reset;
}

std::string  Cat::getType(void) const {
    return _type;
}

void    Cat::getBrain(int i) const {
    std::cout << _brain->getIdea(i) << std::endl;
}

void    Cat::setBrain(std::string str) {
    for (int i = 0; i < 100; i++) {
        _brain->setIdea(i, str);
    }
}
