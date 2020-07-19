#include "gm3p.hpp"

#include <iostream>
#include <iomanip>

using namespace gm3p;

int main(int argc, char** argv)
{
	gInt a("12234234234095780349859034869034635235", 10);
	gInt b("123534622305820985092875207398734234753", 10);

	a *= b;
	gInt c = a * b;

	std::cout << std::dec << a << " * " << b << " = " << c << std::endl;
	std::cout << std::hex << a << " * " << b << " = " << c << std::endl;
	std::cout << std::oct << a << " * " << b << " = " << c << std::endl << std::endl << std::dec;

	int d = c;
	std::cout << d << std::endl;
	std::cout << c.ToString(NULL, 2) << std::endl;

	return 0;
}