/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:55:39 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 04:11:03 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << BRED << "Weapon : " << type << " constructor " << std::endl << reset;
	return ;
}

Weapon::~Weapon() {
	std::cout << BRED << "Weapon destructor" << std::endl << reset;
	return ;
}

void	Weapon::setType(std::string type)  {
	this->_type = type;
	return ;
}

std::string	const &Weapon::getType(void) {
	std::string &ref = this->_type;
	return ref;
}
