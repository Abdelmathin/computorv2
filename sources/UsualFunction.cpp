/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   UsualFunction.cpp                                  :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+      */
/*   By: ahabachi <abdelmathinhabachi@gmail.com>    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+            */
/*   Created: 2024/08/19 17:40:12 by ahabachi          #+#    #+#              */
/*   Updated: 2024/09/24 06:34:37 by ahabachi         ###   ########.fr        */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*    ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗   ██╗████████╗ ██████╗ ██████╗    */
/*   ██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔══██╗   */
/*   ██║     ██║   ██║██╔████╔██║██████╔╝██║   ██║   ██║   ██║   ██║██████╔╝   */
/*   ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║   ██║   ██║   ██║   ██║██╔══██╗   */
/*   ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ╚██████╔╝   ██║   ╚██████╔╝██║  ██║   */
/*    ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝ ╚═╝  ╚═╝   */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/*                                                                             */
/* **************************************************************************  */
/*                                                                             */
/*  █████████            ██████████         ██████████         ██████████      */
/*  ██     ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██         ██      ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██            ██████████         ██████████                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*         ██                    ██                 ██                 ██      */
/*      ████████         ██████████         ██████████                 ██      */
/*                                                                             */
/* **************************************************************************  */

#ifndef __COMPUTORV2_SOURCES_USUAL_FUNCTION
# define __COMPUTORV2_SOURCES_USUAL_FUNCTION

# include "../include/computorv2.hpp"
# include "../include/Complex.hpp"
# include "../include/UsualFunction.hpp"
# include "../include/IndependentVariable.hpp"
# include <sstream>

int computorv2::UsualFunction::getType(void) const
{
    return (COMPUTORV2_TYPE_USUAL_FUNCTION);
}

std::string computorv2::UsualFunction::getTypeName(void) const
{
    return ("UsualFunction");
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
    const computorv2::Object* body = this->_body->evaluate();
    if (!IS_COMPLEX(body))
    {
        computorv2::Object* res = new computorv2::UsualFunction(this->getName(), body);
        delete (body);
        return (res);
    }
    delete (body);
    throw std::logic_error("computorv2::UsualFunction::evaluate (Not implemented)!");
    return (NULL);
}

bool computorv2::UsualFunction::isnull(void) const
{
    bool result = false;
    computorv2::Object* e = this->evaluate();
    if (IS_COMPLEX(e))
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
    if (IS_COMPLEX(e))
    {
        result = e->isunity();
    }
    delete (e);
    return (result);
}

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
    if (this->_body)
    {
        delete (this->_body);
    }
    this->_body = NULL;
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

computorv2::UsualFunction::UsualFunction(const std::string& name, const computorv2::IndependentVariable& body)
{
    this->init();
    this->setName(name);
    this->setBody(&body);
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
    this->init();
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

std::string computorv2::UsualFunction::getName(void) const
{
    return (this->_name);
}

computorv2::Object* computorv2::UsualFunction::getBody(void) const
{
    return (this->_body);
}

std::ostream& operator<<(std::ostream& left, const computorv2::UsualFunction& right)
{
    left << right.toString();
    return (left);
}

#endif//!__COMPUTORV2_SOURCES_USUAL_FUNCTION
