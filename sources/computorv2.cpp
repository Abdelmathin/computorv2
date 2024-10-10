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
        return (true);
    else if (name == "exp")
        return (true);
    else if (name == "sin")
        return (true);
    else if (name == "cos")
        return (true);
    else if (name == "tan")
        return (true);
    else if (name == "arcsin")
        return (true);
    else if (name == "arccos")
        return (true);
    else if (name == "arctan")
        return (true);
    else if (name == "sinh")
        return (true);
    else if (name == "cosh")
        return (true);
    else if (name == "tanh")
        return (true);
    else if (name == "arcsinh")
        return (true);
    else if (name == "arccosh")
        return (true);
    else if (name == "arctanh")
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    return (computorv2::UsualFunction("", computorv2::IndependentVariable::null()));
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
    if (IS_ZERO(left.getReal()))
    {
        if (IS_ZERO(left.getImage()))
        {
            return (true);
        }
        return (left.getImage() > 0);
    }
    if (IS_ZERO(left.getImage()))
    {
        return (left.getReal() > 0);
    }
    return (false);
}

bool computorv2::isfreeterm(const computorv2::Polynomial& left)
{
    if (left.getCoefficient()->isnull() || left.getBase()->isnull())
    {
        return (computorv2::isfreeterm(left.getFreeTerm()));
    }
    return (false);
}

bool computorv2::isfreeterm(const computorv2::UsualFunction& left)
{
    (void)left;
    return (true);
}

bool computorv2::isfreeterm(const computorv2::IndependentVariable& left)
{
    (void)left;
    return (true);
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
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    return (computorv2::eql(right, left));
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    return (computorv2::eql(computorv2::Polynomial(right), left));
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::eql(computorv2::Polynomial(right), left));
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    return (computorv2::eql(right, left));
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Complex& right)
{
    if (IS_ZERO(left.getReal() - right.getReal()))
    {
        return (IS_ZERO(left.getImage() - right.getImage()));
    }
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    return (computorv2::eql(right, left));
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    return (computorv2::eql(computorv2::Polynomial(right), left));
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::eql(computorv2::Polynomial(right), left));
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Polynomial' and 'Matrix'.");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    bool result = false;
    const computorv2::Object* e = left.evaluate();
    if (IS_COMPLEX(e))
    {
        result = computorv2::eql(*AS_COMPLEX(e), right);
    }
    delete (e);
    return (result);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (left.isnull() && right.isnull());
    }
    if (left.isunity() || right.isunity())
    {
        return (left.isunity() && right.isunity());
    }
    if (left.getExponent()->isnull() && right.getExponent()->isnull())
    {
        if (computorv2::eql(left.getCoefficient(), right.getCoefficient()))
        {
            if (computorv2::eql(left.getFreeTerm(), right.getFreeTerm()))
                return (true);
        }
        if (computorv2::eql(left.getCoefficient(), right.getFreeTerm()))
        {
            if (computorv2::eql(left.getFreeTerm(), right.getCoefficient()))
                return (true);
        }
        return (false);
    }
    if (!computorv2::eql(left.getFreeTerm(), right.getFreeTerm()))
        return (false);
    if (left.getExponent()->isunity() && right.getExponent()->isunity())
    {
        if (computorv2::eql(left.getCoefficient(), right.getCoefficient()))
        {
            if (computorv2::eql(left.getBase(), right.getBase()))
                return (true);
        }
        if (computorv2::eql(left.getCoefficient(), right.getBase()))
        {
            if (computorv2::eql(left.getBase(), right.getCoefficient()))
                return (true);
        }
        return (false);
    }
    if (!computorv2::eql(left.getBase(), right.getBase()))
        return (false);
    else if (!computorv2::eql(left.getExponent(), right.getExponent()))
        return (false);
    else if (!computorv2::eql(left.getCoefficient(), right.getCoefficient()))
        return (false);
    return (true);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    return (computorv2::eql(left, computorv2::Polynomial(right)));
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::eql(left, computorv2::Polynomial(right)));
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    return (computorv2::eql(computorv2::Polynomial(left), right));
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    return (computorv2::eql(computorv2::Polynomial(left), right));
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    return (computorv2::eql(computorv2::Polynomial(left), right));
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    if (left.getName() == right.getName())
    {
        return (computorv2::eql(left.getBody(), right.getBody()));
    }
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::eql(right, left));
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    return (computorv2::eql(computorv2::Polynomial(left), right));
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    return (computorv2::eql(computorv2::Polynomial(left), right));
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    return (computorv2::eql(computorv2::Polynomial(left), right));
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    bool result = false;
    const computorv2::Object* r = right.evaluate();
    if (IS_INDVAR(r))
    {
        result = computorv2::eql(left, *AS_INDVAR(r));
    }
    delete (r);
    return (result);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    return (left.getName() == right.getName());
}

