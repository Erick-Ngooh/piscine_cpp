#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << BGRN << "Constructor Brain" << std::endl << reset;
}

Brain::Brain(const Brain &obj) {
    *this = obj;
}

Brain::~Brain(void) {
    std::cout << BRED << "Destructor Brain" << std::endl << reset;
}

Brain &Brain::operator=(const Brain &obj) {
    for (int i = 0; i < 100; i++)
        _ideas[i] = obj._ideas[i];
    return *this;
}

std::string Brain::getIdea(int n) const {
      return _ideas[n];
}

void Brain::setIdea(int n, std::string idea) {
       _ideas[n] = idea;
}
