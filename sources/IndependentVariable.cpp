#include "../include/IndependentVariable.hpp"
#include "../include/utils.hpp"
#include <iostream>

computorv2::IndependentVariable::IndependentVariable(void)
{
	this->clear();
}

computorv2::IndependentVariable::~IndependentVariable(void)
{
	this->clear();
}

computorv2::IndependentVariable::IndependentVariable(const computorv2::IndependentVariable& other)
{
	*this = other;
}

computorv2::IndependentVariable& computorv2::IndependentVariable::operator=(const computorv2::IndependentVariable& other)
{
	if (this != &other)
	{
		this->_name = other._name;
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

void computorv2::IndependentVariable::setName(std::string name)
{
	this->_name = name;
}

std::string computorv2::IndependentVariable::toString(void) const
{
    return ("[object IndependentVariable]");
}

void computorv2::IndependentVariable::clear(void)
{
	this->_name = "";
}
