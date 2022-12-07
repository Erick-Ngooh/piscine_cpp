/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:54:28 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 01:13:45 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main(void) {
	Zombie	first = Zombie("zombie_zero");
	std::cout << std::endl;

	Zombie	*horde = first.zombieHorde(42, "Zombie_horde");
	std::cout << std::endl;
	
	for (int i = 0; i < 42; i++)
		horde[i].announce();
	std::cout << std::endl;

	delete [] horde;
	std::cout << std::endl;
	return 0;
}
