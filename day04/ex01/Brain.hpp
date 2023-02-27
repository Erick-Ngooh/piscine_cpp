#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "colorCode.hpp"
#include <iostream>
#include <string>

class Brain {
    public:
        Brain(void);
        Brain(const Brain &obj);
        ~Brain(void);
        Brain &operator=(const Brain &obj);
        std::string getIdea(int n) const;
        void        setIdea(int n, std::string idea);

    private:
        std::string _ideas[100];
};

#endif
