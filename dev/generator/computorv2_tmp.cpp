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

# include "../include/computorv2.hpp"
# include "../include/Object.hpp"
# include "../include/Matrix.hpp"
# include "../include/Vector.hpp"
# include "../include/Complex.hpp"
# include "../include/Polynomial.hpp"
# include "../include/UsualFunction.hpp"
# include "../include/IndependentVariable.hpp"
# include <sstream>
# include <unistd.h>

std::string computorv2::tolower(const std::string s)
{
	std::string u = "";
	for (size_t i = 0; i < s.length(); i++)
	{
		u += std::tolower(s[i]);
	}
	return (u);
}

bool computorv2::isname(const std::string& name)
{
	const std::string::size_type len = name.size();
	if ((len < 1) || (!IS_VARSTART(name[0])))
	{
		return (false);
	}
	for (std::string::size_type i = 0; i < len; ++i)
	{
		if (!IS_VARCHAR(name[i]))
		{
			return (false);
		}
	}
	return (true);
}

bool computorv2::isUsualFunction(const std::string& name)
{
	if (name == "ln")
	{
		return (true);
	}
	return (false);
}

std::string computorv2::ltrim(const std::string s)
{
	std::string::size_type first = s.find_first_not_of("\v\f\t ");
	if (first == std::string::npos)
	{
		return ("");
	}
	return (s.substr(first, (s.length() - first)));
}

/* -------------------------------- ln -------------------------------- */

