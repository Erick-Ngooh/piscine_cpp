#include "colorCode.hpp"
#include <iostream>
#include <string>

class ClapTrap {
	public:
		ClapTrap(std::string str);
		ClapTrap(const ClapTrap &obj);
        ClapTrap &operator=(const ClapTrap &obj);
		~ClapTrap(void);
        int  getAttack(void) const;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string _Name;
		int         _HitPoint;	
		int         _EnergyPoint;	
		int         _AttackDamage;	
};
