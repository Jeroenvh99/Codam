#include <fstream>
#include <iostream>
#include <string>

int openfiles(std::string infile, std::string s1, std::string s2) {
	std::ifstream infile();
	infile.open(infile);
	std::string outfile = infile.append(".replace");
	std::ofstream outfile();
	outfile.open(outfile);
	writeoutput(infile, outfile, s1, s2);
	infile.close();
	outfile.close();
	// check fo errors opening files
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