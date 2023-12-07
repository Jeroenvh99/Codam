#ifndef ITER_T
# define ITER_T

template<class T> void iter(T *array, int length, void (*func)(T)) {
	for (int i = 0; i < length; i++) {
		func(*(array + i));
	}
}
#endif