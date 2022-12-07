/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:52:14 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 04:11:04 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_H
# define WEAPON_H

#include <ios>
#include <iostream>
#include "./colorCode.hpp"

class Weapon {

	public:
		~Weapon(void);
		Weapon(std::string type);
		std::string	const &getType(void);
		void				setType(std::string type);
	
	private:
		std::string _type;
};

#endif
