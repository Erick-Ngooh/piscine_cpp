#include "Character.hpp"

ICharacter::~ICharacter(void) {
    //std::cout << "destructor abstract ICharacter" << std::endl;
}

Character::Character(void) : _name("Nickname") {
    for (int i = 0; i < 4; i++)
            _materias[i] = NULL;
    //std::cout << "constructor concrete Character" << std::endl;
}

Character::Character(const std::string name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
    //std::cout << "constructor concrete Character" << std::endl;
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++)
        if (_materias[i] != NULL && printf("debug %d %p\n", i, _materias[i]))
            delete _materias[i];
}

Character::Character(const Character &obj) {
    for (int i = 0; i < 4; i++)
        _materias[i] = NULL;
    *this = obj;
    //std::cout << "constructor copy concrete Character" << std::endl;
}

Character &Character::operator=(const Character &obj) {
    _name = obj.getName();
    for (int i = 0; i < 4; i++) {
        if (_materias[i]) {
            delete _materias[i];
            if (obj._materias[i]->getType() == "ice")
                _materias[i] = new Ice();
            else if (obj._materias[i]->getType() == "cure")
                _materias[i] = new Cure();
        }
    }
    return *this;
}

std::string const &Character::getName(void) const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m)
        return ;
    int i = -1; 

    while (i < 4 && _materias[i])
        i++;
    if (i < 4)
        _materias[i] = m;
}

void Character::unequip(int idx) {
    if (idx >= 4 || idx < 0 || !_materias[idx]) 
        return ;
    _materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 4 || idx < 0 || !_materias[idx])
        return ;
    _materias[idx]->use(target);
}
