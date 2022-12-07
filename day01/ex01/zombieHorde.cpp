/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:32:35 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 01:08:17 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name) {
	Zombie	*horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}

	return horde;
}
