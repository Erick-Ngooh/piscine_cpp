#include <iostream>
#include <cmath>

int main(void) {

    int n = 42;
    float f = 42.42;
    int fix;

    std::cout << "value n: " << n << std::endl;
    fix = n << 8;
    std::cout << "after bitshift value fix: " << fix << std::endl;
    n = fix >> 8;
    std::cout << "value n: " << n << std::endl;
    
    std::cout << "value f: " << f << std::endl;
    fix = roundf(f * 256.0);
    std::cout << "value fix: " << fix << std::endl;
    f = float(fix >> 8);
    std::cout << "value f: " << f << std::endl;
    return 0;
}
