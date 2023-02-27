#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void  separator(int choice)
{
    if (choice < 4)
        std::cout << "\033[1;36m";
    else
        std::cout << "\033[1;35m";
    switch (choice)
    {
        case 1:
            std::cout << std::endl << "______________ Animal constructor  ____________________" << std::endl << std::endl;
            break ;
        case 2:
            std::cout << std::endl << "______________ Animal functions _______________________" << std::endl << std::endl;
            break ;
        case 3:
            std::cout << std::endl << "______________ Animal destructor ______________________" << std::endl << std::endl;
            break ;
        case 4:
            std::cout << std::endl << "______________ Wrong constructor  _____________________" << std::endl << std::endl;
            break ;
        case 5:
            std::cout << std::endl << "______________ Wrong functions  _______________________" << std::endl << std::endl;
            break ;
        case 6:
            std::cout << std::endl << "______________ Wrong destructor _______________________" << std::endl << std::endl;
        default:
            break ;
    }
    std::cout << "\033[0m";
}

int main( void )
{
    separator(1);
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();


    separator(2);
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    separator(3);
    delete meta;
    delete j;
    delete i;


    separator(4);
    const WrongAnimal*   weird = new WrongCat();
    const WrongAnimal*   wanimal = new WrongAnimal();


    separator(5);
    std::cout << weird->getType() << " " << std::endl;
    std::cout << wanimal->getType() << " " << std::endl << std::endl;

    weird->makeSound();
    wanimal->makeSound();


    separator(6);
    delete weird;
    delete wanimal;

    std::cout << std::endl;
    return (0);
}
