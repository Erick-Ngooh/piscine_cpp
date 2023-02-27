#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "colorCode.hpp"
#include <iostream>
#include <string>

class Animal {
    public:
        Animal(void);
        Animal(const Animal &obj);
        virtual ~Animal(void);
        Animal &operator=(const Animal &obj);
        virtual std::string getType(void) const;
        virtual void makeSound(void) const;

    protected:
        std::string _type;
};

#endif
