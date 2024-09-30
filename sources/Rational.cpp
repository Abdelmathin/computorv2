#include "../include/Rational.hpp"
#include "../include/utils.hpp"
#include <sstream>

computorv2::Rational::Rational(void)
{
	this->clear();
}

computorv2::Rational::~Rational(void)
{
	this->clear();
}

computorv2::Rational::Rational(const Rational& other)
{
	*this = other;
}

computorv2::Rational& computorv2::Rational::operator=(const computorv2::Rational& other)
{
	if (this != &other)
	{
		this->_name  = other._name;
		this->_value = other._value;
	}
	return (*this);
}

computorv2::Rational::Rational(double value)
{
	this->clear();
	this->setValue(value);
}

int computorv2::Rational::getType(void) const
{
	return (COMPUTORV2_TYPE_RATIONAL);
}

std::string computorv2::Rational::getName(void) const
{
	return (this->_name);
}

double computorv2::Rational::getValue(void) const
{
	return (this->_value);
}

void computorv2::Rational::setName(std::string name)
{
	this->_name = name;
}

void computorv2::Rational::setValue(double value)
{
	this->_value = value;
}

std::string computorv2::Rational::toString(void) const
{
	std::stringstream ss(""); ss << this->_value;
	return (ss.str());
}

void computorv2::Rational::clear(void)
{
	this->_name  = "";
	this->_value = 0.0;
}
