#include "../include/Object.hpp"
#include "../include/utils.hpp"

computorv2::Object::Object(void)
{
	this->clear();
}

computorv2::Object::~Object(void)
{
	this->clear();
}

computorv2::Object::Object(const Object& other)
{
	*this = other;
}

computorv2::Object& computorv2::Object::operator=(const computorv2::Object& other)
{
	if (this != &other)
	{
		this->_name = other._name;
	}
	return (*this);
}

int  computorv2::Object::getType(void) const
{
	return (COMPUTORV2_TYPE_UNKNOWN);
}

std::string computorv2::Object::getName(void) const
{
	return (this->_name);
}

void computorv2::Object::setName(std::string name)
{
	this->_name = name;
}

std::string computorv2::Object::toString(void) const
{
	return ("[object Object]");
}

void computorv2::Object::clear(void)
{
	this->_name = "";
}

std::ostream& operator<<(std::ostream& os, const computorv2::Object& obj)
{
	os << obj.toString();
	return (os);
}
