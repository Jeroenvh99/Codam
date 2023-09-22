#include <iostream>
#include <cmath>
#include <climits>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &fixed) {
	_value = fixed.getRawBits();
}

Fixed::Fixed(const int n) : _value(n << _fraction_bits) {}

Fixed::Fixed(const float f) : _value(std::roundf(f * ( 1 << _fraction_bits))) {}

Fixed& Fixed::operator=(const Fixed &fixed) {
	this->_value = fixed.getRawBits();
	return *this;
}

bool Fixed::operator==(const Fixed &fixed) const {
	return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return this->getRawBits() != fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
	return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>(const Fixed &fixed) const {
	return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return this->getRawBits() >= fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator%(const Fixed &fixed) const {
	int wholes = this->toFloat() / fixed.toFloat();
	return Fixed(this->toFloat() - (fixed.toFloat() * wholes));
}

Fixed &Fixed::operator++() {
	++this->_value;
	return *this;
}

Fixed &Fixed::operator--() {
	--this->_value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	tmp._value = this->_value++;
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	tmp._value = this->_value--;
	return tmp;
}

Fixed &Fixed::min(Fixed &p1, Fixed &p2) {
	if (p1.getRawBits() > p2.getRawBits())
		return p2;
	return p1;
}

const Fixed &Fixed::min(const Fixed &p1, const Fixed &p2) {
	if (p1 > p2)
		return p2;
	return p1;
}

Fixed &Fixed::max(Fixed &p1, Fixed &p2) {
	if (p1.getRawBits() > p2.getRawBits())
		return p1;
	return p2;
}

const Fixed &Fixed::max(const Fixed &p1, const Fixed &p2) {
	if (p1 > p2)
		return p1;
	return p2;
}

int Fixed::getRawBits() const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(this->_value) / (1 << _fraction_bits);
}

int Fixed::toInt() const {
	return this->_value >> _fraction_bits;
}

Fixed::~Fixed() {}

std::ostream& operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return out;
}