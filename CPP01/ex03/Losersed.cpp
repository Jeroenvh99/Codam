#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (openfiles(argv[1], argv[2], argv[3]) == 0) {
		std::cout << "something went wrong opening the files" << std::endl;
		return 1;
	}
	return 0;
}

int openfiles(std::string infile, std::string s1, std::string s2) {
	std::ifstream infile();
	infile.open(infile);
	if (!infile.is_open())
		return 0;
	std::string outfile = infile.append(".replace");
	std::ofstream outfile();
	outfile.open(outfile);
	if (!outfile.is_open()) {
		infile.close();
		return 0;
	}
	writeoutput(infile, outfile, s1, s2);
	infile.close();
	outfile.close();
	return 1;
}

void writeoutput(std::ifstream infile, std::ofstream outfile, std::string s1, std::string s2) {
	std::string str;
	while (infile >> str)
	{
		if (str.compare(s1))
		{
			outfile << s2;
		}
		else
		{
			outfile << str;
		}
		outfile << " ";
	}
}