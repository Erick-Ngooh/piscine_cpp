#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("?") {
    std::cout << BGRN << "Constructor WrongAnimal" << std::endl << reset;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
    *this = obj;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << BRED << "Destructor WrongAnimal" << std::endl << reset;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
    static_cast<void>(obj);
    return *this;
}

void WrongAnimal::makeSound(void) const {
    std::cout << BGRN << "WrongAnimal make sound : ????? " << std::endl << reset;
}

 std::string  WrongAnimal::getType(void) const {
    return _type;
}
