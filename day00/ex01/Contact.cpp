/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:13:30 by engooh            #+#    #+#             */
/*   Updated: 2022/12/05 22:09:32 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
# include "Contact.hpp"

Contact::Contact(void) {
	this->_init[1] = 0;
	this->_init[0] = 127;
	this->_lastName = this->_init;
	this->_nickName = this->_init;
	this->_firstName = this->_init;
	this->_phoneNumber = this->_init;
	this->_darkestSecret = this->_init;
	return ;
}

Contact::~Contact(void) {
	return ;
}

void Contact::getFirstName(void) const {
	std::cout << BBLU << "firstName          : " << this->_firstName << reset; 
	return ;
}

void	Contact::getLastName(void) const {
	std::cout << BBLU << "LastName          : " << this->_lastName << reset; 
	return ;
}

void	Contact::getNickName(void) const {
	std::cout << BBLU << "NickName          : " << this->_nickName << reset; 
	return ;
}

void	Contact::getPhoneNumber(void) const {
	std::cout << BBLU << "PhoneNumber          : " << this->_phoneNumber << reset; 
	return ;
}

void	Contact::getDarkestSecret(void) const {
	std::cout << BBLU << "DarkestSecret          : " << this->_darkestSecret << reset; 
	return ;
}

void	Contact::getInfoContact(void) const {
	if (!this->_firstName.compare(this->_init)) {
		std::cout << BRED << "Error 43: Contact Dont exist !" << std::endl << reset;
		return ;
	}
	this->getFirstName();
	std::cout << std::endl;
	this->getLastName();
	std::cout << std::endl;
	this->getNickName();
	std::cout << std::endl;
	this->getPhoneNumber();
	std::cout << std::endl;
	this->getDarkestSecret();
	std::cout << std::endl;
	return ;
}

int	Contact::getInfoContactFormat(int index) const {
	std::string	content;

	if (!this->_firstName.compare(this->_init))
		return 0;
	content = ('0' + index);
	printformat(content);
	std::cout << "|";
	content = this->_firstName;
	printformat(content);
	std::cout << "|";
	content = this->_lastName;
	printformat(content);
	std::cout << "|";
	content = this->_nickName;
	printformat(content);
	std::cout << "|";
	std::cout << std::endl;
	for (int i = 0; i < 44; i++)
		std::cout << BWHT << "-" << reset;
	std::cout << std::endl;
	return 1;
}

int		Contact::setInfoContact(std::string const content, int flag) {
	if (flag == 0)
		return this->_firstName = content, 1;
	if (flag == 1)
		return this->_lastName = content, 1;
	if (flag == 2)
		return this->_nickName = content, 1;
	if (flag == 3)
		return this->_phoneNumber = content, 1;
	if (flag == 4)
		return this->_darkestSecret = content, 1;
	return (0);
}
