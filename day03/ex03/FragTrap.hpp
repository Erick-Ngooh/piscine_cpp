
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

    public: 
        FragTrap(std::string Name);
        FragTrap(const FragTrap &obj);
        ~FragTrap(void);
        FragTrap &operator=(const FragTrap &obj);
        void highFivesGuys(void);
		void attack(const std::string& target);
};
#endif