/* ------------------------------ neg ------------------------------ */

computorv2::Object* computorv2::neg(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'neg' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::neg(*AS_MATRIX(left)).copy());
    else if (IS_COMPLEX(left))
        return (computorv2::neg(*AS_COMPLEX(left)).copy());
    else if (IS_POLYNOMIAL(left))
        return (computorv2::neg(*AS_POLYNOMIAL(left)).copy());
    else if (IS_USFUNC(left))
        return (computorv2::neg(*AS_USFUNC(left)).copy());
    else if (IS_INDVAR(left))
        return (computorv2::neg(*AS_INDVAR(left)).copy());
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
    return (computorv2::Complex(0.0 - left.getReal(), 0.0 - left.getImage()));
}

computorv2::Polynomial computorv2::neg(const computorv2::Polynomial& left)
{
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
    const computorv2::Object* a = computorv2::neg(left.getCoefficient());
    const computorv2::Object* b = computorv2::neg(left.getFreeTerm());
    res.setCoefficient(a);
    res.setBase(left.getBase());
    res.setExponent(left.getExponent());
    res.setFreeTerm(b);
    delete (a);
    delete (b);
    return (res);
}

computorv2::Polynomial computorv2::neg(const computorv2::UsualFunction& left)
{
    computorv2::Polynomial res(left);
    res.setCoefficient(-1.0);
    return (res);
}

computorv2::Polynomial computorv2::neg(const computorv2::IndependentVariable& left)
{
    computorv2::Polynomial res(left);
    res.setCoefficient(-1.0);
    return (res);
}

/* ------------------------------ inv ------------------------------ */

computorv2::Object* computorv2::inv(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'inv' not supported for null types.");
    else if (IS_MATRIX(left))
        return (computorv2::inv(*AS_MATRIX(left)).copy());
    else if (IS_COMPLEX(left))
        return (computorv2::inv(*AS_COMPLEX(left)).copy());
    else if (IS_POLYNOMIAL(left))
        return (computorv2::inv(*AS_POLYNOMIAL(left)).copy());
    else if (IS_USFUNC(left))
        return (computorv2::inv(*AS_USFUNC(left)).copy());
    else if (IS_INDVAR(left))
        return (computorv2::inv(*AS_INDVAR(left)).copy());
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
    if (left.isnull())
    {
        throw std::logic_error("Division by zero!");
    }
    const double r = left.getReal(); const double m = left.getImage();
    const double q = r * r + m * m;
    return (computorv2::Complex(r / q, (0.0 - m) / q));
}

computorv2::Polynomial computorv2::inv(const computorv2::Polynomial& left)
{
    if (left.isnull())
    {
        throw std::logic_error("Division by zero!");
    }
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
    res.setBase(AS_OBJECT(&left));
    res.setExponent(-1.0);
    return (res);
}

computorv2::Polynomial computorv2::inv(const computorv2::UsualFunction& left)
{
    if (left.isnull())
    {
        throw std::logic_error("Division by zero!");
    }
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
    res.setBase(AS_OBJECT(&left));
    res.setExponent(-1.0);
    return (res);
}

computorv2::Polynomial computorv2::inv(const computorv2::IndependentVariable& left)
{
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
    res.setBase(AS_OBJECT(&left));
    res.setExponent(-1.0);
    return (res);
}

/* ----------------------------------------------------- mul ----------------------------------------------------- */

computorv2::Object* computorv2::mul(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'mul' not supported between null types.");
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_USFUNC(right)).copy());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_INDVAR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_USFUNC(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_INDVAR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).copy());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_USFUNC(left), *AS_MATRIX(right)).copy());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_USFUNC(left), *AS_COMPLEX(right)).copy());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::mul(*AS_USFUNC(left), *AS_USFUNC(right)).copy());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::mul(*AS_USFUNC(left), *AS_INDVAR(right)).copy());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_INDVAR(left), *AS_MATRIX(right)).copy());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_INDVAR(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::mul(*AS_INDVAR(left), *AS_USFUNC(right)).copy());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::mul(*AS_INDVAR(left), *AS_INDVAR(right)).copy());
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
    computorv2::Polynomial tmp(computorv2::IndependentVariable::null());
    tmp.setCoefficient(0.0);
    tmp.setExponent(0.0);
    tmp.setFreeTerm(AS_OBJECT(&left));
    return (computorv2::mul(tmp, right));
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    return (computorv2::mul(left, computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::mul(left, computorv2::Polynomial(right)));
}

