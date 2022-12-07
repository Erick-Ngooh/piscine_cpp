/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:56:07 by engooh            #+#    #+#             */
/*   Updated: 2022/12/06 21:41:23 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

void	Zombie::randomChump( std::string name ) {
	Zombie	zombie(name);
	zombie.announce();
	return ;
}
