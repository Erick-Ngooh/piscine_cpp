#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal {
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &obj);
        virtual ~WrongAnimal(void);
        WrongAnimal &operator=(const WrongAnimal &obj);
        std::string getType(void) const;
        void makeSound(void) const;

    protected:
        std::string _type;
};

#endif
