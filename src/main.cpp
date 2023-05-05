#include "../include/RPN.hpp"

bool rgetline(std::stringstream &ss, std::string &line, char c = ' ')
{
    std::string str = ss.str();
    std::size_t pos = str.rfind(c);
    if (pos != std::string::npos) {
        line = str.substr(pos + 1);
        str.erase(pos, str.length());
        ss.str(str);
        return true;
    }
    return false;
}

int main(int ac, char **av) {
    if (ac != 2) return std::cout << "bad argument" << std::endl, 1;

    std::string             tmp;
    std::string             operators;
    std::stack<int>         operandes;
    std::stringstream       arg(av[1]);

    while (rgetline(arg, tmp)) {
        /*
        if (tmp.size() != 1 || !strchr("0123456789+-", tmp[0])) {
            std::cout << "Error" << std::endl;
            return 2;
        }
        operandes.push(atoi(tmp.c_str()));
        if (operandes.top() > 9 || operandes.top() < 0) {
            std::cout << "Error" << std::endl;
            return 2;
        }*/
        std::cout << tmp << std::endl;
    }

    return 0;
}
