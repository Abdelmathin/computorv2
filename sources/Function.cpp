#include "../include/Function.hpp"
#include "../include/utils.hpp"
#include <iostream>

computorv2::Function::Function(void)
{
    this->clear();
}

computorv2::Function::~Function(void)
{
    this->clear();
}

computorv2::Function::Function(const computorv2::Function& other)
{
    *this = other;
}

computorv2::Function& computorv2::Function::operator=(const computorv2::Function& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_body = other._body;
        this->_ivar = other._ivar;
    }
    return (*this);
}

int computorv2::Function::getType(void) const
{
    return (COMPUTORV2_TYPE_FUNCTION);
}

std::string computorv2::Function::getName(void) const
{
    return (this->_name);
}

std::string computorv2::Function::getBody(void) const
{
    return (this->_body);
}

std::string computorv2::Function::getIndependentVariable(void) const
{
    return (this->_ivar);
}

void computorv2::Function::setName(const std::string name)
{
    this->_name = name;
}

void computorv2::Function::setBody(const std::string body)
{
    this->_body = body;
}

void computorv2::Function::setIndependentVariable(const std::string ivar)
{
    this->_ivar = ivar;
}

std::string computorv2::Function::toString(void) const
{
    return ("[object Function]");
}

void computorv2::Function::clear(void)
{
    this->_name = "";
    this->_body = "";
    this->_ivar = "";
}