computorv2::Matrix computorv2::mul(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    return (computorv2::mul(right, left));
}

computorv2::Complex computorv2::mul(const computorv2::Complex& left, const computorv2::Complex& right)
{
    computorv2::Complex res;
    res.setReal((left.getReal()  * right.getReal() ) - (left.getImage() * right.getImage()));
    res.setImage((left.getReal() * right.getImage()) + (left.getImage() * right.getReal() ));
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    return (computorv2::mul(right, left));
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    return (computorv2::mul(left, computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::mul(left, computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    computorv2::Polynomial tmp(computorv2::IndependentVariable::null());
    tmp.setCoefficient(0.0);
    tmp.setExponent(0.0);
    tmp.setFreeTerm(AS_OBJECT(&right));
    return (computorv2::mul(left, tmp));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    computorv2::Polynomial tmp(computorv2::IndependentVariable::null());
    tmp.setCoefficient(0.0);
    tmp.setExponent(0.0);
    tmp.setFreeTerm(AS_OBJECT(&right));
    return (computorv2::mul(left, tmp));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }

    computorv2::Polynomial poly3(right);
    if (left.getFreeTerm()->isnull())
    {
        poly3.setCoefficient(0.0);
        poly3.setFreeTerm(0.0);
    }
    else
    {
        const computorv2::Object* coefficient = computorv2::mul(left.getFreeTerm(), right.getCoefficient());
        const computorv2::Object* freeterm    = computorv2::mul(left.getFreeTerm(), right.getFreeTerm());
        poly3.setCoefficient(coefficient);
        poly3.setFreeTerm(freeterm);
        delete (coefficient);
        delete (freeterm);
    }
    if (left.getCoefficient()->isnull() || left.getBase()->isnull())
    {
        return (poly3);        
    }

    computorv2::Polynomial poly1(computorv2::IndependentVariable::null());
    poly1.setBase(right.getBase());
    poly1.setFreeTerm(0.0);
    const computorv2::Object* t1 = computorv2::mul(left.getCoefficient(), right.getCoefficient());
    if (computorv2::eql(left.getBase(), right.getBase()))
    {
        const computorv2::Object* t2 = computorv2::add(left.getExponent(), right.getExponent());
        poly1.setCoefficient(t1);
        poly1.setExponent(t2);
        delete (t2);
    }
    else
    {
        if (left.getExponent()->isnull())
        {
            poly1.setCoefficient(t1);
        }
        else
        {
            computorv2::Polynomial xpow_n(computorv2::IndependentVariable::null());
            xpow_n.setCoefficient(1.0);
            xpow_n.setBase(left.getBase());
            xpow_n.setExponent(left.getExponent());
            xpow_n.setFreeTerm(0.0);

            const computorv2::Object* t2 = computorv2::mul(t1, AS_OBJECT(&xpow_n));
            poly1.setCoefficient(t2);
            delete (t2);            
        }
        poly1.setExponent(right.getExponent());
    }
    delete (t1);

    const computorv2::Object* r1 = computorv2::mul(left.getCoefficient(), right.getFreeTerm());
    computorv2::Polynomial poly2(computorv2::IndependentVariable::null());
    poly2.setCoefficient(r1);
    poly2.setBase(left.getBase());
    poly2.setExponent(left.getExponent());
    poly2.setFreeTerm(0.0);
    delete (r1);

    computorv2::Polynomial res = computorv2::add(computorv2::add(poly1, poly2), poly3);
    if (computorv2::eql(res.getCoefficient(), res.getBase()))
    {
        const computorv2::Complex one(1.0, 0.0);
        const computorv2::Object* n = computorv2::add(res.getExponent(), AS_OBJECT(&one));
        res.setCoefficient(1.0);
        res.setExponent(n);
        delete (n);
    }
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    return (computorv2::mul(left, computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::mul(left, computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    return (computorv2::mul(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    return (computorv2::mul(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    return (computorv2::mul(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    return (computorv2::mul(computorv2::Polynomial(left), computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::mul(computorv2::Polynomial(left), computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    return (computorv2::mul(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    return (computorv2::mul(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    return (computorv2::mul(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    return (computorv2::mul(computorv2::Polynomial(left), computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::mul(computorv2::Polynomial(left), computorv2::Polynomial(right)));
}

/* ----------------------------------------------------- div ----------------------------------------------------- */

computorv2::Object* computorv2::div(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'div' not supported between null types.");
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_USFUNC(right)).copy());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_INDVAR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_USFUNC(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_INDVAR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).copy());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_USFUNC(left), *AS_MATRIX(right)).copy());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_USFUNC(left), *AS_COMPLEX(right)).copy());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::div(*AS_USFUNC(left), *AS_USFUNC(right)).copy());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::div(*AS_USFUNC(left), *AS_INDVAR(right)).copy());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_INDVAR(left), *AS_MATRIX(right)).copy());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_INDVAR(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::div(*AS_INDVAR(left), *AS_USFUNC(right)).copy());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::div(*AS_INDVAR(left), *AS_INDVAR(right)).copy());
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
        return (computorv2::add(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_USFUNC(right)).copy());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_INDVAR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_USFUNC(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_INDVAR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).copy());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_USFUNC(left), *AS_MATRIX(right)).copy());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_USFUNC(left), *AS_COMPLEX(right)).copy());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::add(*AS_USFUNC(left), *AS_USFUNC(right)).copy());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::add(*AS_USFUNC(left), *AS_INDVAR(right)).copy());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_INDVAR(left), *AS_MATRIX(right)).copy());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_INDVAR(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::add(*AS_INDVAR(left), *AS_USFUNC(right)).copy());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::add(*AS_INDVAR(left), *AS_INDVAR(right)).copy());
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
    return (computorv2::add(right, left));
}

