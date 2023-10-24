#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) { }

Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()) { }

Point::Point(const float x, const float y) : _x(x), _y(y) { }

Point& Point::operator=(const Point &point) {
	// if (this != &point) {
	// 	// (Fixed)this->_x = point.getX();
	// 	// (Fixed)this->_y = point.getY();
	// 	return Point(point);
	// } // point already exists, don't overwrite const values
	return *this;
}

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}

Point::~Point() { }
