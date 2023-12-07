#include <fstream>
#include <iostream>
#include <string>

void writeoutput(std::ifstream &infile, std::ofstream &outfile, std::string s1, std::string s2) {
	std::string str;
	while (std::getline(infile, str, '\n')) {
		size_t i = str.find(s1);
		while (i < str.size()) {
			str.erase(i, s1.length());
			str.insert(i, s2);
			i = str.find(s1, i + s2.length() - 1);
		}
		outfile << str << '\n';
	}
	outfile << std::flush;
}

int openfiles(std::string infile, std::string s1, std::string s2) {
	std::ifstream in(infile.c_str());
	if (!in.is_open())
		return 0;
	if (in.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "Empty infile, nothing to replace" << std::endl;
		return 1;
	}
	std::string outfile = infile.append(".replace");
	std::ofstream out(outfile.c_str());
	if (!out.is_open()) {
		in.close();
		return 0;
	}
	writeoutput(in, out, s1, s2);
	in.close();
	out.close();
	return 1;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Too little parameters\nUsage ./Losersed filename s1 s2" << std::endl;
        return 1;
    }
    if (openfiles(argv[1], argv[2], argv[3]) == 0) {
		std::cout << "something went wrong opening the files" << std::endl;
		return 1;
	}
	return 0;
}