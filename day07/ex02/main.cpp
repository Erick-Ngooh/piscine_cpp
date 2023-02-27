#include "Array.hpp"
#include <exception>
#include <string>
#include <cstdlib>
#define MAX_VAL 750

template<typename T>
std::ostream &operator<<(std::ostream &out, Array<T> &obj) {
    out << "print value : " << std::endl;
    if (obj.size() > 0) 
        for (unsigned int i = 0; i < obj.size(); i++)
            out << obj[i] << " ";
    else
        out << "tab empty";
    return out;
}

int main(void) {
    srand(time(0));

    {
        Array<int> array(10);
        std::cout << "tab of type int of size " << array.size() << std::endl;
        for (unsigned int i = 0; i < array.size(); i++)
            array[i] = rand() % 10;
        std::cout << array << std::endl << std::endl;
    }
    {
        Array<float> array(8);
        std::cout << "tab of type float of size " << array.size() << std::endl;
        for (unsigned int i = 0; i < array.size(); i++)
                array[i] = static_cast<float>(std::rand()) / RAND_MAX;
        std::cout << array << std::endl << std::endl;
    }
    {
        try {
            Array<char> array(12);
            std::cout << "tab of type char of size " << array.size() << std::endl;
            array[12] = static_cast<char>(std::rand()) / 127;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl << std::endl;
        }
    }
    return 0;
}
