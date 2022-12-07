/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:09:21 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 04:11:05 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << BBLU << "HumanA "<< this->_name << " constructor" << std::endl << reset;
	return ;
}

HumanA::~HumanA(void) {
	std::cout << BBLU << "HumanA "<< this->_name << " destructor" << std::endl << reset;
	return ;
}

void	HumanA::attack(void) {
	std::cout << BWHT << this->_name << " attacks with their " << this->_weapon.getType() << std::endl << reset;
	return ;
}
