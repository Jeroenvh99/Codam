#include "Fixed.hpp"
#include "Point.hpp"

Fixed abs(Fixed in) {
	if (in < 0)
		in = in * -1;
	return in;
}

Fixed area(Point a, Point b, Point c) {
	return (((a.getX() * (b.getY() - c.getY())) +
        	(b.getX() * (c.getY() - a.getY())) +
        	(c.getX() * (a.getY() - b.getY()))) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed pointarea = abs(area(point, a, b)) + abs(area(point, b, c)) + abs(area(point, a, c));
	return pointarea == abs(area(a, b, c));
}