#include "Animal.hpp"

Animal::Animal(void) : _type("?") {
    std::cout << BGRN << "Constructor Animal" << std::endl << reset;
}

Animal::Animal(const Animal &obj) {
    *this = obj;
}

Animal::~Animal(void) {
    std::cout << BRED << "Destructor Animal" << std::endl << reset;
}

Animal &Animal::operator=(const Animal &obj) {
    static_cast<void>(obj);
    return *this;
}

void Animal::makeSound(void) const {
    std::cout << BGRN << "Animal make sound : ????? " << std::endl << reset;
}

 std::string  Animal::getType(void) const {
    return _type;
}
