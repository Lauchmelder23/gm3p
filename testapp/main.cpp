#include "gm3p.hpp"

//#include <iostream>

using namespace gm3p;

int main(int argc, char** argv)
{
	gInt a("12234234234095780349859034869034635235", 10);
	gInt b("123534622305820985092875207398734234753", 10);

	gInt c = a * b;

	std::cout << a << " * " << b << " = " << c << std::endl;

	return 0;
}