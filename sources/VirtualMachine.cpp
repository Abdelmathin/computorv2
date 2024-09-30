#include "../include/VirtualMachine.hpp"
#include "../include/Object.hpp"
#include <iostream>
#include <map>

computorv2::VirtualMachine::VirtualMachine(void)
{
	this->clear();
}

computorv2::VirtualMachine::~VirtualMachine(void)
{
	this->clear();
}

computorv2::VirtualMachine::VirtualMachine(const VirtualMachine& other)
{
	*this = other;
}

computorv2::VirtualMachine& computorv2::VirtualMachine::operator=(const computorv2::VirtualMachine& other)
{
	if (this != &other)
	{
		this->_independent = other._independent;
		this->_variables   = other._variables;
		this->_constants   = other._constants;
	}
	return (*this);
}

computorv2::Object* computorv2::VirtualMachine::getIndependentVariable(void) const
{
	return (this->_independent);
}

computorv2::Object* computorv2::VirtualMachine::getVariableByName(const std::string name) const
{
	std::map< std::string, computorv2::Object* >::const_iterator it = this->_variables.find(name);
	if (it == this->_variables.end())
	{
		return (NULL);
	}
	return (it->second);
}

computorv2::Object* computorv2::VirtualMachine::getConstantByName(const std::string name) const
{
	std::map< std::string, computorv2::Object* >::const_iterator it = this->_constants.find(name);
	if (it == this->_constants.end())
	{
		return (NULL);
	}
	return (it->second);
}

void computorv2::VirtualMachine::setIndependentVariable(computorv2::Object* independent)
{
	this->_independent = independent;
}

void computorv2::VirtualMachine::setVariableByName(const std::string name, computorv2::Object* var)
{
	this->_variables[name] = var;
}

void computorv2::VirtualMachine::setConstantByName(const std::string name, computorv2::Object* var)
{
	this->_constants[name] = var;
}

void computorv2::VirtualMachine::clear(void)
{
	this->_independent = NULL;
	this->_variables.clear();
	this->_constants.clear();
}
