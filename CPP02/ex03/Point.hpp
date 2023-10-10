#ifndef POINT_C
# define POINT_C
# include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		~Point();
};
#endif