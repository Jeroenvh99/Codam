#ifndef ARRAY_C
# define ARRAY_C
# include <stdexcept>

template <typename T> class Array {
	private:
		T *_array;
		unsigned int _size;
	public:
		Array(unsigned int n = 0);
		Array(const Array &array);
		Array &operator=(const Array &array);
		T &operator[](unsigned int index) const;
		unsigned int size() const;
		~Array();
};
#endif