#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public: 
        Cat(void);
        Cat(const Cat &obj);
        virtual ~Cat(void);
        Cat &operator=(const Cat &obj);
        std::string getType(void) const;
        void makeSound(void) const;   
};

#endif
