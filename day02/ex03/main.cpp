#include "Point.hpp"

int main( void )
{
    Point a(5.0f, 7.0f), b(8.0f, 6.0f), c(4.0f, 6.0f), g(5.08f, 6.26f);
    Point d(5.0f, 4.0f), e(6.0f, 3.0f), f(4.0f, 3.0f), h(7.2f, 4.18f);
    Point i(4, -2), j(2, -4), k(4, -4), l(3.42f, -3.24f);
    Point m(8, -2), n(7, -4), o(8, -4), p(8, -3);

    std::cout << "triangle : " << a << b << c << std::endl;
    std::cout << "Point    : " << g << (bsp(a, b, c, g) ? "is in triangle" : "is not triangle") << std::endl;
    
    std::cout << "triangle : " << d << e << f << std::endl;
    std::cout << "Point    : " << h << (bsp(d, e, f, h) ? "is in triangle" : "is not triangle") << std::endl;
    
    std::cout << "triangle : " << i << j << k << std::endl;
    std::cout << "Point    : " << l << (bsp(i, j, k, l) ? "is in triangle" : "is not triangle") << std::endl;
    
    std::cout << "triangle : " << m << n << o << std::endl;
    std::cout << "Point    : " << p << (bsp(m, n, o, p) ? "is in triangle" : "is not triangle") << std::endl;
    return 0;
}
