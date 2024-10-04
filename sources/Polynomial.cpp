#include "../include/Polynomial.hpp"
#include "../include/Rational.hpp"
#include "../include/IndependentVariable.hpp"
#include "../include/utils.hpp"
#include "../include/computorv2.hpp"
#include <iostream>
#include <sstream>
#include <exception>

void computorv2::Polynomial::init(const computorv2::Object* base)
{
	this->_coefficient = NULL;
	this->_base        = NULL;
	this->_exponent    = NULL;
	this->_freeterm    = NULL;

	this->setCoefficient(computorv2::Rational(1.0));
	this->setBase(base);
	this->setExponent(computorv2::Rational(1.0));
	this->setFreeTerm(computorv2::Rational(0.0));
}

void computorv2::Polynomial::delCoefficient(void)
{
	if (this->_coefficient)
	{
		delete (this->_coefficient);
	}
	this->_coefficient = NULL;
}

void computorv2::Polynomial::delBase(void)
{
	if (this->_base)
	{
		delete (this->_base);
	}
	this->_base = NULL;
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
	this->init(NULL);
	throw std::logic_error("Can't create Polynomial without Variable!");
}

computorv2::Polynomial::Polynomial(const std::string& basename)
{
	const computorv2::IndependentVariable base(basename);
	this->init(&base);
}

computorv2::Polynomial::Polynomial(const computorv2::IndependentVariable& base)
{
	this->init(&base);
}

computorv2::Polynomial::Polynomial(const computorv2::IndependentVariable* base)
{
	this->init(base);
}

computorv2::Polynomial::~Polynomial(void)
{
	this->delCoefficient();
	this->delBase();
	this->delExponent();
	this->delFreeTerm();
}

computorv2::Polynomial::Polynomial(const computorv2::Polynomial& other)
{
	this->init(other.getBase());
	*this = other;
}

computorv2::Polynomial& computorv2::Polynomial::operator=(const computorv2::Polynomial& other)
{
	if (this != &other)
	{
		this->setCoefficient(other.getCoefficient());
		this->setBase(other.getBase());
		this->setExponent(other.getExponent());
		this->setFreeTerm(other.getFreeTerm());
	}
	return (*this);
}

int computorv2::Polynomial::getType(void) const
{
	return (COMPUTORV2_TYPE_POLYNOMIAL);
}

computorv2::Object* computorv2::Polynomial::getCoefficient(void) const
{
	return (this->_coefficient);
}

computorv2::Object* computorv2::Polynomial::getBase(void) const
{
	return (this->_base);
}

computorv2::Object* computorv2::Polynomial::getExponent(void) const
{
	return (this->_exponent);
}

computorv2::Object* computorv2::Polynomial::getFreeTerm(void) const
{
	return (this->_freeterm);
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

void computorv2::Polynomial::setBase(const computorv2::Object* base)
{
	this->delBase();
	if (!base)
	{
		throw std::logic_error("Can't set base to NULL");
	}
	this->_base = base->copy();
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

void computorv2::Polynomial::setCoefficient(const computorv2::Object& coefficient)
{
	this->setCoefficient(&coefficient);
}

void computorv2::Polynomial::setBase(const computorv2::Object& base)
{
	this->setBase(&base);
}

void computorv2::Polynomial::setExponent(const computorv2::Object& exponent)
{
	this->setExponent(&exponent);
}

void computorv2::Polynomial::setFreeTerm(const computorv2::Object& freeterm)
{
	this->setFreeTerm(&freeterm);
}

std::string computorv2::Polynomial::toString(void) const
{
	const computorv2::Rational zero(0.0);
	const computorv2::Rational one(1.0);
	std::stringstream ss("");

	// if (((computorv2::eql(this->_coefficient, &zero))) && ((!this->_freeterm) || (computorv2::eql(this->_freeterm, &zero))))
	// {
	// 	ss << "0";
	// 	return (ss.str());
	// }
	// if (this->_coefficient)
	// {
	// 	if (!computorv2::eql(this->_coefficient, &zero))
	// 	{
	// 		ss << "(" << this->_coefficient->toString() << ") * ";
	// 		ss << this->_name;
	// 		if (this->_exponent)
	// 		{
	// 			ss << "^(" << this->_exponent->toString() << ")";
	// 		}			
	// 	}
	// }
	// if (this->_freeterm)
	// {
	// 	ss << " + (" << this->_freeterm->toString() << ")";
	// }
    return (ss.str());
}

computorv2::Object* computorv2::Polynomial::copy(void) const
{
    return ( new computorv2::Polynomial(*this) );
}

bool computorv2::Polynomial::isnull(void) const
{
	if ((this->_coefficient->isnull()) || (this->_base->isnull()))
	{
		return (this->_freeterm->isnull());
	}
	return (false);
}

bool computorv2::Polynomial::isunity(void) const
{
	bool result = false;
	// if (this->_exponent->isnull())
	// {
	// 	const computorv2::Object *tmp = computorv2::add(this->_coefficient, this->_freeterm);
	// 	if (tmp->isunity())
	// 	{
	// 		result = true;
	// 	}
	// 	delete (tmp);
	// }
	// else if (this->_coefficient->isnull() && this->_freeterm->isunity())
	// {
	// 	result = true;
	// }
	return (result);
}
