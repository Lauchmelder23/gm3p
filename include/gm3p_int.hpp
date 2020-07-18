#pragma once

#include "gmp.h"

namespace gm3p
{
	class gInt
	{
	public:
		gInt();
		gInt(mpz_t init);
		gInt(long int init);
		gInt(const char* init, int base);
		~gInt();

		gInt& operator=(const gInt& other);

		friend gInt operator+(const gInt& left, const gInt& right);
		friend gInt operator-(const gInt& left, const gInt& right);
		friend gInt operator*(const gInt& left, const gInt& right);
		friend gInt operator/(const gInt& left, const gInt& right);

		friend std::ostream& operator<<(std::ostream& os, const gInt& value);

	private:
		mpz_t value;
	};
}