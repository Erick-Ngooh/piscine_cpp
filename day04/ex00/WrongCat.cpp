#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
    _type = "WrongCat";
    std::cout << BGRN << "Constructor WrongCat" << std::endl << reset;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal() {
    *this = obj;
}

WrongCat::~WrongCat(void) {
    std::cout << BRED << "Destructor WrongCat" << std::endl << reset;
}

WrongCat &WrongCat::operator=(const WrongCat &obj) {
    static_cast<void>(obj);
    return *this;
}

void WrongCat::makeSound(void) const {
    std::cout << BGRN << "WrongCat make sound : Miaou Miaou ! " << std::endl << reset;
}

 std::string  WrongCat::getType(void) const {
    return _type;
}
