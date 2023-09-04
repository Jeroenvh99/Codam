#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	_value = fixed.getRawBits();
}

Fixed::Fixed(const int n) : _value(n << _fraction_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _value(std::roundf(f * ( 1 << _fraction_bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
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
	this->_value += fixed.getRawBits();
	return this;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	this->_value -= fixed.getRawBits();
	return this;
}

Fixed Fixed::operator*(const Fixed &fixed) const {

}

Fixed Fixed::operator/(const Fixed &fixed) const {

}

Fixed Fixed::operator%(const Fixed &fixed) const {

}

Fixed &Fixed::operator++() {

}

Fixed &Fixed::operator--() {

}

Fixed Fixed::operator++(int) {

}

Fixed Fixed::operator--(int) {

}

Fixed &min(Fixed &p1, Fixed &p2) {

}

Fixed &min(const Fixed &p1, const Fixed &p2) {

}

Fixed &max(Fixed &p1, Fixed &p2) {

}

Fixed &max(const Fixed &p1, const Fixed &p2) {

}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(this->_value) / (1 << _fraction_bits);
}

int Fixed::toInt() const {
	return this->_value >> _fraction_bits;
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return out;
}