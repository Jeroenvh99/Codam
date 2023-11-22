#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	int i = rand() % 3;
	if (i == 0) {
		std::cout << "generated class of type A" << std::endl;
		return new A();
	} else if (i == 1) {
		std::cout << "generated class of type B" << std::endl;
		return new B();
	}
	std::cout << "generated class of type C" << std::endl;
	return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "detected type A for this pointer" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "detected type B for this pointer" << std::endl;
	} else {
		std::cout << "detected type C for this pointer" << std::endl;
	}
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "detected type A for this reference" << std::endl;
	} catch (std::exception &e) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "detected type B for this reference" << std::endl;
		} catch (std::exception &e) {
			std::cout << "detected type C for this reference" << std::endl;
		}
	}
}

int main() {
	srand((unsigned)time(0));
	for (int i = 0; i < 20; i++) {
		Base *random = generate();
		identify(random);
		identify(*random);
		delete random;
	}
	return 0;
}