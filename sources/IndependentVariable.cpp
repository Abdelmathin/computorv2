#include "../include/IndependentVariable.hpp"
#include "../include/Complex.hpp"
#include "../include/Rational.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <sstream>

computorv2::IndependentVariable::IndependentVariable(void)
{
	this->init();
}

computorv2::IndependentVariable::~IndependentVariable(void)
{
	this->clear();
}

computorv2::IndependentVariable::IndependentVariable(const computorv2::IndependentVariable& other)
{
	this->init();
	*this = other;
}

computorv2::IndependentVariable& computorv2::IndependentVariable::operator=(const computorv2::IndependentVariable& other)
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setCoefficient(other.getCoefficient());
		this->setExponent(other.getExponent());
		this->setConstant(other.getConstant());
	}
	return (*this);
}

int computorv2::IndependentVariable::getType(void) const
{
	return (COMPUTORV2_TYPE_INDEPENDENT_VARIABLE);
}

std::string computorv2::IndependentVariable::getName(void) const
{
	return (this->_name);
}

computorv2::Complex* computorv2::IndependentVariable::getCoefficient(void) const
{
	return (this->_coefficient);
}

computorv2::Rational* computorv2::IndependentVariable::getExponent(void) const
{
	return (this->_exponent);
}

computorv2::Object* computorv2::IndependentVariable::getConstant(void) const
{
	return (this->_constant);
}

void computorv2::IndependentVariable::setName(std::string name)
{
	this->_name = name;
}

void computorv2::IndependentVariable::setCoefficient(const computorv2::Complex* coefficient)
{
	if (this->_coefficient)
	{
		delete (this->_coefficient);
		this->_coefficient = NULL;
	}
	if (coefficient)
	{
		this->_coefficient = new computorv2::Complex(*coefficient);
	}
}
void computorv2::IndependentVariable::setExponent(const computorv2::Rational* exponent)
{
	if (this->_exponent)
	{
		delete (this->_exponent);
		this->_exponent = NULL;
	}
	if (exponent)
	{
		this->_exponent = new computorv2::Rational(*exponent);
	}
}
void computorv2::IndependentVariable::setConstant(const computorv2::Object* constant)
{
	if (this->_constant)
	{
		delete (this->_constant);
		this->_constant = NULL;
	}
	if (constant)
	{
		this->_constant = constant->copy();
	}
}

std::string computorv2::IndependentVariable::toString(void) const
{
	std::stringstream ss("");
	if (this->_coefficient)
	{
		ss << "(" << this->_coefficient->toString() << ") * ";
	}
	ss << this->_name;
	if (this->_exponent)
	{
		ss << "^(" << this->_exponent->toString() << ")";
	}
	if (this->_constant)
	{
		ss << " + (" << this->_constant->toString() << ")";
	}
    return (ss.str());
}

void computorv2::IndependentVariable::init(void)
{
	this->_name        = "";
	this->_coefficient = NULL;
	this->_exponent    = NULL;
	this->_constant    = NULL;
}

void computorv2::IndependentVariable::clear(void)
{
	if (this->_coefficient)
	{
		delete (this->_coefficient);
	}
	if (this->_exponent)
	{
		delete (this->_exponent);
	}
	if (this->_constant)
	{
		delete (this->_constant);
	}
}

computorv2::Object* computorv2::IndependentVariable::copy(void) const
{
    return ( new computorv2::IndependentVariable(*this) );
}

computorv2::IndependentVariable operator+(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
	// computorv2::Rational rational_unit     = computorv2::Rational(1.0);
	// computorv2::Complex complex_unit       = computorv2::Complex(1.0, 0.0);

	// computorv2::Rational* left_exponent    = left.getExponent();
	// computorv2::Rational* right_exponent   = right.getExponent();
	// computorv2::Complex* left_coefficient  = left.getCoefficient();
	// computorv2::Complex* right_coefficient = right.getCoefficient();

	// if (!left_coefficient)
	// {
	// 	left_coefficient = &complex_unit;
	// }
	// if (!right_coefficient)
	// {
	// 	right_coefficient = &complex_unit;
	// }
	// if (!left_exponent)
	// {
	// 	left_exponent = &rational_unit;
	// }
	// if (!right_exponent)
	// {
	// 	right_exponent = &rational_unit;
	// }
	// if ((left.getName() == right.getName()) && (*left_exponent == *right_exponent))
	// {
	// 	computorv2::IndependentVariable res;
	// 	res.setName(left.getName());
	// 	computorv2::Complex coeff = computorv2::Complex(*left_coefficient + *right_coefficient);
	// 	res.setCoefficient( &coeff );
	// 	// add constant
	// 	return (res);
	// }
	computorv2::IndependentVariable res( left );
	res.setConstant( static_cast<const computorv2::Object *>(&right) );
	return (res);
}
