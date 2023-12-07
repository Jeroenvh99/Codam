#ifndef ARRAY_T
# define ARRAY_T

template <typename T> Array<T>::Array(unsigned int n) {
	_array = new T[n];
	_size = n;
}

template <typename T> Array<T>::Array(const Array &array) {
	_size = array.size();
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = array[i];
	}
}

template <typename T> Array<T> &Array<T>::operator=(const Array &array) {
	if (this != &array) {
		delete[] _array;
		_size = array.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = array[i];
		}
	}
	return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("that index doesn't exist yet");
	return _array[index];
}

template <typename T> unsigned int Array<T>::size() const {
	return _size;
}

template <typename T> Array<T>::~Array() {
	delete[] _array;
}
#endif