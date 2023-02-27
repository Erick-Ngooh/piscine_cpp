#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "Interface.hpp"

class Ice : public AMateria {
    public:
        Ice(void);
        Ice(const Ice &obj);
        Ice &operator=(const Ice &obj);
        virtual ~Ice(void);
        virtual AMateria* clone(void) const;
        virtual void use(ICharacter& target);
};

class Cure : public AMateria {
    public: 
        Cure(void);
        Cure(const Cure &obj);
        Cure &operator=(const Cure &obj);
        virtual ~Cure(void);
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif
