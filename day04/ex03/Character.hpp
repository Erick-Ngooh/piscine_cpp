#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"

class Character  : public ICharacter {
    private:
        AMateria    *_materias[4];
        std::string _name;

    public:
        Character(void);
        Character(const std::string name);
        Character(const Character &obj);
        Character &operator=(const Character &obj);
        virtual ~Character(void);
        virtual std::string const &getName(void) const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif
