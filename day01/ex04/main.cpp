/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:32:31 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 06:56:25 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>
#include <string>
#include <iostream>
#include <fstream> 
#include "./colorCode.hpp"


int	main (int ac, char **av) {
	if (ac != 3)
		return 1;
	
	std::ifstream	ifs(av[1]);
	if (!ifs.is_open()) {
		std::cerr << BRED << " error : the file could not be opened" << std::endl;
		return 1;
	}

	std::string filename(av[1]);
	filename = filename.append(".replace"); 
	std::ofstream ofs(filename.c_str());
	if (!ofs.is_open()) {
		std::cerr << BRED << " error : the file could not be created" << std::endl;
		return 1;
	}

	std::string	s1(av[2]);
	std::string	s2(av[3]);
	std::string buf;
	size_t			pos = 0;

	while (ifs)	{
		if (!getline(ifs, buf))
			return 1;
		while ( (pos = buf.find(s1, 0)) != std::string::npos) {
				buf.erase(pos, s2.length());
				buf.insert(pos, s2);
		}
		ofs << BWHT << buf << std::endl;
	}

	return 0;
}
