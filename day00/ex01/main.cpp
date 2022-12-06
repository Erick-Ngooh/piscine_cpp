/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:37:57 by engooh            #+#    #+#             */
/*   Updated: 2022/12/05 22:05:35 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"


void	printformat(std::string content) {
	if (content.length() < 10) {
		std::string str(10 - content.length(), ' ');
		str.insert(str.end(), content.begin(), content.end());
		std::cout << BBLU << str.substr(0, 10) << reset;
	}
	else 
	{
		std::string str = content.substr(0, 9);	
		str.push_back('.');
		std::cout << BBLU << str << reset;
	}
}

int	runPhonebook(void) {
	std::string		buf;
	PhoneBook			phoneBook;

	std::cout << BRED << "Please write one of the following: SEARCH, ADD, EXIT. " << std::endl;
	while (42)
	{
		std::cout << BGRN << "PhoneBook $> " << reset;
		if (!std::getline(std::cin, buf))
			return 0;
		if (!buf.compare("ADD"))
			phoneBook.addContact();
		else if (!buf.compare("SEARCH"))
			phoneBook.searchContact();
		else if (!buf.compare("EXIT")) {
			std::cout << BMAG << "Quit PhoneBook" << std::endl;
			return 1;
		}
		else
			std::cout << BRED << "Error 46: Invalid Command" << std::endl;
	}
}

int main(void) {

	return	runPhonebook();
}
