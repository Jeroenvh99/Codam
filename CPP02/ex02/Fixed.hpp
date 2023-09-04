#ifndef FIXED_C
# define FIXED_C
# include <iostream>

class Fixed{
	private:
		int _value;
		static const int _fraction_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int n);
		Fixed(const float f);
		Fixed& operator=(const Fixed &fixed);
		bool Fixed::operator==(const Fixed &fixed) const;
		bool Fixed::operator!=(const Fixed &fixed) const;
		bool Fixed::operator<(const Fixed &fixed) const;
		bool Fixed::operator>(const Fixed &fixed) const;
		bool Fixed::operator<=(const Fixed &fixed) const;
		bool Fixed::operator>=(const Fixed &fixed) const;
		Fixed Fixed::operator+(const Fixed &fixed) const;
		Fixed Fixed::operator-(const Fixed &fixed) const;
		Fixed Fixed::operator*(const Fixed &fixed) const;
		Fixed Fixed::operator/(const Fixed &fixed) const;
		Fixed Fixed::operator%(const Fixed &fixed) const;
		Fixed &Fixed::operator++();
		Fixed &Fixed::operator--();
		Fixed Fixed::operator++(int);
		Fixed Fixed::operator--(int);
		Fixed &min(Fixed &p1, Fixed &p2);
		Fixed &min(const Fixed &p1, const Fixed &p2);
		Fixed &max(Fixed &p1, Fixed &p2);
		Fixed &max(const Fixed &p1, const Fixed &p2);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		~Fixed();
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
#endif