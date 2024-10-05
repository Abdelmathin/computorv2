/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Polynomial.cpp                                     :+:      :+:    :+:    */
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

#ifndef __COMPUTORV2_SOURCES_POLYNOMIAL
# define __COMPUTORV2_SOURCES_POLYNOMIAL

#include "../include/Polynomial.hpp"
#include "../include/IndependentVariable.hpp"
#include "../include/utils.hpp"
#include "../include/computorv2.hpp"
#include <iostream>
#include <sstream>
#include <exception>

int computorv2::Polynomial::getType(void) const
{
    return (COMPUTORV2_TYPE_POLYNOMIAL);
}

std::string computorv2::Polynomial::toString(void) const
{
	std::stringstream ss("");
	if ((this->_coefficient->isnull()) || (this->_base->isnull()))
	{
		return (this->_freeterm->toString());
	}
	if (this->_exponent->isnull())
	{
		const computorv2::Object* value = computorv2::add(this->_coefficient, this->_freeterm);
		const std::string s = value->toString();
		delete (value);
		return (s);
	}
	ss << "(" << this->_coefficient->toString() << ") * (" << this->_base->toString() << ") ^ (" << this->_exponent->toString() << ") + (" << this->_freeterm->toString() << ")";
    return (ss.str());
}

computorv2::Object* computorv2::Polynomial::copy(void) const
{
    return ( new computorv2::Polynomial(*this) );
}

computorv2::Object* computorv2::Polynomial::evaluate(void) const
{
	throw std::logic_error("computorv2::Polynomial::evaluate (Not implemented)!");
    return (NULL);
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

void computorv2::Polynomial::init(const computorv2::Object* base)
{
	this->_coefficient = NULL;
	this->_base        = NULL;
	this->_exponent    = NULL;
	this->_freeterm    = NULL;

	this->setCoefficient(computorv2::Complex(1.0));
	this->setBase(base);
	this->setExponent(computorv2::Complex(1.0));
	this->setFreeTerm(computorv2::Complex(0.0));
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

computorv2::Polynomial::Polynomial(const computorv2::Object* base)
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

#endif//!__COMPUTORV2_SOURCES_POLYNOMIAL
