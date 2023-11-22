#include "Data.hpp"

Data::Data(int i, char c) : _i(i), _c(c) {}

Data::Data(const Data &data) {
	_i = data.getI();
	_c = data.getC();
}

Data &Data::operator=(const Data &data) {
	_i = data.getI();
	_c = data.getC();
	return *this;
}

int Data::getI() const {
	return _i;
}

char Data::getC() const {
	return _c;
}

Data::~Data() {}
