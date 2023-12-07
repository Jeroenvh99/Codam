#ifndef EASYFIND_T
# define EASYFIND_T
# include <algorithm>
# include <exception>

namespace easyfin {
	class notfoundexception : std::exception {
		public:
			virtual const char *what() const throw() {
				return "The element couldn't be found in the array";
			}
	};
}

template<typename T> int &easyfind(T container, int tofind) {
	T<int>::iterator it = find(container.begin(), container.end(), tofind);
	if (it == container.end())
		throw easyfin::notfoundexception();
	return *it;
}
#endif