#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "colorCode.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Animal {
    public:
        Animal(void);
        Animal(const Animal &obj);
        virtual ~Animal(void);
        Animal &operator=(const Animal &obj);
        virtual void makeSound(void) const;
        virtual std::string getType(void) const;
        virtual void getBrain(int i) const;
        virtual void setBrain(std::string str);

    protected:
        std::string _type;
};

#endif
