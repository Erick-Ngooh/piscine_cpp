#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void    getInfoAnimal(Animal &animal, std::string str) {
    animal.getType();
    animal.makeSound();
    animal.setBrain("eat eat eat ...." + str);
    std::cout << "idead number 0: ";
    animal.getBrain(0);
    std::cout << "idead number 99: ";
    animal.getBrain(99);
}

int main( void )
{
    Animal *tab[10];

    for (int i = 0; i < 5; i++)
        tab[i] = new Dog;
    std::cout << "-------------------------" << std::endl;
   
    for (int i = 5; i < 10; i++)
        tab[i] = new Cat;
    std::cout << "-------------------------" << std::endl;

    for (int i = 0; i < 10; i++)
        getInfoAnimal(*tab[i], "");
    std::cout << "-------------------------" << std::endl;

    Dog *ptr = dynamic_cast<Dog*>(tab[0]);
    if (ptr) {
        ptr = new Dog(*ptr);
        getInfoAnimal(*(dynamic_cast<Animal*>(ptr)), " Copy");
        delete ptr;
    }

    std::cout << "-------------------------" << std::endl;
    for (int i = 0; i < 5; i++)
        delete tab[i];
    std::cout << "-------------------------" << std::endl;

    for (int i = 5; i < 10; i++)
        delete tab[i];
    std::cout << "-------------------------" << std::endl;

    return 0;
}
