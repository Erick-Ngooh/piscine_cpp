/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:15:37 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 04:23:53 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>
#include <iostream>
#include "colorCode.hpp"

int main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << BBLU << "PRINT MEMORY ADDRESS : " << std::endl << reset;
	std::cout << BWHT << "ADD STRING : " << &str << std::endl;
	std::cout << BWHT << "ADD PTR    : " << stringPTR << std::endl;
	std::cout << BWHT << "ADD REF    : " << &stringREF << std::endl << std::endl;

	std::cout << BBLU << "PRINT VALUE MEMORY : " << std::endl << reset;
	std::cout << BWHT << "VAL STRING : " << str << std::endl << reset;
	std::cout << BWHT << "VAL PTR    : " << *stringPTR << std::endl << reset;
	std::cout << BWHT << "VAL REF    : " << stringREF << std::endl << reset;
	return 0;
}
