#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main() {
	std::vector<int> nums{3,6,75,34,8,23,876};
	int res;
	try {
		res = easyfind(nums, 35);
	} catch (easyfin::notfoundexception &e) {
		std::cerr << e.what() << std::endl;
	}
	// res = easyfind(nums, 8);
	// std::cout << "found the element " << res << " in the container" << std::endl;
	return 0;
}