/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   computorv2.cpp                                     :+:      :+:    :+:    */
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

#ifndef __COMPUTORV2_SOURCES_COMPUTORV2
# define __COMPUTORV2_SOURCES_COMPUTORV2

#include "../include/computorv2.hpp"
#include "../include/Object.hpp"
#include "../include/Polynomial.hpp"
#include "../include/utils.hpp"
#include <sstream>
#include <unistd.h>

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
	computorv2::Polynomial res(left);
	res.setExponent(right);
	return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
	computorv2::Polynomial res(&left);
	res.setExponent(right);
	return (res);
}

computorv2::Object* computorv2::pow(const computorv2::Object* left, const computorv2::Object* right)
{
	if (!left)
	{
		throw std::logic_error("left is NULL!");
	}
	if (!right)
	{
		throw std::logic_error("left is NULL!");
	}
	if (right->isnull())
	{
		if (left->isnull())
		{
			throw std::logic_error("Error: Zero to the power of zero!");
		}
		return (computorv2::Complex(1.0, 0.0).copy());
	}
	if (IS_INDEPENDENT(left))
	{
		if (IS_COMPLEX(right))
			return (computorv2::pow(*AS_INDEPENDENT(left), *AS_COMPLEX(right)).copy());
	}
	if (IS_USUAL_FUNCTION(left))
	{
		if (IS_COMPLEX(right))
			return (computorv2::pow(*AS_USUAL_FUNCTION(left), *AS_COMPLEX(right)).copy());		
	}

	std::stringstream ss("");
	ss << "Can't pow objects!";
	ss << ", left->getType() = "  << left->getType();
	ss << ", right->getType() = " << right->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (NULL);
}

bool computorv2::isfreeterm(const computorv2::Object* obj)
{
	if (IS_COMPLEX(obj))
	{
		const computorv2::Complex* z = AS_COMPLEX(obj);
		if ((z->getReal() > 0) && (IS_ZERO(z->getImage())))
		{
			return (true);
		}
		else if ((z->getImage() > 0) && (IS_ZERO(z->getReal())))
		{
			return (true);
		}
		return (z->isnull());
	}
	if (IS_INDEPENDENT(obj))
	{
		return (true);
	}
	if (IS_USUAL_FUNCTION(obj))
	{
		return (true);
	}
	std::cout << "Warning: computorv2::isfreeterm((Not implemented)!)" << std::endl;
	return (false);
}

/* Complex (add) */

computorv2::Complex computorv2::add(const computorv2::Complex& left, const computorv2::Complex& right)
{
	computorv2::Complex res;
	res.setReal(left.getReal()   + right.getReal());
	res.setImage(left.getImage() + right.getImage());
	return (res);
}

/* Polynomial (add) */
computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
	return (computorv2::add(computorv2::Polynomial(&left), computorv2::Polynomial(&right)));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
	return (computorv2::add(computorv2::Polynomial(&left), computorv2::Polynomial(&right)));
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
	computorv2::Polynomial res(left);
	const computorv2::Object* freeterm = computorv2::add(left.getFreeTerm(), &right);
	res.setFreeTerm(freeterm);
	delete (freeterm);
	return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
	return (computorv2::add(right, left));
}


computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
	if (IS_COMPLEX(left.getExponent()) && IS_COMPLEX(right.getExponent()))
	{
		const computorv2::Complex* z1 = AS_COMPLEX(left.getExponent());
		const computorv2::Complex* z2 = AS_COMPLEX(right.getExponent());
		if (IS_ZERO(z1->getImage()) && IS_ZERO(z2->getImage()))
		{
			if (z1->getReal() < z2->getReal())
			{
				return (computorv2::add(right, left));
			}
		}
	}
	if ((computorv2::eql(left.getBase(), right.getBase())) && (computorv2::eql(left.getExponent(), right.getExponent())))
	{
		computorv2::Polynomial res(left.getBase());
		const computorv2::Object* coefficient = computorv2::add(left.getCoefficient(), right.getCoefficient());
		const computorv2::Object* freeterm    = computorv2::add(left.getFreeTerm(), right.getFreeTerm());
		res.setCoefficient(coefficient);
		res.setExponent(left.getExponent());
		res.setFreeTerm(freeterm);
		delete (coefficient);
		delete (freeterm);
		return (res);
	}
	computorv2::Polynomial res(left);
	const computorv2::Object* freeterm = computorv2::add(left.getFreeTerm(), &right);
	res.setFreeTerm(freeterm);
	delete (freeterm);
	return (res);
}

