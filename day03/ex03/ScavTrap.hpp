#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

    public: 
        ScavTrap(std::string Name);
        ScavTrap(const ScavTrap &obj);
        ~ScavTrap(void);
        ScavTrap &operator=(const ScavTrap &obj);
        void    guardGate(void);
		void attack(const std::string& target);
};

#endif
