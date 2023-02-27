#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP 

#include "Interface.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
    private: 
        AMateria *_materiaSrc[4];

    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &obj);
        MateriaSource &operator=(const MateriaSource &obj);
        virtual ~MateriaSource();
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};

#endif
