#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

    public: 
        Dog(void);
        Dog(const Dog &obj);
        virtual ~Dog(void);
        Dog &operator=(const Dog &obj);
        virtual std::string getType(void) const;
        virtual void makeSound(void) const;
        virtual void    getBrain(int i) const;
        virtual void    setBrain(std::string str);

    private: 
        Brain *_brain;
};

#endif
