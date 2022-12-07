/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:27:14 by engooh            #+#    #+#             */
/*   Updated: 2022/12/07 04:15:54 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
#include "Contact.hpp"

#ifndef  PHONEBOOK_H
#define  PHONEBOOK_H

class PhoneBook {

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	setIndex(void);
		int		getIndex(void) const;
		int		addContact(void);
		void	searchContact(void) const; 
		void	getInfoContactIndex(int index) const;

	private:
		int				_index;
		Contact 	_contacts[8];
};

#endif
