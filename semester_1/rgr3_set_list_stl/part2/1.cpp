#include <fstream>
#include <sstream>
#include <iostream>

int main()
{
	std::fstream in("names.txt");
	std::stringstream cont;
	cont << in.rdbuf();
	std::string conte = cont.str();
	std::cout << conte;
}
