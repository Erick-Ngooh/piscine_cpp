#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <iostream>
#include "colorCode.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstdio>

class ICharacter;

class AMateria {
    protected:
        std::string _type; 

    public:
        AMateria(std::string const &type);
        virtual ~AMateria(void);
        std::string const & getType(void) const;
        virtual AMateria* clone(void) const = 0;
        virtual void use(ICharacter& target) = 0;
};
 
class ICharacter {
    public:
        virtual ~ICharacter(void);
        virtual std::string const &getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

class IMateriaSource {
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
