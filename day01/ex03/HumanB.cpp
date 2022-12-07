/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:57:46 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 04:11:02 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	std::cout << BGRN << "HumanB "<< this->_name << " constructor" << std::endl << reset;
	return ;
}

HumanB::~HumanB(void) {
	std::cout << BGRN << "HumanB "<< this->_name << " destructor" << std::endl << reset;
	return ;
}

void	HumanB::setWeapon(Weapon &ptr) {
	this->_weapon = &ptr;
}

void	HumanB::attack(void) {
	std::cout << BWHT << this->_name << " attacks with their " << this->_weapon->getType() << std::endl << reset;
	return ;
}

