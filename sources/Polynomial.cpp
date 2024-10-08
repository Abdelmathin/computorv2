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
	const computorv2::Object* p = this->evaluate();
	if (!IS_POLYNOMIAL(p))
	{
		const std::string s = p->toString();
		delete (p);
		return (s);
	}
	const computorv2::Polynomial* poly = AS_POLYNOMIAL(p);
	if ((poly->getCoefficient()->isnull()) || (poly->getBase()->isnull()))
	{
		const std::string s = poly->_freeterm->toString();
		delete (poly);
		return (s);
	}
	if (poly->_exponent->isnull())
	{
		const computorv2::Object *v = computorv2::add(poly->getCoefficient(), poly->getFreeTerm());
		const std::string s = v->toString();
		delete (poly);
		delete (v);
		return (s);
	}
	std::stringstream ss("");
	{
		const computorv2::Object* a = this->_coefficient->evaluate();
		const computorv2::Object* x = this->_base->evaluate();
		const computorv2::Object* n = this->_exponent->evaluate();
		const std::string a_str     = a->toString();
		if (a_str == "-1")
		{
			ss << "-";
		}
		else if (a_str != "1")
		{
			if (!computorv2::isfreeterm(a))
			{
				ss << "(";
			}
			ss << a_str;
			if (!computorv2::isfreeterm(a))
			{
				ss << ")";
			}
			if (!n->isnull())
			{
				ss << " * ";				
			}
		}
		if (!n->isnull())
		{
			if (!computorv2::isfreeterm(x))
			{
				ss << "(";
			}
			ss << x->toString();
			if (!computorv2::isfreeterm(x))
			{
				ss << ")";
			}
			delete (a);
			delete (x);
			const std::string s = n->toString();
			if (!n->isunity())
			{
				ss << "^";
				if ((s[0] == '-') || (!computorv2::isfreeterm(n)))
				{
					ss << "(";
				}
				ss << s;
				if ((s[0] == '-') || (!computorv2::isfreeterm(n)))
				{
					ss << ")";
				}
			}
		}
		delete (n);
	}
	if (!poly->getFreeTerm()->isnull())
	{
		std::string b = poly->_freeterm->toString();
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
	delete (poly);
    return (ss.str());
}

computorv2::Object* computorv2::Polynomial::copy(void) const
{
    return ( new computorv2::Polynomial(*this) );
}

computorv2::Object* computorv2::Polynomial::evaluate(void) const
{
	return (this->copy());
	std::cout << ">>>> evaluate(" << this->getTypeName() << ")" << std::endl;
	const computorv2::Object* a = this->getCoefficient()->evaluate();
	const computorv2::Object* x = this->getBase()->evaluate();
	const computorv2::Object* n = this->getExponent()->evaluate();
	const computorv2::Object* b = this->getFreeTerm()->evaluate();
	const computorv2::Object* p = computorv2::pow(x, n);
	const computorv2::Object* e = computorv2::mul(a, p);
	computorv2::Object* f = computorv2::add(e, b);
	delete (a);
	delete (x);
	delete (n);
	delete (b);
	delete (p);
	delete (e);
	if (!IS_POLYNOMIAL(f))
	{
		return (f);
	}
	computorv2::Object* evaluated = f;
	const computorv2::Polynomial* res = AS_POLYNOMIAL(f);
	if (res->getCoefficient()->isunity() && res->getBase()->isunity() && res->getFreeTerm()->isnull())
	{
		evaluated = res->getBase()->evaluate();
		delete (res);
	}
	return (evaluated);
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
	const computorv2::Object* e = this->evaluate();
	if (!IS_POLYNOMIAL(e))
	{
		result = e->isunity();
	}
	delete (e);
	return (result);
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
	if (coefficient->isnull())
	{
		this->delBase();
		this->_coefficient = computorv2::Complex::null().copy();
		this->_base        = computorv2::IndependentVariable::null().copy();
	}
	else
	{
		this->_coefficient = coefficient->evaluate();
	}
}

void computorv2::Polynomial::setBase(const computorv2::Object* base)
{
	this->delBase();
	if (!base)
	{
		throw std::logic_error("Can't set base to NULL");
	}
	if (base->isnull())
	{
		this->delCoefficient();
		this->_coefficient = computorv2::Complex::null().copy();
		this->_base        = computorv2::IndependentVariable::null().copy();
	}
	else
	{
		this->_base = base->evaluate();
	}
}

void computorv2::Polynomial::setExponent(const computorv2::Object* exponent)
{
	this->delExponent();
	if (!exponent)
	{
		throw std::logic_error("Can't set exponent to NULL");
	}
	if (exponent->isnull())
	{
		this->delBase();
		this->_exponent = computorv2::Complex::null().copy();
		this->_base     = computorv2::IndependentVariable::null().copy();
	}
	else
	{
		this->_exponent = exponent->evaluate();
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
		this->_freeterm = computorv2::Complex::null().copy();
	}
	else
	{
		this->_freeterm = freeterm->evaluate();
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
