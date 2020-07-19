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
		gInt(mpq_t init);
		gInt(mpf_t init);
		gInt(unsigned long int init);
		gInt(long int init);
		gInt(const char* init, int base);
		gInt(double init);

		// DESTRUCTOR
		~gInt();

		// ASSIGNMENT/COPY OPERATORS
		gInt& operator=(const gInt& other);
		gInt(const gInt& other);
		gInt(gInt&& other);

		// ARITHMETIC OPERATORS
		friend gInt operator+(const gInt& left, const gInt& right);
		friend gInt operator-(const gInt& left, const gInt& right);
		friend gInt operator*(const gInt& left, const gInt& right);
		friend gInt operator/(const gInt& left, const gInt& right);

		gInt& operator+=(const gInt& right);
		gInt& operator-=(const gInt& right);
		gInt& operator*=(const gInt& right);
		gInt& operator/=(const gInt& right);

		// CONVERSION OPERATORS
	 	operator long int() const;
		
		unsigned long int ToUnsigned() const;
		char* ToString(char* buf, int base) const;
		double ToDouble() const;
		double ToDouble(long int* exp) const;

		// STDIO OPERATORS
		friend std::ostream& operator<<(std::ostream& os, const gInt& value);

	private:
		mpz_t value;
	};
}