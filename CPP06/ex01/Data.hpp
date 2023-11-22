#ifndef DATA_C
# define DATA_C

class Data {
	private:
		int _i;
		char _c;
	public:
		Data(int i = 0, char c = 'j');
		Data(const Data &data);
		Data &operator=(const Data &data);
		int getI() const;
		char getC() const;
		~Data();
};
#endif