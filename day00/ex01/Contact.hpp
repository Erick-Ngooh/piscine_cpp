/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:49:47 by engooh            #+#    #+#             */
/*   Updated: 2022/12/05 21:36:56 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#	define CONTACT_CLASS_H

class Contact {

	public:
		Contact();
		~Contact();
		void	getFirstName(void) const;
		void	getLastName(void) const;
		void	getNickName(void) const;
		void	getPhoneNumber(void) const;
		void	getDarkestSecret(void) const;
		void	getInfoContact(void) const;
		int		getInfoContactFormat(int index) const; 
		int		setInfoContact(std::string const content, int const flag);
	
	private:
		char					_init[2];
		std::string		_lastName;	
		std::string		_nickName;	
		std::string		_firstName;	
		std::string		_phoneNumber;	
		std::string		_darkestSecret;	
};

#endif
