#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <iostream>

template<typename T>
void	print(T const &val){
	std::cout << val << std::endl;
}

template<typename T>
void	iter(T *tab, int size, void(&f)(T const &value))
{
	for (int i = 0; i < size; i++)
		f(tab[i]);
}

#endif
