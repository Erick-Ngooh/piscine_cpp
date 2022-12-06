/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:31:05 by engooh            #+#    #+#             */
/*   Updated: 2022/12/05 21:57:48 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_index = 0;
	return ;
}


PhoneBook::~PhoneBook(void) {
	return ;
}

int	PhoneBook::getIndex(void) const {
	return this->_index;
}

void	PhoneBook::setIndex(void) {
	if (this->_index == 7) {
		this->_index = 0;
		return ;
	}
	this->_index++;
	return ;
}

int	PhoneBook::addContact(void) {
	std::string content;

	for (int i = 0; i < 5; i++) {
		switch (i) {
			case 0:
				std::cout << BBLU << "Add firstName     : " << reset;
				break ;
			case 1:
				std::cout << BBLU << "Add lastName      : " << reset;
				break ;
			case 2:
				std::cout << BBLU << "Add nickName      : " << reset;
				break ;
			case 3:
				std::cout << BBLU << "Add phoneNumber   : " << reset;
				break ;
			case 4:
				std::cout << BBLU << "Add darkestSecret : " << reset; 
				break ;
		}
		if (!std::getline(std::cin, content))
			return 0;
		if (content.length() > 0)
			this->_contacts[this->_index].setInfoContact(content, i);
		else {
			std::cout << BRED << "Error 45: length info Contact too tittle" << std::endl << reset;
			i--;
		}
	}
	this->setIndex();
	return 0;
}

void	PhoneBook::searchContact(void) const {
	std::string	buf;

	for (int i = 0; i < 44; i++)
		std::cout << BWHT << "-" << reset;
	std::cout << std::endl;
	printformat("Index");
	std::cout << "|";
	printformat("Fname");
	std::cout << "|";
	printformat("Lname");
	std::cout << "|";
	printformat("Nname");
	std::cout << "|";
	std::cout << std::endl;
	for (int i = 0; i < 44; i++)
		std::cout << BWHT << "-" << reset;
	std::cout << std::endl;
	for (int i = 0; i < 8; i++) {
		if (!this->_contacts[i].getInfoContactFormat(i))
			break ;
	}
	std::cout << std::endl;
	std::cout << BGRN << "Search select Contact > " << reset;
	if (!std::getline(std::cin, buf))
			return ;
	for (char a[2] = "0"; a[0] <= '8'; a[0]++) {
		if (!buf.compare(a))
					this->getInfoContactIndex(atoi(a));
	}
}

void	PhoneBook::getInfoContactIndex(int index) const {
	if (index < 8)
		this->_contacts[index].getInfoContact();
}
