#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a(1);
	{
		Fixed const b( Fixed( 5.05f ) + Fixed( 2 ) );
		std::cout << b << std::endl;
	}
	{
		Fixed const b( Fixed( 5.05f ) - Fixed( 2 ) );
		std::cout << b << std::endl;
	}
	{
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << b << std::endl;
	}
	{
		Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
		std::cout << b << std::endl;
	}
	Fixed b( Fixed( 5.05f ) % Fixed( 2 ) );
	std::cout << b << std::endl;
	std::cout << a << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}