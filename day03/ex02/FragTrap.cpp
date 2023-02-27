
#include "FragTrap.hpp"

/* ----------------------------------------------------------------------------------------- */

FragTrap::FragTrap(std::string Name) : ClapTrap(Name) {
    _HitPoint = 100;
    _EnergyPoint = 100;
    _AttackDamage = 30;
    std::cout <<  BGRN << "FragTrap default constructor " << _Name << std::endl << reset;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj) {
    std::cout <<  BGRN << "FragTrap constructor copy " << _Name << std::endl << reset;
}

FragTrap &FragTrap::operator=(const FragTrap &obj) {
    std::cout << BGRN << "equalizer operator overload FragTrap " << std::endl << reset;
    _Name = obj._Name;
    _HitPoint = obj._HitPoint;
    _EnergyPoint = obj._EnergyPoint;
    _AttackDamage = obj._AttackDamage;
    return *this;
}

FragTrap::~FragTrap(void) {
    std::cout << BRED << "FragTrap destructor " << _Name << std::endl << reset;
}

/* ----------------------------------------------------------------------------------------- */

void FragTrap::highFivesGuys(void) {
    std::cout << "High Fives capicity " << _Name << " win 50 point life " << std::endl;
    _HitPoint += 50;
}

void FragTrap::attack(const std::string& target) {
    if (_HitPoint <= 0) {
        std::cout << BMAG << "FragTrap " << _Name << " is dead" << std::endl << reset;
        return ;
    }
    _EnergyPoint--;
    std::cout << BMAG << "FragTrap " << _Name << " attack " << target << " causing " << ++_AttackDamage << " points of damage!";
    std::cout << std::endl << _Name << " have " << _EnergyPoint << " EnergyPoint " << std::endl << reset;
}
