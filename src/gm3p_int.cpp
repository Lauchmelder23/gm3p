#include "gm3p.hpp"

namespace gm3p
{
	gInt::gInt()
	{
		mpz_init(value);
	}

	gInt::gInt(mpz_t init) 
		: gInt::gInt()
	{
		mpz_set(value, init);
	}

	gInt::gInt(long int init) :
		gInt::gInt()
	{
		mpz_set_si(value, init);
	}

	gInt::gInt(const char* init, int base) :
		gInt::gInt()
	{
		mpz_set_str(value, init, base);
	}

	gInt::~gInt()
	{
		mpz_clear(value);
	}

	gInt& gInt::operator=(const gInt& other)
	{
		mpz_set(this->value, other.value);
	}

	gInt operator+(const gInt& left, const gInt& right)
	{
		gInt ret;
		mpz_add(ret.value, left.value, right.value);
		return ret;
	}

	gInt operator-(const gInt& left, const gInt& right)
	{
		gInt ret;
		mpz_sub(ret.value, left.value, right.value);
		return ret;
	}

	gInt operator*(const gInt& left, const gInt& right)
	{
		gInt ret;
		mpz_mul(ret.value, left.value, right.value);
		return ret;
	}

	gInt operator/(const gInt& left, const gInt& right)
	{
		gInt ret;
		mpz_div(ret.value, left.value, right.value);
		return ret;
	}
	std::ostream& operator<<(std::ostream& os, const gInt& value)
	{
		static char* buf;
		gmp_asprintf(&buf, "%Zd", value);
		os << buf;
	}
}