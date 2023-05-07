#include "../include/RPN.hpp"

bool rgetline(std::stringstream &ss, std::string &line, char c = ' ') {
	std::string str = ss.str();

	std::size_t pos = str.rfind(c);
	if (pos == std::string::npos && !str.size())
		return false;
	if (pos == std::string::npos) {
		line = str.substr(0);
		str.erase(0, str.size());
		ss.str(str);
		return true;
	}
	line = str.substr(pos + 1);
	str.erase(pos, str.size());
	ss.str(str);
	return true;
}

int main(int ac, char **av) {
	if (ac != 2) return std::cout << "bad argument" << std::endl, 1;

	std::string             tmp, operators;
	std::stack<int>         operandes;
	std::stringstream       arg(av[1]);

	while (rgetline(arg, tmp)) {
		if (tmp.size() != 1 || !strchr("0123456789+-*/", tmp[0])) {
			std::cout << "Error" << std::endl;
			return 2;
		}
		if (isdigit(tmp.at(0)))
			operandes.push(atoi(tmp.c_str()));
		else
			operators += tmp;
		if (operandes.size() > 0 && (operandes.top() > 9 || operandes.top() < 0)) {
			std::cout << "Error" << std::endl;
			return 3;
		}
	}

	int i = 0, nbr1 = operandes.top();
	while (operandes.size() != 1) {
		std::cout << "nbr: " << nbr1 << std::endl;
		operandes.pop();
		if (operators.at(i) == '-')
			nbr1 -= operandes.top();
		else if (operators.at(i) == '+')
			nbr1 += operandes.top();
		else if (operators.at(i) == '*')
			nbr1 *= operandes.top();
		else if (operators.at(i) == '/')
			nbr1 /= operandes.top();
		if (operators.at(i))
			i++;
		operandes.pop();
		operandes.push(nbr1);
		std::cout << "nbr: " << nbr1 << std::endl;
	}
	return 4;
}
