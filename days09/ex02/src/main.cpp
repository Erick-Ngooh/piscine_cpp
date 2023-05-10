#include "../include/RPN.hpp"

int merge_fusion(std::vector<int> &vec, unsigned int begin, unsigned int end) {
    int ref;

    if (begin) {
        std::cout << "ICI " << std::endl;
        for (unsigned int i = begin; i < end; i++) {
            std::cout << vec.at(i) << " " << end;
        }
        ref = (end >> 1);
        std::cout << std::endl;
        std::cout << std::endl;
        return merge_fusion(vec, begin, ref) + merge_fusion(vec, ref + 1, end);
    }
    return 1;
}

int main(int ac, char **av) {
    if (ac <= 1)
        return 1;

    std::stringstream   ss;
    std::vector<int>    vec;
    std::list<int>      lst;
    std::string         input;
    int                 val;

    for (int i = 1; i < ac; i++)
        ss << av[i] << " ";
    while (getline(ss, input, ' ')) {
        for (int i = 0; i < input[i]; i++)
            if (!isdigit(input.at(i)))
                return 2;
        val = atoi(input.c_str());
        lst.push_back(val);
        vec.push_back(val);
        std::cout << input << "  " <<  std::endl;
    }

    /*
    std::cout << "______________________________\n" << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " " << std::endl;
    }*/

    merge_fusion(vec, 0, vec.size());
    return 0;
}
