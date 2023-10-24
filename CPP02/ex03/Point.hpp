#ifndef POINT_C
# define POINT_C
# include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &point);
		Point& operator=(const Point &point);
		Fixed getX() const;
		Fixed getY() const;
		~Point();
};
#endif