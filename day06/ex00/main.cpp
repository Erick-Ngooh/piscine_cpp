# include <string.h>
# include <cctype>
# include <cstdlib>
# include <iostream>
# include <cfloat>
# include <limits>
# include <climits>
#include <cmath>


#define nanf log(-1.0f)
#define Pinff (1.0f/0.0f)
#define Ninff (-1.0f/0.0f)


int strIsDigit(std::string str, int len) {
    int i = 0;

    if (str[i] == '-')
        i++;
    for (i = i; i < len; i++)
        if (!isdigit(str.at(i)))
            return 0;
    return 2;
}

int strIsFloat(std::string str, int len)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    if (!str.compare("nanf") || !str.compare("-inff") || !str.compare("+inff"))
        return 3;
    if (len < 4)
        return 0;
    for (i = i; i < len && isdigit(str[i]); i++) {}
    if (str[i] == '.' && isdigit(str[i - 1])) {
        for (i = i + 1; i < len && isdigit(str[i]); i++) {}
        if (str[i] == 'f' && i + 1 == len && isdigit(str[i - 1]))
            return 3;
    }
    return 0;
}

int strIsDouble(std::string str, int len)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    if (!str.compare("nan") || !str.compare("-inf") || !str.compare("+inf"))
        return 4;
    if (len < 3)
        return 0;
    for (i = i; i < len && isdigit(str[i]); i++) {}
    if (str[i] == '.' && isdigit(str[i - 1])) {
        for (i = i + 1; i < len; i++)
            if (!isdigit(str[i]))
                return 0;
        return 4;
    }
    return 0;
}

int strIsChar(std::string str, int len) {
    if (str.at(0) == '\'' && str.at(1) == '\'' && len == 3)
       return (1);
    if (len == 1)
        return 1;
    return (0);
}

