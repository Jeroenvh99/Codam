#ifndef FIXED_C
# define FIXED_C

class Fixed {
	private:
		int _value;
		static const int _fraction_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed& operator=(const Fixed &fixed);
		int getRawBits() const;
		void setRawBits(int const raw);
		~Fixed();
};
#endif