#include "Cat.hpp"

Cat::Cat(void) {
    _type = "Cat";
    std::cout << BGRN << "Constructor Cat" << std::endl << reset;
}

Cat::Cat(const Cat &obj) : Animal() {
    *this = obj;
    std::cout << BGRN << "Constructor Copy Cat" << std::endl << reset;
}

Cat::~Cat(void) {
    std::cout << BRED << "Destructor Cat" << std::endl << reset;
}

Cat &Cat::operator=(const Cat &obj) {
    _type = obj._type;
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << BGRN << "Cat make sound : Miaou Miaou ! " << std::endl << reset;
}

 std::string  Cat::getType(void) const {
    return _type;
}