computorv2::Polynomial computorv2::add(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    return (computorv2::add(computorv2::Polynomial(right), left));
}

computorv2::Polynomial computorv2::add(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::add(computorv2::Polynomial(right), left));
}

computorv2::Matrix computorv2::add(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Complex' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Complex computorv2::add(const computorv2::Complex& left, const computorv2::Complex& right)
{
    return (computorv2::Complex(left.getReal() + right.getReal(), left.getImage() + right.getImage()));
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    return (computorv2::add(right, left));
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    return (computorv2::add(computorv2::Polynomial(right), left));
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::add(computorv2::Polynomial(right), left));
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    if (left.isnull())
    {
        computorv2::Polynomial res = computorv2::Polynomial::null();
        res.setFreeTerm(AS_OBJECT(&right));
        return (res);
    }
    computorv2::Polynomial res(left);
    const computorv2::Object* freeterm = computorv2::add(left.getFreeTerm(), AS_OBJECT(&right));
    res.setFreeTerm(freeterm);
    delete (freeterm);
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    if (left.isnull())
        return (right);
    if (right.isnull())
        return (left);
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
    if (left.getCoefficient()->isnull() || left.getBase()->isnull())
    {
        computorv2::Polynomial res(right);
        const computorv2::Object* freeterm = computorv2::add(left.getFreeTerm(), right.getFreeTerm());
        res.setFreeTerm(freeterm);
        delete (freeterm);
        return (res);
    }
    if (right.getCoefficient()->isnull() || right.getBase()->isnull())
    {
        computorv2::Polynomial res(left);
        const computorv2::Object* freeterm = computorv2::add(left.getFreeTerm(), right.getFreeTerm());
        res.setFreeTerm(freeterm);
        delete (freeterm);
        return (res);
    }
    if (left.getExponent()->isnull())
    {
        computorv2::Polynomial res(right);
        const computorv2::Object* a = computorv2::add(left.getCoefficient(), left.getFreeTerm());
        const computorv2::Object* freeterm = computorv2::add(a, right.getFreeTerm());
        res.setFreeTerm(freeterm);
        delete (a);
        delete (freeterm);
        return (res);
    }
    if (right.getExponent()->isnull())
    {
        computorv2::Polynomial res(left);
        const computorv2::Object* a = computorv2::add(right.getCoefficient(), right.getFreeTerm());
        const computorv2::Object* freeterm = computorv2::add(left.getFreeTerm(), a);
        res.setFreeTerm(freeterm);
        delete (a);
        delete (freeterm);
        return (res);
    }
    if ((computorv2::eql(left.getBase(), right.getBase())) && (computorv2::eql(left.getExponent(), right.getExponent())))
    {
        const computorv2::Object* coefficient = computorv2::add(left.getCoefficient(), right.getCoefficient());
        const computorv2::Object* freeterm    = computorv2::add(left.getFreeTerm(), right.getFreeTerm());
        computorv2::Polynomial res(computorv2::IndependentVariable::null());
        res.setCoefficient(coefficient);
        res.setBase(left.getBase());
        res.setExponent(left.getExponent());
        res.setFreeTerm(freeterm);
        delete (coefficient);
        delete (freeterm);
        return (res);
    }
    computorv2::Polynomial res(left);
    const computorv2::Object* freeterm = computorv2::add(left.getFreeTerm(), AS_OBJECT(&right));
    res.setFreeTerm(freeterm);
    delete (freeterm);
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    return (computorv2::add(left, computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::add(left, computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    return (computorv2::add(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    return (computorv2::add(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    return (computorv2::add(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    return (computorv2::add(computorv2::Polynomial(left), computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::add(computorv2::Polynomial(left), computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    return (computorv2::add(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    return (computorv2::add(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    return (computorv2::add(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    return (computorv2::add(computorv2::Polynomial(left), computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::add(computorv2::Polynomial(left), computorv2::Polynomial(right)));
}

/* ----------------------------------------------------- sub ----------------------------------------------------- */

computorv2::Object* computorv2::sub(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'sub' not supported between null types.");
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_USFUNC(right)).copy());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_INDVAR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_USFUNC(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_INDVAR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).copy());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_USFUNC(left), *AS_MATRIX(right)).copy());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_USFUNC(left), *AS_COMPLEX(right)).copy());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::sub(*AS_USFUNC(left), *AS_USFUNC(right)).copy());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::sub(*AS_USFUNC(left), *AS_INDVAR(right)).copy());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_INDVAR(left), *AS_MATRIX(right)).copy());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_INDVAR(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::sub(*AS_INDVAR(left), *AS_USFUNC(right)).copy());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::sub(*AS_INDVAR(left), *AS_INDVAR(right)).copy());
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
        return (computorv2::mod(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_USFUNC(right)).copy());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_INDVAR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_USFUNC(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_INDVAR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).copy());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_USFUNC(left), *AS_MATRIX(right)).copy());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_USFUNC(left), *AS_COMPLEX(right)).copy());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::mod(*AS_USFUNC(left), *AS_USFUNC(right)).copy());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::mod(*AS_USFUNC(left), *AS_INDVAR(right)).copy());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_INDVAR(left), *AS_MATRIX(right)).copy());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_INDVAR(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::mod(*AS_INDVAR(left), *AS_USFUNC(right)).copy());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::mod(*AS_INDVAR(left), *AS_INDVAR(right)).copy());
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
        return (computorv2::pow(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USFUNC(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_USFUNC(right)).copy());
    else if (IS_MATRIX(left) && IS_INDVAR(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_INDVAR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USFUNC(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_USFUNC(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDVAR(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_INDVAR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USFUNC(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_USFUNC(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDVAR(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_INDVAR(right)).copy());
    else if (IS_USFUNC(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_USFUNC(left), *AS_MATRIX(right)).copy());
    else if (IS_USFUNC(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_USFUNC(left), *AS_COMPLEX(right)).copy());
    else if (IS_USFUNC(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_USFUNC(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USFUNC(left) && IS_USFUNC(right))
        return (computorv2::pow(*AS_USFUNC(left), *AS_USFUNC(right)).copy());
    else if (IS_USFUNC(left) && IS_INDVAR(right))
        return (computorv2::pow(*AS_USFUNC(left), *AS_INDVAR(right)).copy());
    else if (IS_INDVAR(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_INDVAR(left), *AS_MATRIX(right)).copy());
    else if (IS_INDVAR(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_INDVAR(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDVAR(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_INDVAR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDVAR(left) && IS_USFUNC(right))
        return (computorv2::pow(*AS_INDVAR(left), *AS_USFUNC(right)).copy());
    else if (IS_INDVAR(left) && IS_INDVAR(right))
        return (computorv2::pow(*AS_INDVAR(left), *AS_INDVAR(right)).copy());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    return (0);
}

computorv2::Polynomial computorv2::drv(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left;  (void)right;
    throw std::logic_error("Operation 'drv' not supported for type: 'Matrix'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::drv(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void)right;
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::drv(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    computorv2::Polynomial res = computorv2::drv(left.getFreeTerm(), right);
    if (left.getCoefficient()->isnull() || left.getBase()->isnull())
    {
        return (res);
    }
    const computorv2::Polynomial da = computorv2::drv(left.getCoefficient(), right);
    if (!da.isnull())
    {
        computorv2::Polynomial xpow_n(computorv2::IndependentVariable::null());
        xpow_n.setCoefficient(1.0);
        xpow_n.setBase(left.getBase());
        xpow_n.setExponent(left.getExponent());
        xpow_n.setFreeTerm(0.0);
        res = computorv2::add(res, computorv2::mul(da, xpow_n));
    }
    computorv2::Polynomial axn(computorv2::IndependentVariable::null());
    axn.setCoefficient(left.getCoefficient());
    axn.setBase(left.getBase());
    axn.setExponent(left.getExponent());
    axn.setFreeTerm(0.0);
    const computorv2::Polynomial dn = computorv2::drv(left.getExponent(), right);
    if (!dn.isnull())
    {
        res = computorv2::add(res, computorv2::mul(computorv2::mul(dn, axn), computorv2::UsualFunction("ln", left.getBase())));
    }
    const computorv2::Polynomial dx = computorv2::drv(left.getBase(), right);
    if (!dx.isnull())
    {
        computorv2::Polynomial nx_1(computorv2::IndependentVariable::null());
        nx_1.setCoefficient(left.getExponent());
        nx_1.setBase(left.getBase());
        nx_1.setExponent(-1.0);
        nx_1.setFreeTerm(0.0);
        res = computorv2::add(res, computorv2::mul(computorv2::mul(dx, axn), nx_1));
    }
    return (res);
}

computorv2::Polynomial computorv2::drv(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    const computorv2::Object* f = left.getBody();
    if (left.getName() == "ln")
    {
        const computorv2::Polynomial df = computorv2::drv(left.getBody(), right);
        const computorv2::Object* df_f  = computorv2::div(AS_OBJECT(&df), left.getBody());
        computorv2::Polynomial res(*AS_POLYNOMIAL(df_f));
        delete (df_f);
        return (res);
    }
    else if (left.getName() == "exp")
    {
        return (computorv2::mul(computorv2::drv(f, right), left));
    }
    else if (left.getName() == "sin")
    {
        return (computorv2::mul(computorv2::drv(f, right), computorv2::UsualFunction("cos", f)));
    }
    else if (left.getName() == "cos")
    {
        return (computorv2::neg(computorv2::mul(computorv2::drv(f, right), computorv2::UsualFunction("sin", f))));
    }
    else if (left.getName() == "tan")
    {
        const computorv2::Polynomial t = computorv2::div(computorv2::UsualFunction("sin", f), computorv2::UsualFunction("cos", f));
        return (computorv2::drv(t, right));
    }
    else if (left.getName() == "arcsin")
    {
        computorv2::Polynomial tmp(computorv2::IndependentVariable::null());
        tmp.setCoefficient(-1.0);
        tmp.setBase(f);
        tmp.setExponent(2.0);
        tmp.setFreeTerm(1.0);
        computorv2::Polynomial df(computorv2::IndependentVariable::null());
        df.setCoefficient(1.0);
        df.setBase(AS_OBJECT(&tmp));
        df.setExponent(0.5);
        df.setFreeTerm(0.0);
        return (computorv2::div(computorv2::drv(f, right), df));
    }
    else if (left.getName() == "arccos")
    {
        computorv2::Polynomial tmp(computorv2::IndependentVariable::null());
        tmp.setCoefficient(-1.0);
        tmp.setBase(f);
        tmp.setExponent(2.0);
        tmp.setFreeTerm(1.0);
        computorv2::Polynomial df(computorv2::IndependentVariable::null());
        df.setCoefficient(-1.0);
        df.setBase(AS_OBJECT(&tmp));
        df.setExponent(0.5);
        df.setFreeTerm(0.0);
        return (computorv2::div(computorv2::drv(f, right), df));
    }
    else if (left.getName() == "arctan")
    {
        computorv2::Polynomial tmp(computorv2::IndependentVariable::null());
        tmp.setCoefficient(1.0);
        tmp.setBase(f);
        tmp.setExponent(2.0);
        tmp.setFreeTerm(1.0);
        return (computorv2::div(computorv2::drv(f, right), tmp));
    }
    throw std::logic_error("Operation 'drv' not supported for: '" + left.getName() + "(" + left.getBody()->toString() + ")'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::drv(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    if (computorv2::eql(left, right))
    {
        return (computorv2::Polynomial::unity());
    }
    return (computorv2::Polynomial::null());
}

#endif//!__COMPUTORV2_SOURCES_COMPUTORV2
