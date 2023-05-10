#include "../include/RPN.hpp"

int set_stack(std::stringstream &ss, std::stack<int> &stck1, std::stack<int> &stck2) {
    int res = 1;
    std::string tmp;

    if (getline(ss, tmp, ' ')) {
        res = set_stack(ss, stck1, stck2);
        if (!(res == 1 && tmp.size() == 1 && strchr("0123456789+-*/", tmp[0])))
            return 0;
        isdigit(tmp[0]) ? stck1.push(atoi(tmp.c_str())) : stck2.push(tmp[0]);
    }
    else if (!stck1.empty() && !stck2.empty())
        return 0;
    return res;
}

int main(int ac, char **av) {
    if (ac != 2)
        return 1;

    std::stack<int> facteur, operators;
    std::stringstream ss(av[1]);
    int res, val;

    if (!set_stack(ss, facteur, operators))
        return std::cout << "Error" << std::endl, 2;
    res = facteur.top();
    facteur.pop();
    while (!operators.empty()) {
        if (!facteur.empty()) {
            val = operators.top();
            if (val == '+')
                res += facteur.top();
            else if (val == '-')
                res -= facteur.top();
            else if (val == '*')
                res *= facteur.top();
            else if (val == '/')
                res /= facteur.top();
            facteur.pop();
        }
        operators.pop();
    }
    std::cout << res << std::endl;
    return 0;
}
