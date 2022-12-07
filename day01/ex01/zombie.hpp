/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:59:15 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 04:12:25 by engooh           ###   ########.fr       */
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
		Zombie(void);
		~Zombie(void);
		void		announce(void);
		void		randomChump(std::string name);
		void		setName(std::string name);
		Zombie	*newZombie(std::string name);
		Zombie	*zombieHorde(int N, std::string name);

	private:
		std::string _name;
};

#endif
