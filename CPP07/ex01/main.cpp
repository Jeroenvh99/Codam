#include <iostream>
#include <string>
#include "iter.hpp"

void print(int i) {
	std::cout << i << " ";
}

void print(std::string s) {
	std::cout << s << " ";
}

int main() {
	{
		int arr[] = {3, 6, 8, 3, 564, 54};
		iter(arr, 6, &print);
		std::cout << std::endl;
	} {
		std::string arr[] = {"hi", "here we", "go again", "that was fun"};
		iter(arr, 4, &print);
		std::cout << std::endl;
	}
	return 0;
}