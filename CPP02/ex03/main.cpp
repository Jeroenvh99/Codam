#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);
Fixed area(Point a, Point b, Point c);

int main() {
	{
		Point a(2, 1);
		Point b(7, -1);
		Point c(4, 8);
		Point x(10, 5); // not inside the triangle
		if (bsp(a, b, c, x))
			std::cout << "The point x is inside the triangle" << std::endl;
		else
			std::cout << "The point x is not inside the triangle" << std::endl;
	}
	{
		Point a(2, 1);
		Point b(7, -1);
		Point c(4, 8);
		Point x(5, 5); // inside the triangle
		if (bsp(a, b, c, x))
			std::cout << "The point x is inside the triangle" << std::endl;
		else
			std::cout << "The point x is not inside the triangle" << std::endl;
	}
	{
		Point a(-2, 1);
		Point b(7, -6);
		Point c(-1.5f, 8.3f);
		Point x(5, 2); // not inside the triangle
		if (bsp(a, b, c, x))
			std::cout << "The point x is inside the triangle" << std::endl;
		else
			std::cout << "The point x is not inside the triangle" << std::endl;
	}
	{
		Point a(2, 1);
		Point b(6, 1);
		Point c(6, 5);
		std::cout << "The area of the triangle is " << area(a, b, c) << std::endl; // area is 8
	}
	return 0;
}