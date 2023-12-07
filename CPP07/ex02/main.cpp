#include <iostream>
#include "Array.hpp"
#include "Array.tpp"

int main() {
	Array<char> otherString(4);
	try {
		otherString[5] = 'i';
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	} try {
		otherString[2] = 'j';
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	} try {
		otherString[-3] = 'm';
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "The size of this array is " << otherString.size() << std::endl;

	Array<float> numbers;
	std::cout << "The size of this array is " << numbers.size() << std::endl;
	Array<float> filled(6);
	filled[0] = 9.756f;
	filled[1] = 5.870f;
	filled[2] = 0.0f;
	filled[3] = 89.0f;
	filled[4] = 8.5657f;
	filled[5] = 11.55f;
	numbers = filled;
	return 0;
}