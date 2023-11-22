#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include <ctype.h>
#include "ScalarConverter.hpp"

namespace utils {
	types recognise(std::string in) {
		types type = CHAR;
		if (in.compare("-inff") == 0 || in.compare("+inff") == 0)
			return FLOAT;
		if (in.compare("nan") == 0 || in.compare("-inf") == 0 || in.compare("+inf") == 0)
			return DOUBLE;
		size_t i = 0;
		if (in[i] && !(in[i] >= '0' && in[i] <= '9'))
			++i;
		while (in[i] && in[i] >= '0' && in[i] <= '9') {
			if (type != INT)
				type = INT;
			++i;
		}
		if (in[i] == '.' && in[i + 1])
			++i;
		while (in[i] && in[i] >= '0' && in[i] <= '9') {
			if (type != DOUBLE)
				type = DOUBLE;
			++i;
		}
		if (in[i] == 'f') {
			type = FLOAT;
			++i;
		}
		if (i != in.length())
			type = NONE;
		return type;
	}

	void convertChar(std::string in) {
		std::cout << "char: ";
		if (isprint(in[0])) {
			std::cout << in[0];
		} else {
			std::cout << "Non displayable";
		}
		std::cout << "\nint: " << static_cast<int>(in[0]);
		std::cout << std::fixed << std::setprecision(1) << "\nfloat: " << static_cast<float>(in[0]) << "f";
		std::cout << std::fixed << std::setprecision(1) << "\ndouble: " << static_cast<double>(in[0]);
		std::cout << std::endl;
	}

	void convertInt(std::string in) {
		int res = 0;
		try {
			res = std::stoi(in);
			std::cout << "char: ";
			if (isprint(static_cast<char>(res))) {
				std::cout << static_cast<char>(res);
			} else {
				std::cout << "Non displayable";
			}
			std::cout << "\nint: " << res;
			std::cout << std::fixed << std::setprecision(1) << "\nfloat: " << static_cast<float>(res) << "f";
			std::cout << std::fixed << std::setprecision(1) << "\ndouble: " << static_cast<double>(res);
			std::cout << std::endl;
		} catch (std::out_of_range &e) {
			std::cerr << "out_of_range exception, this doesn't fit into an int" << std::endl;
		}
	}

	void convertFloat(std::string in) {
		float res = 0;
		try {
			res = std::stof(in);
			std::cout << "char: ";
			if (isprint(static_cast<char>(res))) {
				std::cout << static_cast<char>(res);
			} else {
				std::cout << "Non displayable";
			}
			std::cout << "\nint: " << static_cast<int>(res);
			std::cout << std::fixed << std::setprecision(3) << "\nfloat: " << res << "f";
			std::cout << std::fixed << std::setprecision(3) << "\ndouble: " << static_cast<double>(res);
			std::cout << std::endl;
		} catch (std::out_of_range &e) {
			std::cerr << "out_of_range exception, this doesn't fit into a float" << std::endl;
		}
	}

	void convertDouble(std::string in) {
		double res = 0;
		try {
			res = std::stod(in);
			std::cout << "char: ";
			if (isprint(static_cast<char>(res))) {
				std::cout << static_cast<char>(res);
			} else {
				std::cout << "Non displayable";
			}
			std::cout << "\nint: " << static_cast<int>(res);
			std::cout << std::fixed << std::setprecision(3) << "\nfloat: " << static_cast<float>(res) << "f";
			std::cout << std::fixed << std::setprecision(3) << "\ndouble: " << res;
			std::cout << std::endl;
		} catch (std::out_of_range &e) {
			std::cerr << "out_of_range exception, this doesn't fit into a double" << std::endl;
		}
	}
}

void ScalarConverter::convert(std::string in) {
	types type = utils::recognise(in);
	switch (type) {
		case CHAR:
			utils::convertChar(in);
			break;
		case INT:
			utils::convertInt(in);
			break;
		case FLOAT:
			utils::convertFloat(in);
			break;
		case DOUBLE:
			utils::convertDouble(in);
			break;
		default:
			std::cout << "type not recognised" << std::endl;
	}
}
