/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:59:15 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 04:13:38 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ios>
#include <iostream>
#include "colorCode.hpp"

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Zombie {

	public:
		Zombie(std::string name);
		~Zombie(void);
		void		announce(void);
		Zombie* newZombie(std::string name);
		void		randomChump(std::string name);

	private:
		std::string _name;
};

#endif
