#include<string>
#include<iostream>

int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "The address of string is: " << &string << std::endl;
	std::cout << "The address of stringPTR is: " << stringPTR << std::endl;
	std::cout << "The address of stringREF is: " << &stringREF << std::endl;

	std::cout << "The content of string is: " << string << std::endl;
	std::cout << "The content being pointed to by stringPTR is: " << *stringPTR << std::endl;
	std::cout << "The content being referenced by stringREF is: " << stringREF << std::endl;

	std::string string1 = "HI THIS IS BRAIN AGAIN";
	stringPTR = &string1;
	stringREF = string1;

	std::cout << "The address of string is: " << &string1 << std::endl;
	std::cout << "The address of stringPTR is: " << stringPTR << std::endl;
	std::cout << "The address of stringREF is: " << &stringREF << std::endl;

	stringPTR = NULL;
	return 0;
}