/* Object (add) */

computorv2::Object* computorv2::add(const computorv2::Object* left, const computorv2::Object* right)
{
	if (!left)
	{
		throw std::logic_error("left is NULL!");
	}
	if (!right)
	{
		throw std::logic_error("left is NULL!");
	}
	if (IS_COMPLEX(left))
	{
		if (IS_COMPLEX(right))
			return (computorv2::add(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
		else if (IS_POLYNOMIAL(right))
			return (computorv2::add(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
	}
	else if (IS_POLYNOMIAL(left))
	{
		if (IS_COMPLEX(right))
			return (computorv2::add(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
		else if (IS_POLYNOMIAL(right))
			return (computorv2::add(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
	}
	std::stringstream ss("");
	ss << "Can't add objects!";
	ss << ", left->getType() = "  << left->getType();
	ss << ", right->getType() = " << right->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (NULL);
}

/* Complex (mul) */
computorv2::Complex computorv2::mul(const computorv2::Complex& left, const computorv2::Complex& right)
{
	computorv2::Complex res;
	res.setReal((left.getReal()  * right.getReal() ) - (left.getImage() * right.getImage()));
	res.setImage((left.getReal() * right.getImage()) + (left.getImage() * right.getReal() ));
	return (res);
}

/* Polynomial (mul) */


computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
	computorv2::Polynomial res(left);
	const computorv2::Object* coefficient = computorv2::mul(left.getCoefficient(), &right);
	const computorv2::Object* freeterm    = computorv2::mul(left.getFreeTerm(), &right);
	res.setCoefficient(coefficient);
	res.setFreeTerm(freeterm);
	delete (coefficient);
	delete (freeterm);
	return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
	return (computorv2::mul(right, left));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
	if (computorv2::eql(left.getBase(), right.getBase()))
	{
		computorv2::Polynomial first(left.getBase());
		computorv2::Polynomial second(left.getBase());
		computorv2::Polynomial third(left.getBase());

		computorv2::Object* coefficient = NULL;
		computorv2::Object* exponent    = NULL;

		coefficient = computorv2::mul(left.getCoefficient(), right.getCoefficient());
		first.setCoefficient(coefficient);
		delete (coefficient);

		coefficient = computorv2::mul(left.getCoefficient(), right.getFreeTerm());
		second.setCoefficient(coefficient);
		delete (coefficient);

		coefficient = computorv2::mul(left.getFreeTerm(), right.getCoefficient());
		third.setCoefficient(coefficient);
		delete (coefficient);

		exponent = computorv2::add(left.getExponent(), right.getExponent());
		first.setExponent(exponent);
		second.setExponent(left.getExponent());
		third.setExponent(right.getExponent());
		delete (exponent);

		computorv2::Polynomial tmp   = computorv2::add(computorv2::add(first, second), third);
		computorv2::Object* freeterm = computorv2::mul(left.getFreeTerm(), right.getFreeTerm());
		computorv2::Object* tmp_res  = computorv2::add(AS_OBJECT(&tmp), freeterm);
		computorv2::Polynomial res(*(AS_POLYNOMIAL(tmp_res)));
		delete (tmp_res);
		delete (freeterm);
		return (res);
	}
	computorv2::Polynomial res(left);
	const computorv2::Object* coefficient = computorv2::mul(left.getCoefficient(), &right);
	const computorv2::Object* freeterm    = computorv2::mul(left.getFreeTerm(), &right);
	res.setCoefficient(coefficient);
	res.setFreeTerm(freeterm);
	delete (coefficient);
	delete (freeterm);
	return (res);
}

computorv2::Object* computorv2::mul(const computorv2::Object* left, const computorv2::Object* right)
{
	if (!left)
	{
		throw std::logic_error("left is NULL!");
	}
	if (!right)
	{
		throw std::logic_error("left is NULL!");
	}
	if (IS_COMPLEX(left))
	{
		if (IS_COMPLEX(right))
			return (computorv2::mul(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
		else if (IS_POLYNOMIAL(right))
			return (computorv2::mul(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
	}
	else if (IS_POLYNOMIAL(left))
	{
		if (IS_COMPLEX(right))
			return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
		else if (IS_POLYNOMIAL(right))
			return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
	}
	std::stringstream ss("");
	ss << "MultiplicationError: ";
	ss << ", left->getType()  = " << left->getType();
	ss << ", right->getType() = " << right->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (NULL);
}

/* Object (eql) */
bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
	return (left.getName() == right.getName());
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Complex& right)
{
	if (IS_ZERO(left.getReal() - right.getReal()))
	{
		return (IS_ZERO(left.getImage() - right.getImage()));
	}
	return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
	if (left.getName() == right.getName())
	{
		return (computorv2::eql(left.getBody(), right.getBody()));
	}
	return (false);
}

bool computorv2::eql(const computorv2::Object* left, const computorv2::Object* right)
{
	if (!left)
	{
		throw std::logic_error("left is NULL!");
	}
	if (!right)
	{
		throw std::logic_error("left is NULL!");
	}
	if (IS_COMPLEX(left))
	{
		if (IS_COMPLEX(right))
			return (computorv2::eql(*AS_COMPLEX(left), *AS_COMPLEX(right)));
	}
	if (IS_INDEPENDENT(left))
	{
		if (IS_INDEPENDENT(right))
			return (computorv2::eql(*AS_INDEPENDENT(left), *AS_INDEPENDENT(right)));
	}
	if (IS_USUAL_FUNCTION(left))
	{
		if (IS_USUAL_FUNCTION(right))
			return (computorv2::eql(*AS_USUAL_FUNCTION(left), *AS_USUAL_FUNCTION(right)));
	}
	std::stringstream ss("");
	ss << "ComparisonError: ";
	ss << ", left->getType()  = " << left->getType();
	ss << ", right->getType() = " << right->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (false);
}

/* derivative (Object) */
computorv2::Polynomial computorv2::derivative(const computorv2::Object* obj, const computorv2::IndependentVariable& dx)
{
	if (!obj)
	{
		throw std::logic_error("Error: Null pointer passed to derivative function.");
	}
	if (IS_COMPLEX(obj))
		return (computorv2::derivative(*AS_COMPLEX(obj), dx));
	else if (IS_POLYNOMIAL(obj))
		return (computorv2::derivative(*AS_POLYNOMIAL(obj), dx));
	std::stringstream ss("");
	ss << "DerivativeError: ";
	ss << ", obj->getType()  = " << obj->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (computorv2::Polynomial("x"));
}

/* derivative (Complex) */
computorv2::Polynomial computorv2::derivative(const computorv2::Complex& obj, const computorv2::IndependentVariable& dx)
{
	computorv2::Polynomial res(dx);
	const computorv2::Complex zero(0.0);
	res.setCoefficient(&zero);
	res.setExponent(&zero);
	res.setFreeTerm(&zero);
	return (res);
}

/* derivative (Polynomial) */
computorv2::Polynomial computorv2::derivative(const computorv2::Polynomial& poly, const computorv2::IndependentVariable& dx)
{
	return (poly);
}

#endif//!__COMPUTORV2_SOURCES_COMPUTORV2
