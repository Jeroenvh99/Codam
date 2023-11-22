#include "Serializer.hpp"
#include <iostream>

int main() {
	Data tmp;
	std::cout << "the c value of data is: " << tmp.getC() << std::endl;
	uintptr_t num = Serializer::serialize(&tmp);
	std::cout << "the address of tmp is: " << num << std::endl;
	std::cout << "the c value of data is: " << Serializer::deserialize(num)->getC() << std::endl;
	return 0;
}