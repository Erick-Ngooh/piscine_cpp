#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string str) :  _Name(str), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0) {
    std::cout <<  BGRN << "ClapTrap default constructor " << _Name << std::endl << reset;
}

ClapTrap::ClapTrap(const ClapTrap &obj) {
    *this = obj;
    std::cout << BGRN << "ClapTrap copy constructor " << _Name << std::endl << reset;
}

ClapTrap::~ClapTrap(void) {
    std::cout << BRED << "ClapTrap destructor " << _Name << std::endl << reset;
}

/* ------------------------------------------------------------------------------ */

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
    std::cout << BGRN << "ClapTrap equalizer operator overload" << std::endl << reset;
    _Name = obj._Name;
    _HitPoint = obj._HitPoint;
    _EnergyPoint = obj._EnergyPoint;
    _AttackDamage = obj._AttackDamage;
    return *this;
}

/* ------------------------------------------------------------------------------ */

int  ClapTrap::getAttack(void) const {
    return _AttackDamage;
}
/* ------------------------------------------------------------------------------ */

void ClapTrap::attack(const std::string& target) {
    if (_HitPoint <= 0) {
        std::cout << BWHT << "ClapTrap " << _Name << " is dead" << std::endl << reset;
        return ;
    }
    _EnergyPoint--;
    std::cout << BWHT << "ClapTrap " << _Name << " attack " << target << " causing " << ++_AttackDamage << " points of damage!";
    std::cout << std::endl << _Name << " have " << _EnergyPoint << " EnergyPoint " << std::endl << reset;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _HitPoint -= amount;
    if (_HitPoint <= 0) {
        std::cout << BWHT << _Name << " is dead" << std::endl << reset;
        return ;
    }
    std::cout << BWHT << "ClapTrap " << _Name << " take damage and lost " << amount << " causing " << _HitPoint << " points of life";
    std::cout << std::endl << reset;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_HitPoint <= 0) {
        std::cout << BWHT << _Name << " is dead" << std::endl << reset;
        return ;
    }
    _HitPoint += amount;
    _EnergyPoint--;
    std::cout << BWHT << "ClapTrap " << _Name << " this Repaired and win " << amount << " causing " << _HitPoint << " points of life!"; 
    std::cout << std::endl << _Name << " have " << _EnergyPoint << " EnergyPoint " << std::endl << reset;
}
