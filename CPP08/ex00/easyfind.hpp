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

template<typename T, typename V = typename T::value_type>
int &easyfind(T &container, int tofind) {
	// T<int>::iterator it = find(container.begin(), container.end(), tofind);
	if (find(container.begin(), container.end(), tofind) == container.end())
		throw easyfin::notfoundexception();
	return *find(container.begin(), container.end(), tofind);
}
#endif