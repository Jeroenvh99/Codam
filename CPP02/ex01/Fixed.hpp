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
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		~Fixed();
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
#endif