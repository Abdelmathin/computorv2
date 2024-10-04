#include "../include/IndependentVariable.hpp"
#include "../include/utils.hpp"
#include <iostream>

computorv2::IndependentVariable::IndependentVariable(void)
{
    this->_name = "";
}

computorv2::IndependentVariable::IndependentVariable(const std::string& name)
{
    this->setName(name);
}

computorv2::IndependentVariable::~IndependentVariable(void)
{
    this->_name = "";
}

computorv2::IndependentVariable::IndependentVariable(const computorv2::IndependentVariable& other)
{
    this->setName(other.getName());
}

computorv2::IndependentVariable& computorv2::IndependentVariable::operator=(const computorv2::IndependentVariable& other)
{
    if (this != &other)
    {
       this->setName(other.getName());
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

void computorv2::IndependentVariable::setName(const std::string& name)
{
    // if (!computorv2::isname(name))
    // {
    //     throw std::logic_error("bad Variable Name!");
    // }
    this->_name = name;
}

std::string computorv2::IndependentVariable::toString(void) const
{
    return (this->getName());
}

computorv2::Object* computorv2::IndependentVariable::copy(void) const
{
    return ( new computorv2::IndependentVariable(*this) );
}

bool computorv2::IndependentVariable::isnull(void) const
{
    return (false);
}

bool computorv2::IndependentVariable::isunity(void) const
{
    return (false);
}
