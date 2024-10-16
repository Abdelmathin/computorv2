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

# include "../include/computorv2.hpp"
# include "../include/Complex.hpp"
# include "../include/Polynomial.hpp"
# include "../include/UsualFunction.hpp"
# include "../include/IndependentVariable.hpp"
# include <iostream>
# include <sstream>
# include <exception>

int computorv2::Polynomial::getType(void) const
{
    return (COMPUTORV2_TYPE_POLYNOMIAL);
}

std::string computorv2::Polynomial::getTypeName(void) const
{
    return ("Polynomial");
}

std::string computorv2::Polynomial::toString(void) const
{
	if ((this->getCoefficient()->isnull()) || (this->getBase()->isnull()))
	{
		return (this->getFreeTerm()->toString());
	}
	std::stringstream ss("");
	{
		std::string a = this->getCoefficient()->toString();
		if (this->getExponent()->isnull() || this->getBase()->isunity())
		{
			ss << a;
		}
		else
		{
			if ((a != "1") && (a != "-1"))
			{
				if (!computorv2::isfreeterm(this->getCoefficient()))
				{
					ss << "(";
				}
				ss << a;
				if (!computorv2::isfreeterm(this->getCoefficient()))
				{
					ss << ")";
				}
				ss << " * ";
			}
			else if (a == "-1")
			{
				ss << "-";
			}
			if (!computorv2::isfreeterm(this->getBase()))
			{
				ss << "(";
			}
			ss << this->getBase()->toString();
			if (!computorv2::isfreeterm(this->getBase()))
			{
				ss << ")";
			}
			const std::string n = this->getExponent()->toString();
			if ((n.size() > 0) && (!this->getExponent()->isunity()))
			{
				ss << "^";
				if ((n[0] == '-') || (!computorv2::isfreeterm(this->getExponent())))
				{
					ss << "(";
				}
				ss << n;
				if ((n[0] == '-') || (!computorv2::isfreeterm(this->getExponent())))
				{
					ss << ")";
				}
			}
		}
	}
	if (!this->getFreeTerm()->isnull())
	{
		std::string b = this->getFreeTerm()->toString();
		if (b.size() > 0)
		{
			if (b[0] == '-')
			{
				ss << " - ";
				b = b.substr(1, b.size() - 1);
			}
			else
			{
				ss << " + ";
			}
			ss << b;			
		}
	}
    return (ss.str());
}

computorv2::Object* computorv2::Polynomial::clone(void) const
{
	computorv2::Object* e = new computorv2::Polynomial(*this);
    return (e);
}

bool computorv2::Polynomial::isnull(void) const
{
	if ((this->getCoefficient()->isnull()) || (this->getBase()->isnull()))
	{
		return (this->getFreeTerm()->isnull());
	}
	return (false);
}

bool computorv2::Polynomial::isunity(void) const
{
	if ((this->getCoefficient()->isnull()) || (this->getBase()->isnull()))
	{
		return (this->getFreeTerm()->isunity());
	}
	if (this->getExponent()->isnull() || this->getBase()->isunity())
	{
		if (this->getCoefficient()->isunity() && this->getFreeTerm()->isnull())
		{
			return (true);
		}
	}
	return (false);
}

bool computorv2::Polynomial::isnegative(void) const
{
	throw std::logic_error("Not implemented: computorv2::Polynomial::isnegative");
    return (false);
}

computorv2::Polynomial computorv2::Polynomial::null(void)
{
	computorv2::Polynomial res(computorv2::IndependentVariable::null());
	res.setCoefficient(0.0);
	res.setExponent(0.0);
	res.setFreeTerm(0.0);
	return (res);
}

computorv2::Polynomial computorv2::Polynomial::unity(void)
{
	computorv2::Polynomial res(computorv2::IndependentVariable::null());
	res.setCoefficient(1.0);
	res.setExponent(0.0);
	res.setFreeTerm(0.0);
	return (res);
}

void computorv2::Polynomial::init(const computorv2::Object* base)
{
	this->_coefficient = NULL;
	this->_base        = NULL;
	this->_exponent    = NULL;
	this->_freeterm    = NULL;

	this->setCoefficient(1.0);
	this->setBase(base);
	this->setExponent(1.0);
	this->setFreeTerm(0.0);
}

void computorv2::Polynomial::delCoefficient(void)
{
	delete (this->_coefficient);
	this->_coefficient = NULL;
}

void computorv2::Polynomial::delBase(void)
{
	delete (this->_base);
	this->_base = NULL;
}

void computorv2::Polynomial::delExponent(void)
{
	delete (this->_exponent);
	this->_exponent = NULL;
}

void computorv2::Polynomial::delFreeTerm(void)
{
	delete (this->_freeterm);
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

computorv2::Polynomial::Polynomial(const computorv2::Polynomial& other)
{
	this->init(other.getBase());
	*this = other;
}

computorv2::Polynomial::Polynomial(const computorv2::UsualFunction& base)
{
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
	if (coefficient == this)
	{
		throw std::logic_error("coefficient == this!");
	}
	if (coefficient->isnull())
	{
		this->delBase();
		this->_coefficient = computorv2::Complex::null().clone();
		this->_base        = computorv2::IndependentVariable::null().clone();
	}
	else
	{
		this->_coefficient = coefficient->clone();
	}
}

void computorv2::Polynomial::setBase(const computorv2::Object* base)
{
	this->delBase();
	if (!base)
	{
		throw std::logic_error("Can't set base to NULL");
	}
	if (base == this)
	{
		throw std::logic_error("base == this!");
	}
	if (base->isnull())
	{
		this->delCoefficient();
		this->_coefficient = computorv2::Complex::null().clone();
		this->_base        = computorv2::IndependentVariable::null().clone();
	}
	else
	{
		this->_base = base->clone();
	}
}

void computorv2::Polynomial::setExponent(const computorv2::Object* exponent)
{
	this->delExponent();
	if (!exponent)
	{
		throw std::logic_error("Can't set exponent to NULL");
	}
	if (exponent == this)
	{
		throw std::logic_error("exponent == this!");
	}
	if (exponent->isnull())
	{
		this->delBase();
		this->_exponent = computorv2::Complex::null().clone();
		this->_base     = computorv2::IndependentVariable::null().clone();
	}
	else
	{
		this->_exponent = exponent->clone();
	}
}

void computorv2::Polynomial::setFreeTerm(const computorv2::Object* freeterm)
{
	this->delFreeTerm();
	if (!freeterm)
	{
		throw std::logic_error("Can't set freeterm to NULL");
	}
	if (freeterm->isnull())
	{
		this->_freeterm = computorv2::Complex::null().clone();
	}
	else
	{
		this->_freeterm = freeterm->clone();
	}
}

void computorv2::Polynomial::setCoefficient(const double coefficient)
{
	const computorv2::Complex z = computorv2::Complex(coefficient, 0.0);
	this->setCoefficient(&z);
}

void computorv2::Polynomial::setExponent(const double exponent)
{
	const computorv2::Complex z = computorv2::Complex(exponent, 0.0);
	this->setExponent(&z);
}

void computorv2::Polynomial::setFreeTerm(const double freeterm)
{
	const computorv2::Complex z = computorv2::Complex(freeterm, 0.0);
	this->setFreeTerm(&z);
}

std::ostream& operator<<(std::ostream& left, const computorv2::Polynomial& right)
{
	left << right.toString();
	return (left);
}

#endif//!__COMPUTORV2_SOURCES_POLYNOMIAL
