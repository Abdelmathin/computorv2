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

computorv2::Object* computorv2::div(const computorv2::Object* left, const computorv2::Object* right)
{
	std::stringstream ss("");
	ss << "Can't div objects!";
	ss << ", left->getType() = "  << left->getType();
	ss << ", right->getType() = " << right->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (NULL);
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


/* Polynomial (add) */
computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
	return (computorv2::add(computorv2::Polynomial(&left), computorv2::Polynomial(&right)));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
	return (computorv2::add(computorv2::Polynomial(&left), computorv2::Polynomial(&right)));
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

/* Polynomial (mul) */


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
		if (IS_USUAL_FUNCTION(right))
			return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_USUAL_FUNCTION(right)).copy());
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

/* ------------------------------------------------------------------------ eql ------------------------------------------------------------------------ */

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
	// if (IS_COMPLEX(left))
	// {
	// 	if (IS_COMPLEX(right))
	// 		return (computorv2::eql(*AS_COMPLEX(left), *AS_COMPLEX(right)));
	// }
	// if (IS_INDEPENDENT(left))
	// {
	// 	if (IS_INDEPENDENT(right))
	// 		return (computorv2::eql(*AS_INDEPENDENT(left), *AS_INDEPENDENT(right)));
	// 	if (IS_USUAL_FUNCTION(right))
	// 		return (computorv2::eql(*AS_INDEPENDENT(left), *AS_USUAL_FUNCTION(right)));
	// 	if (IS_POLYNOMIAL(right))
	// 		return (computorv2::eql(*AS_INDEPENDENT(left), *AS_POLYNOMIAL(right)));
	// }
	// if (IS_USUAL_FUNCTION(left))
	// {
	// 	if (IS_USUAL_FUNCTION(right))
	// 		return (computorv2::eql(*AS_USUAL_FUNCTION(left), *AS_USUAL_FUNCTION(right)));
	// }
	std::stringstream ss("");
	ss << "ComparisonError: ";
	ss << ", left->getType()  = " << left->getType();
	ss << ", right->getType() = " << right->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (false);
}


bool computorv2::eql(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
	return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
	return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
	bool result = false;
	const computorv2::Object* v = right.evaluate();
	if (IS_COMPLEX(v))
	{
		result = computorv2::eql(left, AS_COMPLEX(v));
	}
	delete (v);
	return (result);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
	return (computorv2::eql(right, left));
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
	bool result = false;
	const computorv2::Object* v = right.evaluate();
	if (IS_COMPLEX(v))
	{
		result = computorv2::eql(left, AS_COMPLEX(v));
	}
	delete (v);
	return (result);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
	return (computorv2::eql(right, left));
}


bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
	return (computorv2::eql(right, left));
}

/* -------------------------------------------------------------------- derivative -------------------------------------------------------------------- */

/* derivative (Object) */
computorv2::Polynomial computorv2::derivative(const computorv2::Object* obj, const computorv2::IndependentVariable& x)
{
	if (!obj)
	{
		throw std::logic_error("Error: Null pointer passed to derivative function.");
	}
	if (IS_COMPLEX(obj))
		return (computorv2::derivative(*AS_COMPLEX(obj), x));
	if (IS_INDEPENDENT(obj))
		return (computorv2::derivative(*AS_INDEPENDENT(obj), x));
	else if (IS_POLYNOMIAL(obj))
		return (computorv2::derivative(*AS_POLYNOMIAL(obj), x));
	std::stringstream ss("");
	ss << "DerivativeError: ";
	ss << ", obj->getType()  = " << obj->getType();
	ss << std::endl;
	throw std::logic_error(ss.str());
	return (computorv2::Polynomial("x"));
}

#endif//!__COMPUTORV2_SOURCES_COMPUTORV2
