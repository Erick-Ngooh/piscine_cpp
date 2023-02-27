#include "ScavTrap.hpp"

/* ----------------------------------------------------------------------------------------- */

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name) {
    _HitPoint = 100;
    _EnergyPoint = 20;
    _AttackDamage = 20;
    std::cout <<  BGRN << "ScavTrap default constructor " << _Name << std::endl << reset;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj) {
    std::cout <<  BGRN << "ScavTrap constructor copy " << _Name << std::endl << reset;
    *this = obj;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj) {
    std::cout << BGRN << "equalizer operator overload ScavTrap " << std::endl << reset;
    _Name = obj._Name;
    _HitPoint = obj._HitPoint;
    _EnergyPoint = obj._EnergyPoint;
    _AttackDamage = obj._AttackDamage;
    return *this;
}

ScavTrap::~ScavTrap(void) {
    std::cout << BRED << "ScavTrap destructor " << _Name << std::endl << reset;
}

/* ----------------------------------------------------------------------------------------- */

void    ScavTrap::guardGate(void) {
    std::cout << BWHT << " ScavTrap is Gate keeper mode " << std::endl;
}


void ScavTrap::attack(const std::string& target) {
    if (_HitPoint <= 0) {
        std::cout << BMAG << "ScavTrap " << _Name << " is dead" << std::endl << reset;
        return ;
    }
    _EnergyPoint--;
    std::cout << BMAG << "ScavTrap " << _Name << " attack " << target << " causing " << ++_AttackDamage << " points of damage!";
    std::cout << std::endl << _Name << " have " << _EnergyPoint << " EnergyPoint " << std::endl << reset;
}
