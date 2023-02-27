#include "easyfind.hpp"



int main(void) {
    srand(time(0));

    {
        std::vector<int> ctn;
        std::vector<int>::iterator i;

        std::cout << "---- Container of type vector ----" << std::endl;
        for (int i = 0; i < 10; i++)
            ctn.push_back(rand() % 10);

        std::cout << "---- Content container of type vector ----" << std::endl;
        for (i = ctn.begin(); i != ctn.end(); ++i)
            std::cout << *i << " " << std::endl;

        int randomNumber = rand() % 20;
        std::cout << "search value " << randomNumber << std::endl;

        try {
             i = easyfind(ctn, randomNumber);
             std::cout << "find " << randomNumber << " at index " << std::distance(ctn.begin(), i) << std::endl;
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    
    std::cout << std::endl;

    {
        std::list<int> ctn;
        std::list<int>::iterator i;

        std::cout << "---- Container of type list ----" << std::endl;
        for (int i = 0; i < 10; i++)
            ctn.push_back(rand() % 10);

        std::cout << "---- Content container of type list ----" << std::endl;
        for (i = ctn.begin(); i != ctn.end(); ++i)
            std::cout << *i << " " << std::endl;

        int randomNumber = rand() % 20;
        std::cout << "search value " << randomNumber << std::endl;

        try {
             i = easyfind(ctn, randomNumber);
             std::cout << "find " << randomNumber << " at index " << std::distance(ctn.begin(), i) << std::endl;
        }
        catch (std::exception &e) {
            std::cerr << e.what();
        }
    }
    return 0;
}
