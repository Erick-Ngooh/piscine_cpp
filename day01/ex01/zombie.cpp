/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:01:11 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 04:26:26 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << BGRN << name << ": is born" <<  std::endl << reset;
	return ;
}

Zombie::Zombie(void) {
	std::cout << BGRN << "Zombie_horde is born" << std::endl << reset;
	return ;
}

Zombie::~Zombie(void) {
	std::cout << BRED << this->_name << ": has died" <<  std::endl << reset;
	return ;
}

void	Zombie::announce(void) {
	std::cout << BMAG  << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl << reset;
	return ;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
	return ;
}