computorv2::UsualFunction computorv2::ln(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'ln' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::ln(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::ln(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::ln(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::ln(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::ln(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'ln' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::ln(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("ln", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::ln(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("ln", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::ln(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("ln", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::ln(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("ln", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::ln(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("ln", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- exp -------------------------------- */

computorv2::UsualFunction computorv2::exp(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'exp' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::exp(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::exp(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::exp(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::exp(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::exp(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'exp' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::exp(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("exp", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::exp(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("exp", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::exp(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("exp", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::exp(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("exp", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::exp(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("exp", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- sin -------------------------------- */

computorv2::UsualFunction computorv2::sin(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'sin' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::sin(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::sin(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::sin(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::sin(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::sin(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'sin' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::sin(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("sin", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::sin(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("sin", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::sin(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("sin", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::sin(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("sin", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::sin(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("sin", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- cos -------------------------------- */

computorv2::UsualFunction computorv2::cos(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'cos' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::cos(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::cos(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::cos(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::cos(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::cos(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'cos' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::cos(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("cos", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::cos(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("cos", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::cos(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("cos", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::cos(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("cos", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::cos(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("cos", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- tan -------------------------------- */

computorv2::UsualFunction computorv2::tan(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'tan' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::tan(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::tan(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::tan(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::tan(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::tan(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'tan' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::tan(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("tan", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::tan(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("tan", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::tan(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("tan", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::tan(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("tan", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::tan(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("tan", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- sinh -------------------------------- */

computorv2::UsualFunction computorv2::sinh(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'sinh' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::sinh(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::sinh(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::sinh(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::sinh(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::sinh(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'sinh' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::sinh(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("sinh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::sinh(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("sinh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::sinh(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("sinh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::sinh(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("sinh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::sinh(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("sinh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- cosh -------------------------------- */

computorv2::UsualFunction computorv2::cosh(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'cosh' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::cosh(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::cosh(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::cosh(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::cosh(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::cosh(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'cosh' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::cosh(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("cosh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::cosh(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("cosh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::cosh(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("cosh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::cosh(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("cosh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::cosh(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("cosh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- tanh -------------------------------- */

computorv2::UsualFunction computorv2::tanh(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'tanh' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::tanh(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::tanh(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::tanh(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::tanh(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::tanh(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'tanh' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::tanh(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("tanh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::tanh(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("tanh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::tanh(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("tanh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::tanh(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("tanh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::tanh(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("tanh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- arcsin -------------------------------- */

computorv2::UsualFunction computorv2::arcsin(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'arcsin' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::arcsin(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::arcsin(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::arcsin(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::arcsin(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::arcsin(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'arcsin' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::arcsin(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("arcsin", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arcsin(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("arcsin", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arcsin(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("arcsin", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arcsin(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("arcsin", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arcsin(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("arcsin", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- arccos -------------------------------- */

computorv2::UsualFunction computorv2::arccos(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'arccos' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::arccos(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::arccos(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::arccos(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::arccos(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::arccos(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'arccos' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::arccos(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("arccos", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arccos(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("arccos", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arccos(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("arccos", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arccos(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("arccos", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arccos(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("arccos", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- arctan -------------------------------- */

computorv2::UsualFunction computorv2::arctan(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'arctan' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::arctan(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::arctan(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::arctan(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::arctan(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::arctan(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'arctan' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::arctan(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("arctan", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arctan(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("arctan", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arctan(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("arctan", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arctan(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("arctan", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arctan(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("arctan", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- arcsinh -------------------------------- */

computorv2::UsualFunction computorv2::arcsinh(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'arcsinh' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::arcsinh(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::arcsinh(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::arcsinh(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::arcsinh(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::arcsinh(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'arcsinh' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::arcsinh(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("arcsinh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arcsinh(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("arcsinh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arcsinh(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("arcsinh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arcsinh(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("arcsinh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arcsinh(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("arcsinh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- arccosh -------------------------------- */

computorv2::UsualFunction computorv2::arccosh(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'arccosh' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::arccosh(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::arccosh(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::arccosh(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::arccosh(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::arccosh(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'arccosh' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::arccosh(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("arccosh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arccosh(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("arccosh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arccosh(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("arccosh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arccosh(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("arccosh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arccosh(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("arccosh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* -------------------------------- arctanh -------------------------------- */

computorv2::UsualFunction computorv2::arctanh(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'arctanh' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::arctanh(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::arctanh(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::arctanh(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::arctanh(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::arctanh(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'arctanh' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::UsualFunction::null());
}

computorv2::UsualFunction computorv2::arctanh(const computorv2::Matrix& left)
{
    computorv2::UsualFunction res("arctanh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arctanh(const computorv2::Complex& left)
{
    computorv2::UsualFunction res("arctanh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arctanh(const computorv2::Polynomial& left)
{
    computorv2::UsualFunction res("arctanh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arctanh(const computorv2::UsualFunction& left)
{
    computorv2::UsualFunction res("arctanh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

computorv2::UsualFunction computorv2::arctanh(const computorv2::IndependentVariable& left)
{
    computorv2::UsualFunction res("arctanh", computorv2::IndependentVariable::null());
	res.setBody(AS_OBJECT(&left));
	return (res);
}

/* --------------------- isfreeterm --------------------- */

bool computorv2::isfreeterm(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'isfreeterm' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::isfreeterm(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::isfreeterm(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::isfreeterm(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::isfreeterm(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::isfreeterm(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'isfreeterm' not supported for type '" + left->getTypeName() + "'.");
    return (0);
}

bool computorv2::isfreeterm(const computorv2::Matrix& left)
{
    (void)left;
    throw std::logic_error("Operation 'isfreeterm' not supported for type: 'Matrix'");
    return (false);
}

bool computorv2::isfreeterm(const computorv2::Complex& left)
{
    (void)left;
    throw std::logic_error("Operation 'isfreeterm' not supported for type: 'Complex'");
    return (false);
}

bool computorv2::isfreeterm(const computorv2::Polynomial& left)
{
    (void)left;
    throw std::logic_error("Operation 'isfreeterm' not supported for type: 'Polynomial'");
    return (false);
}

bool computorv2::isfreeterm(const computorv2::UsualFunction& left)
{
    (void)left;
    throw std::logic_error("Operation 'isfreeterm' not supported for type: 'UsualFunction'");
    return (false);
}

bool computorv2::isfreeterm(const computorv2::IndependentVariable& left)
{
    (void)left;
    throw std::logic_error("Operation 'isfreeterm' not supported for type: 'IndependentVariable'");
    return (false);
}

/* -------------------------------------------- eql -------------------------------------------- */

bool computorv2::eql(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'eql' not supported between null types.");
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_MATRIX(right)));
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_COMPLEX(right)));
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_POLYNOMIAL(right)));
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_USFUNC(right)));
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_INDVAR(right)));
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_MATRIX(right)));
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_COMPLEX(right)));
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)));
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_USFUNC(right)));
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_INDVAR(right)));
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_MATRIX(right)));
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)));
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)));
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_USFUNC(right)));
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_INDVAR(right)));
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_USFUNC(left), *AS_MATRIX(right)));
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_USFUNC(left), *AS_COMPLEX(right)));
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_USFUNC(left), *AS_POLYNOMIAL(right)));
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::eql(*AS_USFUNC(left), *AS_USFUNC(right)));
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::eql(*AS_USFUNC(left), *AS_INDVAR(right)));
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_INDVAR(left), *AS_MATRIX(right)));
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_INDVAR(left), *AS_COMPLEX(right)));
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_INDVAR(left), *AS_POLYNOMIAL(right)));
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::eql(*AS_INDVAR(left), *AS_USFUNC(right)));
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::eql(*AS_INDVAR(left), *AS_INDVAR(right)));
    throw std::logic_error("Operation 'eql' not supported between types '" + left->getTypeName() + "' and '" + right->getTypeName() + "'.");
    return (0);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Matrix' and 'Matrix'.");
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Matrix' and 'Complex'.");
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Matrix' and 'Polynomial'.");
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Matrix' and 'UsualFunction'.");
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Complex' and 'Matrix'.");
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Complex' and 'Complex'.");
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Complex' and 'Polynomial'.");
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Complex' and 'UsualFunction'.");
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Complex' and 'IndependentVariable'.");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Polynomial' and 'Matrix'.");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Polynomial' and 'Complex'.");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Polynomial' and 'Polynomial'.");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Polynomial' and 'UsualFunction'.");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Polynomial' and 'IndependentVariable'.");
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'UsualFunction' and 'Matrix'.");
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'UsualFunction' and 'Complex'.");
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'UsualFunction' and 'Polynomial'.");
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'UsualFunction' and 'UsualFunction'.");
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'UsualFunction' and 'IndependentVariable'.");
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'IndependentVariable' and 'Complex'.");
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'IndependentVariable' and 'Polynomial'.");
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'IndependentVariable' and 'UsualFunction'.");
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'IndependentVariable' and 'IndependentVariable'.");
    return (false);
}

/* ------------------------------ neg ------------------------------ */

computorv2::Object* computorv2::neg(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'neg' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::neg(*AS_MATRIX(left)).clone());
    else if (IS_COMPLEX(left))
        return (computorv2::neg(*AS_COMPLEX(left)).clone());
    else if (IS_POLYNOMIAL(left))
        return (computorv2::neg(*AS_POLYNOMIAL(left)).clone());
    else if (IS_USFUNC(left))
        return (computorv2::neg(*AS_USFUNC(left)).clone());
    else if (IS_INDVAR(left))
        return (computorv2::neg(*AS_INDVAR(left)).clone());
    throw std::logic_error("Operation 'neg' not supported for type '" + left->getTypeName() + "'.");
    return (0);
}

computorv2::Matrix computorv2::neg(const computorv2::Matrix& left)
{
    (void)left;
    throw std::logic_error("Operation 'neg' not supported for type: 'Matrix'");
    return (computorv2::Matrix::null());
}

computorv2::Complex computorv2::neg(const computorv2::Complex& left)
{
    (void)left;
    throw std::logic_error("Operation 'neg' not supported for type: 'Complex'");
    return (computorv2::Complex::null());
}

computorv2::Polynomial computorv2::neg(const computorv2::Polynomial& left)
{
    (void)left;
    throw std::logic_error("Operation 'neg' not supported for type: 'Polynomial'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::neg(const computorv2::UsualFunction& left)
{
    (void)left;
    throw std::logic_error("Operation 'neg' not supported for type: 'UsualFunction'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::neg(const computorv2::IndependentVariable& left)
{
    (void)left;
    throw std::logic_error("Operation 'neg' not supported for type: 'IndependentVariable'");
    return (computorv2::Polynomial::null());
}

/* ------------------------------ inv ------------------------------ */

computorv2::Object* computorv2::inv(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'inv' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::inv(*AS_MATRIX(left)).clone());
    else if (IS_COMPLEX(left))
        return (computorv2::inv(*AS_COMPLEX(left)).clone());
    else if (IS_POLYNOMIAL(left))
        return (computorv2::inv(*AS_POLYNOMIAL(left)).clone());
    else if (IS_USFUNC(left))
        return (computorv2::inv(*AS_USFUNC(left)).clone());
    else if (IS_INDVAR(left))
        return (computorv2::inv(*AS_INDVAR(left)).clone());
    throw std::logic_error("Operation 'inv' not supported for type '" + left->getTypeName() + "'.");
    return (0);
}

computorv2::Matrix computorv2::inv(const computorv2::Matrix& left)
{
    (void)left;
    throw std::logic_error("Operation 'inv' not supported for type: 'Matrix'");
    return (computorv2::Matrix::null());
}

computorv2::Complex computorv2::inv(const computorv2::Complex& left)
{
    (void)left;
    throw std::logic_error("Operation 'inv' not supported for type: 'Complex'");
    return (computorv2::Complex::null());
}

computorv2::Polynomial computorv2::inv(const computorv2::Polynomial& left)
{
    (void)left;
    throw std::logic_error("Operation 'inv' not supported for type: 'Polynomial'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::inv(const computorv2::UsualFunction& left)
{
    (void)left;
    throw std::logic_error("Operation 'inv' not supported for type: 'UsualFunction'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::inv(const computorv2::IndependentVariable& left)
{
    (void)left;
    throw std::logic_error("Operation 'inv' not supported for type: 'IndependentVariable'");
    return (computorv2::Polynomial::null());
}

/* ----------------------------------------------------- mul ----------------------------------------------------- */

computorv2::Object* computorv2::mul(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'mul' not supported between null types.");
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_MATRIX(right)).clone());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_COMPLEX(right)).clone());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_USFUNC(right)).clone());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_INDVAR(right)).clone());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_MATRIX(right)).clone());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_COMPLEX(right)).clone());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_USFUNC(right)).clone());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_INDVAR(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).clone());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_USFUNC(left), *AS_MATRIX(right)).clone());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_USFUNC(left), *AS_COMPLEX(right)).clone());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::mul(*AS_USFUNC(left), *AS_USFUNC(right)).clone());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::mul(*AS_USFUNC(left), *AS_INDVAR(right)).clone());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_INDVAR(left), *AS_MATRIX(right)).clone());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_INDVAR(left), *AS_COMPLEX(right)).clone());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::mul(*AS_INDVAR(left), *AS_USFUNC(right)).clone());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::mul(*AS_INDVAR(left), *AS_INDVAR(right)).clone());
    throw std::logic_error("Operation 'mul' not supported between types '" + left->getTypeName() + "' and '" + right->getTypeName() + "'.");
    return (0);
}

computorv2::Matrix computorv2::mul(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Matrix::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Matrix computorv2::mul(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Matrix::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Matrix computorv2::mul(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Matrix::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Complex computorv2::mul(const computorv2::Complex& left, const computorv2::Complex& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Complex::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'Complex'.");
    return (computorv2::Complex::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'Complex'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'Complex'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'Complex'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

/* ----------------------------------------------------- div ----------------------------------------------------- */

computorv2::Object* computorv2::div(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'div' not supported between null types.");
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_MATRIX(right)).clone());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_COMPLEX(right)).clone());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_USFUNC(right)).clone());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_INDVAR(right)).clone());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_MATRIX(right)).clone());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_COMPLEX(right)).clone());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_USFUNC(right)).clone());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_INDVAR(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).clone());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_USFUNC(left), *AS_MATRIX(right)).clone());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_USFUNC(left), *AS_COMPLEX(right)).clone());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::div(*AS_USFUNC(left), *AS_USFUNC(right)).clone());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::div(*AS_USFUNC(left), *AS_INDVAR(right)).clone());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_INDVAR(left), *AS_MATRIX(right)).clone());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_INDVAR(left), *AS_COMPLEX(right)).clone());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::div(*AS_INDVAR(left), *AS_USFUNC(right)).clone());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::div(*AS_INDVAR(left), *AS_INDVAR(right)).clone());
    throw std::logic_error("Operation 'div' not supported between types '" + left->getTypeName() + "' and '" + right->getTypeName() + "'.");
    return (0);
}

computorv2::Matrix computorv2::div(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Matrix computorv2::div(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Matrix computorv2::div(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Complex computorv2::div(const computorv2::Complex& left, const computorv2::Complex& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::mul(left, computorv2::inv(right)));
}

/* ----------------------------------------------------- add ----------------------------------------------------- */

computorv2::Object* computorv2::add(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'add' not supported between null types.");
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_MATRIX(right)).clone());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_COMPLEX(right)).clone());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_USFUNC(right)).clone());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_INDVAR(right)).clone());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_MATRIX(right)).clone());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_COMPLEX(right)).clone());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_USFUNC(right)).clone());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_INDVAR(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).clone());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_USFUNC(left), *AS_MATRIX(right)).clone());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_USFUNC(left), *AS_COMPLEX(right)).clone());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::add(*AS_USFUNC(left), *AS_USFUNC(right)).clone());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::add(*AS_USFUNC(left), *AS_INDVAR(right)).clone());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_INDVAR(left), *AS_MATRIX(right)).clone());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_INDVAR(left), *AS_COMPLEX(right)).clone());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::add(*AS_INDVAR(left), *AS_USFUNC(right)).clone());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::add(*AS_INDVAR(left), *AS_INDVAR(right)).clone());
    throw std::logic_error("Operation 'add' not supported between types '" + left->getTypeName() + "' and '" + right->getTypeName() + "'.");
    return (0);
}

computorv2::Matrix computorv2::add(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Matrix computorv2::add(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Matrix computorv2::add(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Complex' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Complex computorv2::add(const computorv2::Complex& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Complex' and 'Complex'.");
    return (computorv2::Complex::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Complex' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Complex' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Complex' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'Complex'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'Complex'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'Complex'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

/* ----------------------------------------------------- sub ----------------------------------------------------- */

computorv2::Object* computorv2::sub(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'sub' not supported between null types.");
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_MATRIX(right)).clone());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_COMPLEX(right)).clone());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_USFUNC(right)).clone());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_INDVAR(right)).clone());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_MATRIX(right)).clone());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_COMPLEX(right)).clone());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_USFUNC(right)).clone());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_INDVAR(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).clone());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_USFUNC(left), *AS_MATRIX(right)).clone());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_USFUNC(left), *AS_COMPLEX(right)).clone());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::sub(*AS_USFUNC(left), *AS_USFUNC(right)).clone());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::sub(*AS_USFUNC(left), *AS_INDVAR(right)).clone());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_INDVAR(left), *AS_MATRIX(right)).clone());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_INDVAR(left), *AS_COMPLEX(right)).clone());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::sub(*AS_INDVAR(left), *AS_USFUNC(right)).clone());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::sub(*AS_INDVAR(left), *AS_INDVAR(right)).clone());
    throw std::logic_error("Operation 'sub' not supported between types '" + left->getTypeName() + "' and '" + right->getTypeName() + "'.");
    return (0);
}

computorv2::Matrix computorv2::sub(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Matrix computorv2::sub(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Matrix computorv2::sub(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Complex computorv2::sub(const computorv2::Complex& left, const computorv2::Complex& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::add(left, computorv2::neg(right)));
}

/* ----------------------------------------------------- mod ----------------------------------------------------- */

computorv2::Object* computorv2::mod(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'mod' not supported between null types.");
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_MATRIX(right)).clone());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_COMPLEX(right)).clone());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_USFUNC(right)).clone());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_INDVAR(right)).clone());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_MATRIX(right)).clone());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_COMPLEX(right)).clone());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_USFUNC(right)).clone());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_INDVAR(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).clone());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_USFUNC(left), *AS_MATRIX(right)).clone());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_USFUNC(left), *AS_COMPLEX(right)).clone());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::mod(*AS_USFUNC(left), *AS_USFUNC(right)).clone());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::mod(*AS_USFUNC(left), *AS_INDVAR(right)).clone());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_INDVAR(left), *AS_MATRIX(right)).clone());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_INDVAR(left), *AS_COMPLEX(right)).clone());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::mod(*AS_INDVAR(left), *AS_USFUNC(right)).clone());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::mod(*AS_INDVAR(left), *AS_INDVAR(right)).clone());
    throw std::logic_error("Operation 'mod' not supported between types '" + left->getTypeName() + "' and '" + right->getTypeName() + "'.");
    return (0);
}

computorv2::Matrix computorv2::mod(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Matrix computorv2::mod(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Matrix computorv2::mod(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Complex' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Complex computorv2::mod(const computorv2::Complex& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Complex' and 'Complex'.");
    return (computorv2::Complex::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Complex' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Complex' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Complex' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'Complex'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'Complex'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'Complex'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

/* ----------------------------------------------------- pow ----------------------------------------------------- */

computorv2::Object* computorv2::pow(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'pow' not supported between null types.");
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_MATRIX(right)).clone());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_COMPLEX(right)).clone());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_USFUNC(right)).clone());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_INDVAR(right)).clone());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_MATRIX(right)).clone());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_COMPLEX(right)).clone());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_USFUNC(right)).clone());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_INDVAR(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).clone());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).clone());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_USFUNC(left), *AS_MATRIX(right)).clone());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_USFUNC(left), *AS_COMPLEX(right)).clone());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::pow(*AS_USFUNC(left), *AS_USFUNC(right)).clone());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::pow(*AS_USFUNC(left), *AS_INDVAR(right)).clone());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_INDVAR(left), *AS_MATRIX(right)).clone());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_INDVAR(left), *AS_COMPLEX(right)).clone());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).clone());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::pow(*AS_INDVAR(left), *AS_USFUNC(right)).clone());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::pow(*AS_INDVAR(left), *AS_INDVAR(right)).clone());
    throw std::logic_error("Operation 'pow' not supported between types '" + left->getTypeName() + "' and '" + right->getTypeName() + "'.");
    return (0);
}

computorv2::Matrix computorv2::pow(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Matrix computorv2::pow(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix::null());
}

computorv2::Polynomial computorv2::pow(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Matrix computorv2::pow(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Complex' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Complex computorv2::pow(const computorv2::Complex& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Complex' and 'Complex'.");
    return (computorv2::Complex::null());
}

computorv2::Polynomial computorv2::pow(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        if (right.isnull())
            throw std::logic_error("Zero to the power of zero!");
        if (right.isnegative())
            throw std::logic_error("Division by zero!");
        return (computorv2::Polynomial::null());
    }
    if (left.isunity() || right.isnull())
    {
        return (computorv2::Polynomial::unity());
    }
    computorv2::Polynomial res("undefined");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

/* ----------------------------------------------------- drv ----------------------------------------------------- */

computorv2::Polynomial computorv2::drv(const computorv2::Object* left, const computorv2::IndependentVariable& right)
{
    if (!left)
        throw std::logic_error("Operation 'drv' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::drv(*AS_MATRIX(left), right));
    else if (IS_COMPLEX(left))
        return (computorv2::drv(*AS_COMPLEX(left), right));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::drv(*AS_POLYNOMIAL(left), right));
    else if (IS_USFUNC(left))
        return (computorv2::drv(*AS_USFUNC(left), right));
    else if (IS_INDVAR(left))
        return (computorv2::drv(*AS_INDVAR(left), right));
    throw std::logic_error("Operation 'drv' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::drv(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'drv' not supported for type: 'Matrix'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::drv(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'drv' not supported for type: 'Complex'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::drv(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'drv' not supported for type: 'Polynomial'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::drv(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'drv' not supported for type: 'UsualFunction'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::drv(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'drv' not supported for type: 'IndependentVariable'");
    return (computorv2::Polynomial::null());
}

#endif//!__COMPUTORV2_SOURCES_COMPUTORV2
