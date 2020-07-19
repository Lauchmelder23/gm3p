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

	gInt::~gInt()
	{
		mpz_clear(value);
	}

	gInt& gInt::operator=(const gInt& other)
	{
		mpz_set(*this, const_cast<gInt&>(other));
		return *this;
	}

	gInt::gInt(const gInt& other)
	{
		mpz_set(*this, const_cast<gInt&>(other));
	}

	gInt::gInt(gInt&& other)
	{
		mpz_set(*this, const_cast<gInt&>(other));
	}

	gInt operator-(const gInt& value)
	{
		return Neg(value);
	}

	gInt operator+(const gInt& left, const gInt& right)
	{
		gInt ret;
		mpz_add(ret, const_cast<gInt&>(left), const_cast<gInt&>(right));
		return ret;
	}

	gInt operator-(const gInt& left, const gInt& right)
	{
		gInt ret;
		mpz_sub(ret, const_cast<gInt&>(left), const_cast<gInt&>(right));
		return ret;
	}

	gInt operator*(const gInt& left, const gInt& right)
	{
		gInt ret;
		mpz_mul(ret, const_cast<gInt&>(left), const_cast<gInt&>(right));
		return ret;
	}

	gInt operator/(const gInt& left, const gInt& right)
	{
		gInt ret;
		mpz_div(ret, const_cast<gInt&>(left), const_cast<gInt&>(right));
		return ret;
	}

	gInt& gInt::operator+=(const gInt& right)
	{
		mpz_add(value, value, const_cast<gInt&>(right));
		return *this;
	}

	gInt& gInt::operator-=(const gInt& right)
	{
		mpz_sub(value, value, const_cast<gInt&>(right));
		return *this;
	}

	gInt& gInt::operator*=(const gInt& right)
	{
		mpz_mul(value, value, right.value);
		return *this;
	}

	gInt& gInt::operator/=(const gInt& right)
	{
		mpz_div(value, value, const_cast<gInt&>(right));
		return *this;
	}

	gInt Mul2Exp(const gInt& value, const mp_bitcnt_t& exp)
	{
		gInt ret;
		mpz_mul_2exp(ret, const_cast<gInt&>(value), exp);
		return ret;
	}

	gInt Neg(const gInt& value)
	{
		gInt ret;
		mpz_neg(ret, const_cast<gInt&>(value));
		return ret;
	}

	gInt Abs(const gInt& value)
	{
		gInt ret;
		mpz_abs(ret, const_cast<gInt&>(value));
		return ret;
	}

	gInt::operator long int() const
	{
		return mpz_get_si(value);
	}

	gInt::operator mpz_t&()
	{
		return value;
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