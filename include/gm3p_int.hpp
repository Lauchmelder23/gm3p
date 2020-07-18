#pragma once

#include <iostream>

#include "gmp.h"

namespace gm3p
{
	class gInt
	{
	public:
		// CONSTRUCTORS
		gInt();
		gInt(mpz_t init);
		gInt(unsigned long int init);
		gInt(long int init);
		gInt(const char* init, int base);
		~gInt();

		// ASSIGNMENT OPERATORS
		gInt& operator=(const gInt& other);

		// ARITHMETIC OPERATORS
		friend gInt operator+(const gInt& left, const gInt& right);
		friend gInt operator-(const gInt& left, const gInt& right);
		friend gInt operator*(const gInt& left, const gInt& right);
		friend gInt operator/(const gInt& left, const gInt& right);

		gInt& operator+=(const gInt& right);
		gInt& operator-=(const gInt& right);
		gInt& operator*=(const gInt& right);
		gInt& operator/=(const gInt& right);

		friend std::ostream& operator<<(std::ostream& os, const gInt& value);

	private:
		mpz_t value;
	};
}