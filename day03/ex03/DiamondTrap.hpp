#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    public:
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &obj);
        ~DiamondTrap(void);
        DiamondTrap &operator=(const DiamondTrap &obj);
        void whoAmI(void);
		void attack(const std::string& target);

    private:
        std::string name;
};

#endif
