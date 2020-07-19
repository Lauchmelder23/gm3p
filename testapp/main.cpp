#include "gm3p.hpp"

#include <iostream>
#include <iomanip>

using namespace gm3p;

int main(int argc, char** argv)
{
	gInt a("12");
	gInt b = -5;

	gInt c = a * b;

	std::cout << c << std::endl << std::endl;
	std::cout << -c << std::endl << std::endl;

	int d = Abs(c);
	std::cout << d << std::endl;
	std::cout << c.ToString(NULL, 2) << std::endl << std::endl;

	mpz_t& e = c;
	mpz_mul_ui(e, e, 2);
	std::cout << c << std::endl;

	return 0;
}