#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), name(name) {
    std::cout <<  BGRN << "DiamondTrap default constructor " << _Name << std::endl << reset;
    _HitPoint = FragTrap::_HitPoint;
    _EnergyPoint = ScavTrap::_EnergyPoint;
    _AttackDamage = FragTrap::_AttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj) {
    std::cout << BGRN << "DiamondTrap constructor copy " << _Name << std::endl << reset;
    *this = obj;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << BRED << "FragTrap destructor " << _Name << std::endl << reset;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
    std::cout << BGRN << "equalizer operator overload DiamondTrap " << std::endl << reset;
    name = obj.name;
    _HitPoint = obj._HitPoint;
    _EnergyPoint = obj._EnergyPoint;
    _AttackDamage = obj._AttackDamage;
    return *this;
}

/* --------------------------------------------------------------------------------------- */ 

void DiamondTrap::whoAmI(void) {
    std::cout << BWHT << "I am " << name << std::endl << reset;
}

void DiamondTrap::attack(const std::string& target) {
    std::cout << BMAG << "DiamondTrap attack by " << name << std::endl << reset;
    ScavTrap::attack(target);
}
