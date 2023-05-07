#include "../include/BitcoinExchange.hpp"

long checkDate(std::string str) {
    char                    dash;
    int                     year, month ,day;
    std::stringstream       date(str);

    date >> year >> dash >> month >> dash >> day;
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        return 0;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return 0;
    } else if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) && day > 29) {
        return 0;
    } else if (month == 2 && day > 28)
            return 0;
    return (year * 525600) + (month * 43830) + (day * 1440);
}

int main(int ac, char **av) {
    if (ac != 2) return 1;
    std::ifstream input(av[1]);
    if (!input.is_open()) return 1;
    std::ifstream in("db/data.csv");
    if (!in.is_open()) return 2;

    const char                                *pattern = "^([0-9]{4}-[0-9]{2}-[0-9]{2}),([0-9]*|([0-9]+.[0-9]+)*)$";
    long                                      finaldate;
    float                                     finalprice;
    regex_t                                   regex, regex1;
    std::string                               date, price, line;
    std::map<int, float>              db; 
    std::map<int, float>::iterator    it; 

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) return 1;
    std::getline(in, line);
    if (line != "date,exchange_rate") {
        std::cerr << "Error: " << line << " Bad syntaxe data base csv" << std::endl;
        return 3;
    }
    while(std::getline(in, line)) {
        if (regexec(&regex, line.c_str(), 0, NULL, 0) != 0) {
            std::cerr << "Error: {" << line << "} Bad syntaxe data base csv" << std::endl;
            return 4;
        } 
        std::stringstream               ss(line);
        std::getline(ss, date,  ',');
        std::getline(ss, price, ','); 
        if (!(finaldate = checkDate(date))) {
            std::cerr << "Error: {" << date << "} Date invalide in data base" << std::endl;
            return 5;
        }
        db[finaldate] = atof(price.c_str());
    }

    const char                                *pattern1 = "^([0-9]{4}-[0-9]{2}-[0-9]{2})$";
    pattern = "^([0-9]{4}-[0-9]{2}-[0-9]{2}) \\| (\\-?[0-9]*|(\\-?[0-9]+.[0-9]+)*)$";
    
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) return 1;
    if (regcomp(&regex1, pattern1, REG_EXTENDED) != 0) return 1;
    std::getline(input, line);
    if (line != "date | value") {
        std::cerr << "Error: bad input => " << line << std::endl;
        return 6;
    }
    while(std::getline(input, line)) {
        if (regexec(&regex, line.c_str(), 0, NULL, 0)) {
            if (regexec(&regex1, line.c_str(), 0, NULL, 0)) {
                std::cerr << "Error: bad input => {" << line << "}" << std::endl;
               return 7;
            }
        }
        std::stringstream               ss(line);
        std::getline(ss, date,  '|');
        std::getline(ss, price, '|'); 
        if (!(finaldate = checkDate(date))) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue ;
        } else if ((finalprice = atof(price.c_str())) < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue ;
        } else if (finalprice > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue ;
        }
        while ((it = db.find(finaldate)) == db.end())
            finaldate--;
        std::cout << date << "=>" << price << " = " << it->second * finalprice << std::endl;
    }

    return 0;
}
