#ifndef HARL_C
# define HARL_C
# include <string>

class Harl {
	private:
		void debug();
		void info();
		void warning();
		void error();
	public:
		Harl();
		void complain(std::string comm);
		~Harl();
};

typedef void (Harl::*t_func)();
#endif