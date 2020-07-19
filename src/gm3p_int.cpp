#include "gm3p.hpp"

namespace gm3p
{
	gInt::gInt()
	{
		mpz_init(value);
	}

	gInt::gInt(mpz_t init) 
	{
		mpz_init_set(value, init);
	}

	gInt::gInt(mpq_t init)
	{
		mpz_init(value);
		mpz_set_q(value, init);
	}

	gInt::gInt(mpf_t init)
	{
		mpz_init(value);
		mpz_set_f(value, init);
	}

	gInt::gInt(unsigned long int init) :
		gInt::gInt()
	{
		mpz_init_set_ui(value, init);
	}

	gInt::gInt(long int init) :
		gInt::gInt()
	{
		mpz_init_set_si(value, init);
	}

	gInt::gInt(const char* init, int base) :
		gInt::gInt()
	{
		mpz_init_set_str(value, init, base);
	}

	gInt::gInt(double init)
	{
		mpz_init_set_d(value, init);
	}


	gInt::~gInt()
	{
		mpz_clear(value);
	}




	gInt& gInt::operator=(const gInt& other)
	{
		mpz_set(this->value, other.value);
		return *this;
	}

	gInt::gInt(const gInt& other)
	{
		mpz_set(this->value, other.value);
	}

	gInt::gInt(gInt&& other)
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



	gInt& gInt::operator+=(const gInt& right)
	{
		mpz_add(value, value, right.value);
		return *this;
	}

	gInt& gInt::operator-=(const gInt& right)
	{
		mpz_sub(value, value, right.value);
		return *this;
	}

	gInt& gInt::operator*=(const gInt& right)
	{
		mpz_mul(value, value, right.value);
		return *this;
	}

	gInt& gInt::operator/=(const gInt& right)
	{
		mpz_div(value, value, right.value);
		return *this;
	}

	gInt::operator long int() const
	{
		return mpz_get_si(value);
	}

	unsigned long int gInt::ToUnsigned() const
	{
		return mpz_get_ui(value);
	}

	char* gInt::ToString(char* buf, int base) const
	{
		return mpz_get_str(buf, base, value);
	}

	double gInt::ToDouble() const
	{
		return mpz_get_d(value);
	}

	double gInt::ToDouble(long int* exp) const
	{
		return mpz_get_d_2exp(exp, value);
	}


	std::ostream& operator<<(std::ostream& os, const gInt& value)
	{
		os << value.ToString(NULL, 
			(os.flags() & std::ios_base::dec) != 0 ? 10 :
				(os.flags() & std::ios_base::hex) != 0 ? 16 : 
					8
		);
		return os;
	}
}