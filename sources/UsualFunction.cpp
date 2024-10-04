#include "../include/UsualFunction.hpp"
#include "../include/utils.hpp"
#include <sstream>

computorv2::UsualFunction::UsualFunction(void)
{
    this->init();
}

void computorv2::UsualFunction::setName(const std::string& name)
{
    if (!computorv2::isUsualFunction(name))
    {
        throw std::logic_error("bad function name!");
    }
    this->_name = name;
}

void computorv2::UsualFunction::setBody(const computorv2::Object* body)
{
    if (!body)
    {
        throw std::logic_error("bad function body!");
    }
    this->_body = body->copy();
}

void computorv2::UsualFunction::init(void)
{
    this->_name = "";
    this->_body = NULL;
}

void computorv2::UsualFunction::clear(void)
{
    if (this->_body)
    {
        delete (this->_body);
    }
    this->init();
}

computorv2::UsualFunction::UsualFunction(const std::string& name, const computorv2::Object* body)
{
    this->init();
    this->setName(name);
    this->setBody(body);
}

computorv2::UsualFunction::~UsualFunction(void)
{
    this->clear();
}

computorv2::UsualFunction::UsualFunction(const computorv2::UsualFunction& other)
{
    this->setName(other.getName());
    this->setBody(other.getBody());
}

computorv2::UsualFunction& computorv2::UsualFunction::operator=(const computorv2::UsualFunction& other)
{
    if (this != &other)
    {
        this->setName(other.getName());
        this->setBody(other.getBody());
    }
    return (*this);
}

int computorv2::UsualFunction::getType(void) const
{
    return (COMPUTORV2_TYPE_USUAL_FUNCTION);
}

std::string computorv2::UsualFunction::getName(void) const
{
    return (this->_name);
}

computorv2::Object* computorv2::UsualFunction::getBody(void) const
{
    return (this->_body);
}

std::string computorv2::UsualFunction::toString(void) const
{
    std::stringstream ss("");
    ss << this->getName() << "(" << this->getBody()->toString() << ")";
    return (ss.str());
}

computorv2::Object* computorv2::UsualFunction::copy(void) const
{
    return ( new computorv2::UsualFunction(*this) );
}

computorv2::Object* computorv2::UsualFunction::evaluate(void) const
{
    throw std::logic_error("computorv2::UsualFunction::evaluate (Not implemented)!");
    return (NULL);
}

bool computorv2::UsualFunction::isnull(void) const
{
    bool result = false;
    computorv2::Object* e = this->evaluate();
    if (IS_RATIONAL(e) || IS_COMPLEX(e))
    {
        result = e->isnull();
    }
    delete (e);
    return (result);
}

bool computorv2::UsualFunction::isunity(void) const
{
    bool result = false;
    computorv2::Object* e = this->evaluate();
    if (IS_RATIONAL(e) || IS_COMPLEX(e))
    {
        result = e->isunity();
    }
    delete (e);
    return (result);
}
