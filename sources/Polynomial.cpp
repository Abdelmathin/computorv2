#include "../include/Polynomial.hpp"
#include "../include/Rational.hpp"
#include "../include/utils.hpp"
#include "../include/computorv2.hpp"
#include <iostream>
#include <sstream>
#include <exception>

void computorv2::Polynomial::init(void)
{
	this->_name        = "";
	this->_coefficient = new computorv2::Rational(1.0);
	this->_exponent    = new computorv2::Rational(1.0);
	this->_freeterm    = new computorv2::Rational(0.0);
}

void computorv2::Polynomial::delCoefficient(void)
{
	if (this->_coefficient)
	{
		delete (this->_coefficient);
	}
	this->_coefficient = NULL;
}

void computorv2::Polynomial::delExponent(void)
{
	if (this->_exponent)
	{
		delete (this->_exponent);
	}
	this->_exponent = NULL;
}

void computorv2::Polynomial::delFreeTerm(void)
{
	if (this->_freeterm)
	{
		delete (this->_freeterm);
	}
	this->_freeterm = NULL;
}

computorv2::Polynomial::Polynomial(void)
{
	this->init();
}

computorv2::Polynomial::~Polynomial(void)
{
	this->delCoefficient();
	this->delExponent();
	this->delFreeTerm();
}

computorv2::Polynomial::Polynomial(const computorv2::Polynomial& other)
{
	this->init();
	*this = other;
}

computorv2::Polynomial& computorv2::Polynomial::operator=(const computorv2::Polynomial& other)
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setCoefficient(other.getCoefficient());
		this->setExponent(other.getExponent());
		this->setFreeTerm(other.getFreeTerm());
	}
	return (*this);
}

int computorv2::Polynomial::getType(void) const
{
	return (COMPUTORV2_TYPE_POLYNOMIAL);
}

std::string computorv2::Polynomial::getName(void) const
{
	return (this->_name);
}

computorv2::Object* computorv2::Polynomial::getCoefficient(void) const
{
	return (this->_coefficient);
}

computorv2::Object* computorv2::Polynomial::getExponent(void) const
{
	return (this->_exponent);
}

computorv2::Object* computorv2::Polynomial::getFreeTerm(void) const
{
	return (this->_freeterm);
}

void computorv2::Polynomial::setName(const std::string& name)
{
	this->_name = name;
}

void computorv2::Polynomial::setCoefficient(const computorv2::Object* coefficient)
{
	this->delCoefficient();
	if (!coefficient)
	{
		throw std::logic_error("Can't set coefficient to NULL");
	}
	this->_coefficient = coefficient->copy();
}

void computorv2::Polynomial::setExponent(const computorv2::Object* exponent)
{
	this->delExponent();
	if (!exponent)
	{
		throw std::logic_error("Can't set exponent to NULL");
	}
	this->_exponent = exponent->copy();
}

void computorv2::Polynomial::setFreeTerm(const computorv2::Object* freeterm)
{
	this->delFreeTerm();
	if (!freeterm)
	{
		throw std::logic_error("Can't set freeterm to NULL");
	}
	this->_freeterm = freeterm->copy();
}

std::string computorv2::Polynomial::toString(void) const
{
	const computorv2::Rational zero(0.0);
	const computorv2::Rational one(1.0);
	std::stringstream ss("");

	if (((computorv2::eql(this->_coefficient, &zero))) && ((!this->_freeterm) || (computorv2::eql(this->_freeterm, &zero))))
	{
		ss << "0";
		return (ss.str());
	}
	if (this->_coefficient)
	{
		if (!computorv2::eql(this->_coefficient, &zero))
		{
			ss << "(" << this->_coefficient->toString() << ") * ";
			ss << this->_name;
			if (this->_exponent)
			{
				ss << "^(" << this->_exponent->toString() << ")";
			}			
		}
	}
	if (this->_freeterm)
	{
		ss << " + (" << this->_freeterm->toString() << ")";
	}
    return (ss.str());
}

computorv2::Object* computorv2::Polynomial::copy(void) const
{
    return ( new computorv2::Polynomial(*this) );
}

bool computorv2::Polynomial::isnull(void) const
{
	return (this->_coefficient->isnull() && this->_freeterm->isnull());
}

bool computorv2::Polynomial::isunity(void) const
{
	return (this->_coefficient->isnull() && this->_freeterm->isunity());
}
