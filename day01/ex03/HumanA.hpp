/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:09:31 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 04:11:09 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA {

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void	attack(void);

	private:
		std::string _name;
		Weapon			&_weapon;
};

#endif
