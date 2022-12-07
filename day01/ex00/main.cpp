/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:54:28 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 04:20:43 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main(void) {
	Zombie *ptr1;
	Zombie *ptr2;
	Zombie *ptr3;

	Zombie zombie1 = Zombie("zombie1");
	Zombie zombie2 = Zombie("zombie2");
	Zombie zombie3 = Zombie("zombie3");
	zombie1.announce();
	zombie2.announce();
	zombie3.announce();
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	ptr1 = zombie1.newZombie("zombie1_child");
	ptr2 = zombie2.newZombie("zombie2_child");
	ptr3 = zombie3.newZombie("zombie3_child");
	ptr1->announce();
	ptr2->announce();
	ptr3->announce();
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	zombie1.randomChump("zombie1_bis");
	zombie2.randomChump("zombie2_bis");
	zombie3.randomChump("zombie3_bis");

	std::cout << std::endl;
	std::cout << std::endl;
	
	delete ptr1;
	delete ptr2;
	delete ptr3;
	
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
