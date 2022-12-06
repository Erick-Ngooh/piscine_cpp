/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:47:00 by engooh            #+#    #+#             */
/*   Updated: 2022/11/29 04:02:16 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cctype>
#include <iostream>

int	main(int ac, char **av) {	
	if (ac < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}

	for (int i = 1; av[i]; i++)
		for (int j = 0; av[i][j]; j++)
			std::cout << (char)toupper(av[i][j]);

	std::cout << std::endl;
	return 0;
}
