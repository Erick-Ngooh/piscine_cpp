#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    for (int i = 0; i < 4; i++)
       _materiaSrc[i] = NULL;
//    std::cout << "constructor concrete MateriaSource" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
    for (int i = 0; i < 4; i++)
       _materiaSrc[i] = NULL;
    *this = obj;
 //   std::cout << "constructor copy concrete Cure" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj) {
    for (int i = 0; i < 4; i++) {
        if (_materiaSrc[i]) {
            delete _materiaSrc[i];
            if (obj._materiaSrc[i]->getType() == "ice")
                _materiaSrc[i] = new Ice();
            else if (obj._materiaSrc[i]->getType() == "cure")
                _materiaSrc[i] = new Cure();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < 4; i++)
        if (_materiaSrc[i])
            delete _materiaSrc[i];
  //  std::cout << "destructor concrete MateriaSource" << std::endl;
}

void MateriaSource::learnMateria(AMateria *obj) {
    if (!obj)
        return ;
    int i = -1;
    while (i < 4 && _materiaSrc[i])
        i++;
    if (i < 4){
        _materiaSrc[i] = obj;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    int i = -1;

    while (i < 4 && _materiaSrc[i] && _materiaSrc[i]->getType() != type)
        i++;
    if (i < 4 && type == "ice") {
        //std::cout << "create new items of type : " << type << std::endl;
        return  new Ice();
    }
    else if (i < 4 && type == "cure") {
        //std::cout << "create new items of type : " << type << std::endl;
        return  new Cure();
    }
    return 0;
}
