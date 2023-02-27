#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public: 
        Cat(void);
        Cat(const Cat &obj);
        virtual ~Cat(void);
        Cat &operator=(const Cat &obj);
        virtual std::string getType(void) const;
        virtual void        makeSound(void) const;   
        virtual void        getBrain(int i) const;
        virtual void        setBrain(std::string str);
    
    private: 
        Brain *_brain;
};

#endif
