#include "Fixed.hpp"
#include <cmath>

class Point {
    public:
        Point(void);
        ~Point(void);
        Point(const Point &obj);
        Point(const float a, const float b);
        Point &operator=(const Point &obj);
        bool operator==(const Point &p) const;
        const Fixed &getFixedX(void) const;
        const Fixed &getFixedY(void) const;
        int   getarea(const Point &b, const Point &c) const;
        Fixed getdistance(const Point &p) const;

    private:
        const Fixed _x;
        const Fixed _y;
};

std::ostream &operator<<(std::ostream &out, const Point &p);
bool bsp(Point const a, Point const b, Point const c, Point const point);