int getType(std::string str, int len) {
    double      nbrDbl;
    float       nbrfloat;
    long        nbrlng;
    int         nbrint;
    char        Chr;

    if (strIsDigit(str, len)) {
        nbrint = atoi(str.c_str());
        
        if (nbrint > 31 && nbrint < 127)
            std::cout << "char: " << static_cast<char>(nbrint) << std::endl;
        else if (nbrint < -128 && nbrint > 127)
            std::cout << "char: " << "overflow" << std::endl;
        else
            std::cout << "char: " << "Non displayable" << std::endl;

        nbrlng = atol(str.c_str());
        if (nbrlng > std::numeric_limits<int>::max() || nbrlng < std::numeric_limits<int>::min())
            std::cout << "int: " << "overflow" << std::endl; 
        else
            std::cout << "int: " << nbrint << std::endl; 

        std::cout << "float: " << static_cast<float>(nbrint) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(nbrint) << ".0" << std::endl;
    }
    else if (strIsFloat(str, len)) {
        nbrfloat = strtof(str.c_str(), NULL);

        if (nbrfloat == Ninff || nbrfloat == Pinff || std::isnan(nbrfloat))
		    std::cout << "char: " << "imposible" << std::endl;
        else if (nbrfloat < -128.0f && nbrfloat > 128.0f)
            std::cout << "char: " << "overflow" << std::endl;
        else if (nbrfloat > 31.0f && nbrfloat < 127.0f)
            std::cout << "char: " << static_cast<char>(nbrfloat) << std::endl;
        else
		    std::cout << "char: " << "Non displayable" << std::endl;

        if (nbrfloat == Ninff || nbrfloat == Pinff || std::isnan(nbrfloat))
            std::cout << "int: " << "imposible" << std::endl;
        else if (static_cast<long int>(nbrfloat) > std::numeric_limits<int>::max()) 
            std::cout << "int: " << "overflow" << std::endl;
        else if (static_cast<long int>(nbrfloat) < std::numeric_limits<int>::min())
            std::cout << "int: " << "overflow" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(nbrfloat) << std::endl;

        if (nbrfloat == Ninff || nbrfloat == Pinff || std::isnan(nbrfloat))
            std::cout << "float: " << nbrfloat << "f" << std::endl;
        else if (nbrfloat > std::numeric_limits<float>::max())
            std::cout << "float: " << "overflow" << std::endl;
        else if ( nbrfloat < 0 && nbrfloat > std::numeric_limits<float>::min())
            std::cout << "float: " << "overflow" << std::endl;
        else
            std::cout << std::fixed << "float: " << nbrfloat << "f" << std::endl;

        nbrDbl = nbrfloat;
        if (nbrfloat == Ninff || nbrfloat == Pinff || std::isnan(nbrfloat))
            std::cout << "double: " << static_cast<double>(nbrfloat) << std::endl;
        else if (nbrDbl > std::numeric_limits<double>::max())
            std::cout << "double: " << "overflow" << std::endl;
        else if (nbrDbl < 0 && nbrDbl > std::numeric_limits<double>::min()) 
            std::cout << "double: " << "overflow1" << std::endl;
        else
            std::cout << std::fixed << "double: " << static_cast<double>(nbrfloat) << std::endl;
    }
    else if (strIsDouble(str, len)) {
        nbrDbl = strtod(str.c_str(), NULL);

        if (nbrDbl == -HUGE_VAL || nbrDbl == HUGE_VAL || std::isnan(nbrDbl))
		    std::cout << "char: " << "imposible" << std::endl;
        else if (nbrDbl < -128.0 && nbrDbl > 127.0)
            std::cout << "char: " << "overflow" << std::endl;
        else if (nbrDbl > 31.0 && nbrDbl < 127.0)
            std::cout << "char: " << static_cast<char>(nbrDbl) << std::endl;
        else
		    std::cout << "char: " << "Non displayable" << std::endl;

        if (nbrDbl == -HUGE_VAL || nbrDbl == HUGE_VAL || std::isnan(nbrDbl))
            std::cout << "int: " << "imposible" << std::endl;
        else if (static_cast<long int>(nbrDbl) > std::numeric_limits<int>::max()) 
            std::cout << "int: " << "overflow" << std::endl;
        else if (static_cast<long int>(nbrDbl) < std::numeric_limits<int>::min())
            std::cout << "int: " << "overflow" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(nbrDbl) << std::endl;

        if (nbrDbl == -HUGE_VAL || nbrDbl == HUGE_VAL || std::isnan(nbrDbl))
            std::cout << "float: " << nbrDbl << "f" << std::endl;
        else if (nbrDbl > std::numeric_limits<float>::max())
            std::cout << "float: " << "overflow" << std::endl;
        else if (nbrDbl < 0 && nbrDbl > std::numeric_limits<float>::min())
            std::cout << "float: " << "overflow1" << std::endl;
        else
            std::cout << std::fixed << "float: " << nbrDbl << "f" << std::endl;
        
        if (nbrDbl == -HUGE_VAL || nbrDbl == HUGE_VAL || std::isnan(nbrDbl))
            std::cout << "double: " << nbrDbl << std::endl;
        else if (nbrDbl > std::numeric_limits<double>::max())
            std::cout << "double: " << "overflow" << std::endl;
        else if (nbrDbl < 0 && nbrDbl > std::numeric_limits<double>::min())
            std::cout << "double: " << "overflow" << std::endl;
        else
            std::cout << std::fixed << "double: " << nbrDbl << std::endl;
    }
    else if (strIsChar(str, len)) {
        Chr = str.at(0);
        std::cout << "char: " << Chr << std::endl;
	    std::cout << "int: " << static_cast<int>(Chr) << std::endl;
	    std::cout << "float: " << static_cast<float>(Chr) << ".0f" << std::endl;
	    std::cout << "double: " << static_cast<double>(Chr) << ".0" << std::endl;
    }
    return 0;
}

int main(int ac, char **av) 
{
    if (ac != 2)
        return 0;

    std::string str(av[1]);
    getType(str, str.length());
    return 0;
}
