#include "Point.hpp"
#include <cstdio>

/* ------------------------------------------------- */

Point::Point(void) : _x(0), _y(0) {
}

Point::Point(const Point &obj) : _x(obj._x.toFloat()) , _y(obj._y.toFloat()){
}

Point::Point(const float a, const float b) : _x(a), _y(b) {
}

Point::~Point(void) {
}

/* ------------------------------------------------- */

Point &Point::operator=(const Point &obj) {
    static_cast<void>(obj);
    return *this ;
}

bool Point::operator==(const Point &p) const {
    return (_x.getRawBits() == p._x.getRawBits()) && (_y.getRawBits() == p._y.getRawBits());
}

std::ostream &operator<<(std::ostream &out, const Point &p) {
    out << "Point (" << p.getFixedX().toFloat() << "," << p.getFixedY().toFloat() << ") ";
    return out;
}

/* ------------------------------------------------- */

const Fixed &Point::getFixedX(void) const {
    return _x;
}

const Fixed &Point::getFixedY(void) const {
    return _y;
}

/* ------------------------------------------------- */

Fixed Point::getdistance(const Point &p) const {
    float dist = fabs(sqrt(pow(_x.getRawBits() - p._x.getRawBits(), 2)  + pow(_y.getRawBits() - p._y.getRawBits(), 2)));
    return Fixed(dist);
}

int Point::getarea(const Point &b, const Point &c) const {
    int x1 = this->getFixedX().getRawBits(), x2 = b.getFixedX().getRawBits(), x3 = c.getFixedX().getRawBits();
    int y1 = this->getFixedY().getRawBits(), y2 = b.getFixedY().getRawBits(), y3 = c.getFixedY().getRawBits();
    return abs((x1*y2) + (x2*y3) + (x3*y1) - (x2*y1) - (x3*y2) - (x1*y3));
}

bool PointInTriangle(const Point &a, const Point &b, const Point &c, const Point &p) { 
    if (a.getdistance(p) + p.getdistance(b) == a.getdistance(b))
        return false;
    else if (b.getdistance(p) + p.getdistance(c) == b.getdistance(c))
        return false;
    else if (c.getdistance(p) + p.getdistance(a) == c.getdistance(a))
        return false;
    else if (p == a || p == b || p == c)
        return false;
    int area = a.getarea(b, p) + b.getarea(c, p) + c.getarea(a, p);
    return Fixed(a.getarea(b, c)) == Fixed(area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    return PointInTriangle(a, b, c, point);
}
