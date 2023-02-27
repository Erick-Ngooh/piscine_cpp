#include "iter.hpp"

int main(void) {
	{
		int	tab[5] = {0, 1, 2, 3 ,4};
		::iter(tab, 5, ::print);
		std::cout << std::endl << std::endl;
	}
	{
		float	tab[5] = {0.2f, 1.3f, 2.4f, 3.5f ,4.6f};
		::iter(tab, 5, ::print);
		std::cout << std::endl << std::endl;
	}
	{
		std::string	tab[5] = {"un", "two", "troi", "quatre", "cinq"};
		::iter(tab, 5, ::print);
		std::cout << std::endl << std::endl;
	}
}
