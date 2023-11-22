#ifndef SCALARCONVERTER_C
# define SCALARCONVERTER_C
# include <string>

enum types {
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter {
	public:
		static void convert(std::string in);
	private:
		//move constructor and assignment operator (c++11) generated
};
#endif