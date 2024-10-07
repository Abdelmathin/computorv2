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
    std::string functions[] = {"ln", "sin"};
    for (int i = 0; i < 2; i++)
    {
        if (functions[i] == name)
        {
            return (true);
        }
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

/* ------------------------------ inverse ------------------------------ */

computorv2::Object* computorv2::inverse(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'inverse' not supported for null types.");
    else if (IS_VECTOR(left))
        return (computorv2::inverse(*AS_VECTOR(left)).copy());
    else if (IS_MATRIX(left))
        return (computorv2::inverse(*AS_MATRIX(left)).copy());
    else if (IS_COMPLEX(left))
        return (computorv2::inverse(*AS_COMPLEX(left)).copy());
    else if (IS_POLYNOMIAL(left))
        return (computorv2::inverse(*AS_POLYNOMIAL(left)).copy());
    else if (IS_USFUNC(left))
        return (computorv2::inverse(*AS_USFUNC(left)).copy());
    else if (IS_INDVAR(left))
        return (computorv2::inverse(*AS_INDVAR(left)).copy());
    throw std::logic_error("Operation 'inverse' not supported for type '" + left->getTypeName() + "'.");
    return (0);
}

computorv2::Matrix computorv2::inverse(const computorv2::Vector& left)
{
    if (left.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    throw std::logic_error("Operation 'inverse' not supported for type: 'Vector'");
    return (computorv2::Matrix::null());
}

computorv2::Matrix computorv2::inverse(const computorv2::Matrix& left)
{
    if (left.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    throw std::logic_error("Operation 'inverse' not supported for type: 'Matrix'");
    return (left);
}

computorv2::Complex computorv2::inverse(const computorv2::Complex& left)
{
    if (left.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    const double r = left.getReal(); const double m = left.getImage();
    const double q = r * r + m * m;
    return (computorv2::Complex(r / q, (0.0 - m) / q));
}

computorv2::Polynomial computorv2::inverse(const computorv2::Polynomial& left)
{
    if (left.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.getFreeTerm()->isnull())
    {
        const computorv2::Complex zero(0.0, 0.0);
        computorv2::Polynomial res(left);
        const computorv2::Object* a = computorv2::inverse(left.getCoefficient());
        const computorv2::Object* n = computorv2::sub(AS_OBJECT(&zero), left.getExponent());
        res.setCoefficient(a);
        res.setExponent(n);
        delete (a);
        delete (n);
        return (res);
    }
    const computorv2::Complex minus_one(-1.0, 0.0);
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&minus_one));
    return (res);
}

computorv2::Polynomial computorv2::inverse(const computorv2::UsualFunction& left)
{
    if (left.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    const computorv2::Complex minus_one(-1.0, 0.0);
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&minus_one));
    return (res);
}

computorv2::Polynomial computorv2::inverse(const computorv2::IndependentVariable& left)
{
    if (left.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    const computorv2::Complex minus_one(-1.0, 0.0);
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&minus_one));
    return (res);
}

/* --------------------- isfreeterm --------------------- */

bool computorv2::isfreeterm(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'isfreeterm' not supported for null types.");
    else if (IS_VECTOR(left))
        return (computorv2::isfreeterm(*AS_VECTOR(left)));
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

bool computorv2::isfreeterm(const computorv2::Vector& left)
{
    (void)left;
    throw std::logic_error("Operation 'isfreeterm' not supported for type: 'Vector'");
    return (false);
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
    if (left.getFreeTerm()->isnull())
    {
        return (computorv2::isfreeterm(left.getCoefficient()));
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
    (void) left;
    return (true);
}

/* -------------------------------------------- eql -------------------------------------------- */

bool computorv2::eql(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'eql' not supported between null types.");
    else if (IS_VECTOR(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_VECTOR(right)));
    else if (IS_VECTOR(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_MATRIX(right)));
    else if (IS_VECTOR(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_COMPLEX(right)));
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_POLYNOMIAL(right)));
    else if (IS_VECTOR(left) && IS_USFUNC(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_USFUNC(right)));
    else if (IS_VECTOR(left) && IS_INDVAR(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_INDVAR(right)));
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_VECTOR(right)));
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
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_VECTOR(right)));
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
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_VECTOR(right)));
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
    else if (IS_USFUNC(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_USFUNC(left), *AS_VECTOR(right)));
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
    else if (IS_INDVAR(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_INDVAR(left), *AS_VECTOR(right)));
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

bool computorv2::eql(const computorv2::Vector& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Vector' and 'Vector'.");
    return (false);
}

bool computorv2::eql(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Vector' and 'Matrix'.");
    return (false);
}

bool computorv2::eql(const computorv2::Vector& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Vector' and 'Complex'.");
    return (false);
}

bool computorv2::eql(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Vector' and 'Polynomial'.");
    return (false);
}

bool computorv2::eql(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Vector' and 'UsualFunction'.");
    return (false);
}

bool computorv2::eql(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Vector' and 'IndependentVariable'.");
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Matrix' and 'Vector'.");
    return (false);
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

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Complex' and 'Vector'.");
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
    if (IS_ZERO(left.getReal() - right.getReal()))
    {
        return (IS_ZERO(left.getImage() - right.getImage()));
    }
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

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Polynomial' and 'Vector'.");
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
    // use evaluate !
    if (!computorv2::eql(left.getBase(), right.getBase()))
        return (false);
    if (!computorv2::eql(left.getExponent(), right.getExponent()))
        return (false);
    if (!computorv2::eql(left.getCoefficient(), right.getCoefficient()))
        return (false);
    if (!computorv2::eql(left.getFreeTerm(), right.getFreeTerm()))
        return (false);
    return (true);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    if (!left.getFreeTerm()->isnull())
        return (false);
    if (!left.getCoefficient()->isunity())
        return (false);
    if (!left.getExponent()->isunity())
        return (false);
    return (computorv2::eql(left.getBase(), AS_OBJECT(&right)));
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::eql(right, left));
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'UsualFunction' and 'Vector'.");
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
    if (!right.getCoefficient()->isunity())
        return (false);
    if (!right.getExponent()->isunity())
        return (false);
    if (!right.getFreeTerm()->isnull())
        return (false);
    return (computorv2::eql(AS_OBJECT(&left), right.getBase()));
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
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'IndependentVariable' and 'Vector'.");
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
    if (!right.getCoefficient()->isunity())
        return (false);
    if (!right.getExponent()->isunity())
        return (false);
    if (!right.getFreeTerm()->isnull())
        return (false);
    return (computorv2::eql(AS_OBJECT(&left), right.getBase()));
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    return (left.getName() == right.getName());
}

/* ----------------------------------------------------- derivative ----------------------------------------------------- */

computorv2::Polynomial computorv2::derivative(const computorv2::Object* left, const computorv2::IndependentVariable& right)
{
    if (!left)
        throw std::logic_error("Operation 'derivative' not supported for null types.");
    else if (IS_VECTOR(left))
        return (computorv2::derivative(*AS_VECTOR(left), right));
    else if (IS_MATRIX(left))
        return (computorv2::derivative(*AS_MATRIX(left), right));
    else if (IS_COMPLEX(left))
        return (computorv2::derivative(*AS_COMPLEX(left), right));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::derivative(*AS_POLYNOMIAL(left), right));
    else if (IS_USFUNC(left))
        return (computorv2::derivative(*AS_USFUNC(left), right));
    else if (IS_INDVAR(left))
        return (computorv2::derivative(*AS_INDVAR(left), right));
    throw std::logic_error("Operation 'derivative' not supported for type '" + left->getTypeName() + "'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::derivative(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'derivative' not supported for type: 'Vector'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::derivative(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'derivative' not supported for type: 'Matrix'");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::derivative(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::derivative(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    throw std::logic_error("Operation 'derivative' not supported for type: 'Polynomial'");
    return (left);
}

computorv2::Polynomial computorv2::derivative(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    if (left.getName() == "ln")
    {
        const computorv2::Polynomial dx = computorv2::derivative(AS_OBJECT(left.getBody()), right);
        return (computorv2::div(dx, right));
    }
    throw std::runtime_error("Derivative of '" + left.getName() + "(" + left.getBody()->toString() + ")' not implemented.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::derivative(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    computorv2::Polynomial res("x");
    if (computorv2::eql(left, right))
    {
        res.setCoefficient(1.0);
    }
    else
    {
        res.setCoefficient(0.0);
    }
    res.setBase(AS_OBJECT(&left));
    res.setExponent(0.0);
    res.setFreeTerm(0.0);
    return (res);
}

/* ----------------------------------------------------- add ----------------------------------------------------- */

computorv2::Object* computorv2::add(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'add' not supported between null types.");
    else if (IS_VECTOR(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_VECTOR(right)).copy());
    else if (IS_VECTOR(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_MATRIX(right)).copy());
    else if (IS_VECTOR(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_COMPLEX(right)).copy());
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_VECTOR(left) && IS_USFUNC(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_USFUNC(right)).copy());
    else if (IS_VECTOR(left) && IS_INDVAR(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_INDVAR(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
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
    else if (IS_USFUNC(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_USFUNC(left), *AS_VECTOR(right)).copy());
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
    else if (IS_INDVAR(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_INDVAR(left), *AS_VECTOR(right)).copy());
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

computorv2::Vector computorv2::add(const computorv2::Vector& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Vector' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::add(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Vector' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Vector computorv2::add(const computorv2::Vector& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Vector' and 'Complex'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Polynomial computorv2::add(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Vector' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Vector' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::add(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Vector' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Matrix computorv2::add(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'Vector'.");
    return (computorv2::Matrix::null());
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

computorv2::Vector computorv2::add(const computorv2::Complex& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Complex' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
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
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&right));
    res.setFreeTerm(AS_OBJECT(&left));
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&right));
    res.setFreeTerm(AS_OBJECT(&left));
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'Vector'.");
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
    const bool left_null  = left.isnull();
    const bool right_null = right.isnull();
    if (left_null && right_null)
    {
        return (computorv2::Polynomial::null());
    }
    if (left_null)
    {
        return (computorv2::add(computorv2::Complex(0.0, 0.0), right));
    }
    if (right_null)
    {
        return (computorv2::add(left, computorv2::Complex(0.0, 0.0)));
    }
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
        const computorv2::Object* coefficient = computorv2::add(left.getCoefficient(), right.getCoefficient());
        const computorv2::Object* freeterm    = computorv2::add(left.getFreeTerm(), right.getFreeTerm());
        computorv2::Polynomial res("x");
        res.setCoefficient(coefficient);
        res.setBase(left.getBase());
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

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    computorv2::Polynomial res(left);
    if ((left.getExponent()->isunity()) && (computorv2::eql(left.getBase(), AS_OBJECT(&right))))
    {
        const computorv2::Complex one(1.0, 0.0);
        const computorv2::Object* a = computorv2::add(res.getCoefficient(), AS_OBJECT(&one));
        res.setCoefficient(a);
        delete (a);
        return (res);
    }
    const computorv2::Object* b = computorv2::add(res.getFreeTerm(), AS_OBJECT(&right));
    res.setFreeTerm(b);
    delete (b);
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    computorv2::Polynomial res(left);
    if ((left.getExponent()->isunity()) && (computorv2::eql(left.getBase(), AS_OBJECT(&right))))
    {
        const computorv2::Complex one(1.0, 0.0);
        const computorv2::Object* a = computorv2::add(res.getCoefficient(), AS_OBJECT(&one));
        res.setCoefficient(a);
        delete (a);
        return (res);
    }
    const computorv2::Object* b = computorv2::add(res.getFreeTerm(), AS_OBJECT(&right));
    res.setFreeTerm(b);
    delete (b);
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'Vector'.");
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
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setFreeTerm(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    return (computorv2::add(right, left));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    if (computorv2::eql(left, right))
    {
        res.setCoefficient(2.0);
        return (res);
    }
    res.setFreeTerm(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&right));
    res.setFreeTerm(AS_OBJECT(&left));
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'Vector'.");
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
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setFreeTerm(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    return (computorv2::add(right, left));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setFreeTerm(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    if (computorv2::eql(left, right))
    {
        res.setCoefficient(2.0);
        return (res);
    }
    res.setFreeTerm(AS_OBJECT(&right));
    return (res);
}

/* ----------------------------------------------------- sub ----------------------------------------------------- */

computorv2::Object* computorv2::sub(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'sub' not supported between null types.");
    else if (IS_VECTOR(left) && IS_VECTOR(right))
        return (computorv2::sub(*AS_VECTOR(left), *AS_VECTOR(right)).copy());
    else if (IS_VECTOR(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_VECTOR(left), *AS_MATRIX(right)).copy());
    else if (IS_VECTOR(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_VECTOR(left), *AS_COMPLEX(right)).copy());
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_VECTOR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_VECTOR(left) && IS_USFUNC(right))
        return (computorv2::sub(*AS_VECTOR(left), *AS_USFUNC(right)).copy());
    else if (IS_VECTOR(left) && IS_INDVAR(right))
        return (computorv2::sub(*AS_VECTOR(left), *AS_INDVAR(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
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
    else if (IS_USFUNC(left) && IS_VECTOR(right))
        return (computorv2::sub(*AS_USFUNC(left), *AS_VECTOR(right)).copy());
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
    else if (IS_INDVAR(left) && IS_VECTOR(right))
        return (computorv2::sub(*AS_INDVAR(left), *AS_VECTOR(right)).copy());
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

computorv2::Vector computorv2::sub(const computorv2::Vector& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Vector' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::sub(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Vector' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Vector computorv2::sub(const computorv2::Vector& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Vector' and 'Complex'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Polynomial computorv2::sub(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Vector' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::sub(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Vector' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::sub(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Vector' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Matrix computorv2::sub(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'Vector'.");
    return (computorv2::Matrix::null());
}

computorv2::Matrix computorv2::sub(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Matrix computorv2::sub(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix::null());
}

computorv2::Polynomial computorv2::sub(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::sub(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::sub(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Vector computorv2::sub(const computorv2::Complex& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Complex' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::sub(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Complex' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Complex computorv2::sub(const computorv2::Complex& left, const computorv2::Complex& right)
{
    computorv2::Complex res;
    res.setReal(left.getReal()   - right.getReal());
    res.setImage(left.getImage() - right.getImage());
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    const computorv2::Complex minus_one = computorv2::Complex(-1.0, 0.0);
    computorv2::Polynomial res(right);
    const computorv2::Object* a = computorv2::mul(res.getCoefficient(), AS_OBJECT(&minus_one));
    const computorv2::Object* b = computorv2::add(res.getFreeTerm(), AS_OBJECT(&left));
    res.setCoefficient(a);
    res.setFreeTerm(b);
    delete (a);
    delete (b);
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    computorv2::Polynomial res("x");
    res.setCoefficient(-1.0);
    res.setBase(AS_OBJECT(&right));
    res.setFreeTerm(AS_OBJECT(&left));
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    computorv2::Polynomial res("x");
    res.setCoefficient(-1.0);
    res.setBase(AS_OBJECT(&right));
    res.setFreeTerm(AS_OBJECT(&left));
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Polynomial' and 'Vector'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    computorv2::Polynomial res(left);
    const computorv2::Object* b = computorv2::sub(left.getFreeTerm(), AS_OBJECT(&right));
    res.setFreeTerm(b);
    delete (b);
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    computorv2::Polynomial res(left);
    if (computorv2::eql(left.getBase(), right.getBase()) && computorv2::eql(left.getExponent(), right.getExponent()))
    {
        const computorv2::Object* a = computorv2::sub(left.getCoefficient(), right.getCoefficient());
        const computorv2::Object* b = computorv2::sub(left.getFreeTerm()   , right.getFreeTerm());
        res.setCoefficient(a);
        res.setFreeTerm(b);
        delete (a);
        delete (b);
        return (res);
    }
    const computorv2::Object* b = computorv2::sub(left.getFreeTerm(), AS_OBJECT(&right));
    res.setFreeTerm(b);
    delete (b);
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    computorv2::Polynomial res(left);
    if ((left.getExponent()->isunity()) && (computorv2::eql(left.getBase(), AS_OBJECT(&right))))
    {
        const computorv2::Complex one(1.0, 0.0);
        const computorv2::Object* a = computorv2::sub(res.getCoefficient(), AS_OBJECT(&one));
        res.setCoefficient(a);
        delete (a);
        return (res);
    }
    const computorv2::Object* b = computorv2::sub(res.getFreeTerm(), AS_OBJECT(&right));
    res.setFreeTerm(b);
    delete (b);
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    computorv2::Polynomial res(left);
    if ((left.getExponent()->isunity()) && (computorv2::eql(left.getBase(), AS_OBJECT(&right))))
    {
        const computorv2::Complex one(1.0, 0.0);
        const computorv2::Object* a = computorv2::sub(res.getCoefficient(), AS_OBJECT(&one));
        res.setCoefficient(a);
        delete (a);
        return (res);
    }
    const computorv2::Object* b = computorv2::sub(res.getFreeTerm(), AS_OBJECT(&right));
    res.setFreeTerm(b);
    delete (b);
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'UsualFunction' and 'Vector'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'UsualFunction' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    const computorv2::Complex z = computorv2::sub(computorv2::Complex(0.0, 0.0), right);
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setFreeTerm(AS_OBJECT(&z));
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    computorv2::Polynomial res(right);
    const computorv2::Complex zero(0.0, 0.0);
    if (right.getExponent()->isunity() && computorv2::eql(AS_OBJECT(&left), right.getBase()))
    {
        const computorv2::Complex one(1.0, 0.0);
        const computorv2::Object* a = computorv2::sub(AS_OBJECT(&one), right.getCoefficient());
        const computorv2::Object* b = computorv2::sub(AS_OBJECT(&zero), right.getFreeTerm());
        res.setCoefficient(a);
        res.setFreeTerm(b);
        delete (a);
        delete (b);
        return (res);
    }
    const computorv2::Object* a = computorv2::sub(AS_OBJECT(&zero), right.getCoefficient());
    const computorv2::Object* b = computorv2::sub(AS_OBJECT(&left), right.getFreeTerm());
    res.setCoefficient(a);
    res.setFreeTerm(b);
    delete (a);
    delete (b);
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    if (computorv2::eql(left, right))
    {
        return (computorv2::Polynomial::null());
    }
    const computorv2::Complex zero(0.0, 0.0);
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    const computorv2::Polynomial r1 = computorv2::sub(zero, right);
    res.setFreeTerm(AS_OBJECT(&r1));
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    computorv2::Polynomial res("x");
    res.setCoefficient(-1.0);
    res.setBase(AS_OBJECT(&right));
    res.setFreeTerm(AS_OBJECT(&left));
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'IndependentVariable' and 'Vector'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    const computorv2::Complex z = computorv2::sub(computorv2::Complex(0.0, 0.0), right);
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setFreeTerm(AS_OBJECT(&z));
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    return (computorv2::sub(computorv2::Polynomial(left), right));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    const computorv2::Polynomial p = computorv2::sub(computorv2::Complex(0.0, 0.0), right);
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setFreeTerm(AS_OBJECT(&p));
    return (res);
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    if (computorv2::eql(left, right))
    {
        return (computorv2::Polynomial::null());
    }
    const computorv2::Complex zero(0.0, 0.0);
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    const computorv2::Polynomial r1 = computorv2::sub(zero, right);
    res.setFreeTerm(AS_OBJECT(&r1));
    return (res);
}

/* ----------------------------------------------------- mul ----------------------------------------------------- */

computorv2::Object* computorv2::mul(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'mul' not supported between null types.");
    else if (IS_VECTOR(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_VECTOR(right)).copy());
    else if (IS_VECTOR(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_MATRIX(right)).copy());
    else if (IS_VECTOR(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_COMPLEX(right)).copy());
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_VECTOR(left) && IS_USFUNC(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_USFUNC(right)).copy());
    else if (IS_VECTOR(left) && IS_INDVAR(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_INDVAR(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
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
    else if (IS_USFUNC(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_USFUNC(left), *AS_VECTOR(right)).copy());
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
    else if (IS_INDVAR(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_INDVAR(left), *AS_VECTOR(right)).copy());
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

computorv2::Vector computorv2::mul(const computorv2::Vector& left, const computorv2::Vector& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Vector::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::mul(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Matrix::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Vector computorv2::mul(const computorv2::Vector& left, const computorv2::Complex& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Vector::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'Complex'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Polynomial computorv2::mul(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Matrix computorv2::mul(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Matrix::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'Vector'.");
    return (computorv2::Matrix::null());
}

computorv2::Matrix computorv2::mul(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Matrix::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Matrix computorv2::mul(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Matrix::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Vector computorv2::mul(const computorv2::Complex& left, const computorv2::Vector& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Vector::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::mul(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Matrix::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'Matrix'.");
    return (computorv2::Matrix::null());
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
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(right, left));
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res(right);
    res.setCoefficient(AS_OBJECT(&left));
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res(right);
    res.setCoefficient(AS_OBJECT(&left));
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'Vector'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    if (right.isnull() || left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res(left);
    const computorv2::Object* coefficient = computorv2::mul(left.getCoefficient(), AS_OBJECT(&right));
    const computorv2::Object* freeterm    = computorv2::mul(left.getFreeTerm(),    AS_OBJECT(&right));
    res.setCoefficient(coefficient);
    res.setFreeTerm(freeterm);
    delete (coefficient);
    delete (freeterm);
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    // if (computorv2::eql(left.getBase(), right.getBase()))
    // {
    //     computorv2::Polynomial first(left.getBase());
    //     computorv2::Polynomial second(left.getBase());
    //     computorv2::Polynomial third(left.getBase());

    //     computorv2::Object* coefficient = NULL;
    //     computorv2::Object* exponent    = NULL;

    //     coefficient = computorv2::mul(left.getCoefficient(), right.getCoefficient());
    //     first.setCoefficient(coefficient);
    //     delete (coefficient);

    //     coefficient = computorv2::mul(left.getCoefficient(), right.getFreeTerm());
    //     second.setCoefficient(coefficient);
    //     delete (coefficient);

    //     coefficient = computorv2::mul(left.getFreeTerm(), right.getCoefficient());
    //     third.setCoefficient(coefficient);
    //     delete (coefficient);

    //     exponent = computorv2::add(left.getExponent(), right.getExponent());
    //     first.setExponent(exponent);
    //     second.setExponent(left.getExponent());
    //     third.setExponent(right.getExponent());
    //     delete (exponent);

    //     computorv2::Polynomial tmp   = computorv2::add(computorv2::add(first, second), third);
    //     computorv2::Object* freeterm = computorv2::mul(left.getFreeTerm(), right.getFreeTerm());
    //     computorv2::Object* tmp_res  = computorv2::add(AS_OBJECT(&tmp), freeterm);
    //     computorv2::Polynomial res(*(AS_POLYNOMIAL(tmp_res)));
    //     delete (tmp_res);
    //     delete (freeterm);
    //     return (res);
    // }
    computorv2::Polynomial res(left);
    const computorv2::Object* coefficient = computorv2::mul(left.getCoefficient(), AS_OBJECT(&right));
    const computorv2::Object* freeterm    = computorv2::mul(left.getFreeTerm(),    AS_OBJECT(&right));
    res.setCoefficient(coefficient);
    res.setFreeTerm(freeterm);
    delete (coefficient);
    delete (freeterm);
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res(left);
    if (computorv2::eql(left.getBase(), AS_OBJECT(&right)))
    {
        const computorv2::Complex one(1.0, 0.0);
        const computorv2::Object* exponent = computorv2::add(left.getExponent(), AS_OBJECT(&one));
        res.setExponent(exponent);
        delete (exponent);
    }
    else
    {
        const computorv2::Object* coefficient = computorv2::mul(left.getCoefficient(), AS_OBJECT(&right));
        res.setCoefficient(coefficient);
        delete (coefficient);        
    }
    const computorv2::Object* freeterm = computorv2::mul(left.getFreeTerm(), AS_OBJECT(&right));
    res.setFreeTerm(freeterm);
    delete (freeterm);
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res(left);
    if (computorv2::eql(left.getBase(), AS_OBJECT(&right)))
    {
        const computorv2::Complex one(1.0, 0.0);
        const computorv2::Object* exponent = computorv2::add(left.getExponent(), AS_OBJECT(&one));
        res.setExponent(exponent);
        delete (exponent);
    }
    else
    {
        const computorv2::Object* coefficient = computorv2::mul(left.getCoefficient(), AS_OBJECT(&right));
        res.setCoefficient(coefficient);
        delete (coefficient);        
    }
    const computorv2::Object* freeterm = computorv2::mul(left.getFreeTerm(), AS_OBJECT(&right));
    res.setFreeTerm(freeterm);
    delete (freeterm);
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'Vector'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res(left);
    res.setCoefficient(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res(right);
    if (computorv2::eql(AS_OBJECT(&left), right.getBase()))
    {
        const computorv2::Complex one(1.0);
        const computorv2::Object* n = computorv2::add(right.getExponent(), AS_OBJECT(&one));
        res.setExponent(n);
        delete (n);
    }
    else
    {
        const computorv2::Object* a = computorv2::mul(AS_OBJECT(&left), right.getCoefficient());
        res.setCoefficient(a);
        delete (a);        
    }
    const computorv2::Object* b = computorv2::mul(AS_OBJECT(&left), right.getFreeTerm());
    res.setFreeTerm(b);
    delete (b);
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res(right);
    if (computorv2::eql(left, right))
    {
        const computorv2::Complex two(2.0, 0.0);
        res.setExponent(AS_OBJECT(&two));
        return (res);
    }
    res.setCoefficient(AS_OBJECT(&left));
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setCoefficient(AS_OBJECT(&left));
    res.setBase(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'Vector'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setCoefficient(AS_OBJECT(&right));
    res.setBase(AS_OBJECT(&left));
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res(right);
    if (computorv2::eql(AS_OBJECT(&left), right.getBase()))
    {
        const computorv2::Complex one(1.0);
        const computorv2::Object* n = computorv2::add(right.getExponent(), AS_OBJECT(&one));
        res.setExponent(n);
        delete (n);
    }
    else
    {
        const computorv2::Object* a = computorv2::mul(AS_OBJECT(&left), right.getCoefficient());
        res.setCoefficient(a);
        delete (a);        
    }
    const computorv2::Object* b = computorv2::mul(AS_OBJECT(&left), right.getFreeTerm());
    res.setFreeTerm(b);
    delete (b);
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setCoefficient(AS_OBJECT(&right));
    res.setBase(AS_OBJECT(&left));
    return (res);
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&right));
    if (computorv2::eql(left, right))
    {
        res.setExponent(2.0);
        return (res);
    }
    res.setCoefficient(AS_OBJECT(&left));
    return (res);
}

/* ----------------------------------------------------- div ----------------------------------------------------- */

computorv2::Object* computorv2::div(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'div' not supported between null types.");
    else if (IS_VECTOR(left) && IS_VECTOR(right))
        return (computorv2::div(*AS_VECTOR(left), *AS_VECTOR(right)).copy());
    else if (IS_VECTOR(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_VECTOR(left), *AS_MATRIX(right)).copy());
    else if (IS_VECTOR(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_VECTOR(left), *AS_COMPLEX(right)).copy());
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_VECTOR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_VECTOR(left) && IS_USFUNC(right))
        return (computorv2::div(*AS_VECTOR(left), *AS_USFUNC(right)).copy());
    else if (IS_VECTOR(left) && IS_INDVAR(right))
        return (computorv2::div(*AS_VECTOR(left), *AS_INDVAR(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
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
    else if (IS_USFUNC(left) && IS_VECTOR(right))
        return (computorv2::div(*AS_USFUNC(left), *AS_VECTOR(right)).copy());
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
    else if (IS_INDVAR(left) && IS_VECTOR(right))
        return (computorv2::div(*AS_INDVAR(left), *AS_VECTOR(right)).copy());
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

computorv2::Matrix computorv2::div(const computorv2::Vector& left, const computorv2::Vector& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Matrix::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Matrix computorv2::div(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Matrix::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Vector computorv2::div(const computorv2::Vector& left, const computorv2::Complex& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Vector::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Matrix computorv2::div(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Matrix::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Matrix computorv2::div(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Matrix::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Matrix computorv2::div(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Matrix::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Matrix computorv2::div(const computorv2::Complex& left, const computorv2::Vector& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Matrix::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Matrix computorv2::div(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Matrix::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Complex computorv2::div(const computorv2::Complex& left, const computorv2::Complex& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Complex::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    if (computorv2::eql(left, right))
    {
        computorv2::Polynomial res(right);
        res.setExponent(0.0);
        return (res);
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    if (computorv2::eql(AS_OBJECT(&left), right.getBase()))
    {
        if (right.getExponent()->isnull())
        {
            const computorv2::Object* d = computorv2::add(right.getCoefficient(), right.getFreeTerm());
            const computorv2::Object* p = computorv2::div(AS_OBJECT(&left), d);
            delete (d);
            if (!IS_POLYNOMIAL(p))
            {
                delete (p);
                throw std::logic_error("IndependentVariable / Anything must be Polynomial.");
            }
            computorv2::Polynomial res(*AS_POLYNOMIAL(p));
            delete (p);
            return (res);
        }
        if ((right.getCoefficient()->isnull()) || (right.getBase()->isnull()))
        {
            const computorv2::Object* p = computorv2::div(AS_OBJECT(&left), right.getFreeTerm());
            if (!IS_POLYNOMIAL(p))
            {
                delete (p);
                throw std::logic_error("IndependentVariable / Anything must be Polynomial.");
            }
            computorv2::Polynomial res(*AS_POLYNOMIAL(p));
            delete (p);
            return (res);
        }
        if (right.getFreeTerm()->isnull())
        {
            const computorv2::Complex one(1.0, 0.0);
            const computorv2::Object* a = computorv2::div(AS_OBJECT(&one), right.getCoefficient());
            const computorv2::Object* n = computorv2::sub(AS_OBJECT(&one), right.getExponent());
            computorv2::Polynomial res(left);
            res.setCoefficient(a);
            res.setExponent(n);
            delete (a);
            delete (n);
            return (res);
        }
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    if (right.isnull())
    {
        throw std::logic_error("division by zero!");
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    if (computorv2::eql(left, right))
    {
        computorv2::Polynomial res(right);
        const computorv2::Complex zero(0.0, 0.0);
        res.setExponent(AS_OBJECT(&zero));
        return (res);
    }
    return (computorv2::mul(left, computorv2::inverse(right)));
}

/* ----------------------------------------------------- mod ----------------------------------------------------- */

computorv2::Object* computorv2::mod(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Operation 'mod' not supported between null types.");
    else if (IS_VECTOR(left) && IS_VECTOR(right))
        return (computorv2::mod(*AS_VECTOR(left), *AS_VECTOR(right)).copy());
    else if (IS_VECTOR(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_VECTOR(left), *AS_MATRIX(right)).copy());
    else if (IS_VECTOR(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_VECTOR(left), *AS_COMPLEX(right)).copy());
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_VECTOR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_VECTOR(left) && IS_USFUNC(right))
        return (computorv2::mod(*AS_VECTOR(left), *AS_USFUNC(right)).copy());
    else if (IS_VECTOR(left) && IS_INDVAR(right))
        return (computorv2::mod(*AS_VECTOR(left), *AS_INDVAR(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
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
    else if (IS_USFUNC(left) && IS_VECTOR(right))
        return (computorv2::mod(*AS_USFUNC(left), *AS_VECTOR(right)).copy());
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
    else if (IS_INDVAR(left) && IS_VECTOR(right))
        return (computorv2::mod(*AS_INDVAR(left), *AS_VECTOR(right)).copy());
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

computorv2::Vector computorv2::mod(const computorv2::Vector& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Vector' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::mod(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Vector' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Vector computorv2::mod(const computorv2::Vector& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Vector' and 'Complex'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Polynomial computorv2::mod(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Vector' and 'Polynomial'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Vector' and 'UsualFunction'.");
    return (computorv2::Polynomial::null());
}

computorv2::Polynomial computorv2::mod(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Vector' and 'IndependentVariable'.");
    return (computorv2::Polynomial::null());
}

computorv2::Matrix computorv2::mod(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'Vector'.");
    return (computorv2::Matrix::null());
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

computorv2::Vector computorv2::mod(const computorv2::Complex& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Complex' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
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
    return (computorv2::Complex(0.0, 0.0));
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

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'Vector'.");
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

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'Vector'.");
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

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'Vector'.");
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
    else if (IS_VECTOR(left) && IS_VECTOR(right))
        return (computorv2::pow(*AS_VECTOR(left), *AS_VECTOR(right)).copy());
    else if (IS_VECTOR(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_VECTOR(left), *AS_MATRIX(right)).copy());
    else if (IS_VECTOR(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_VECTOR(left), *AS_COMPLEX(right)).copy());
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_VECTOR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_VECTOR(left) && IS_USFUNC(right))
        return (computorv2::pow(*AS_VECTOR(left), *AS_USFUNC(right)).copy());
    else if (IS_VECTOR(left) && IS_INDVAR(right))
        return (computorv2::pow(*AS_VECTOR(left), *AS_INDVAR(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
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
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
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
    else if (IS_USFUNC(left) && IS_VECTOR(right))
        return (computorv2::pow(*AS_USFUNC(left), *AS_VECTOR(right)).copy());
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
    else if (IS_INDVAR(left) && IS_VECTOR(right))
        return (computorv2::pow(*AS_INDVAR(left), *AS_VECTOR(right)).copy());
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

computorv2::Vector computorv2::pow(const computorv2::Vector& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Vector' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::pow(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Vector' and 'Matrix'.");
    return (computorv2::Matrix::null());
}

computorv2::Vector computorv2::pow(const computorv2::Vector& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Vector' and 'Complex'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Polynomial computorv2::pow(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Matrix computorv2::pow(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Matrix' and 'Vector'.");
    return (computorv2::Matrix::null());
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
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Vector computorv2::pow(const computorv2::Complex& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Complex' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
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
    return (computorv2::Complex(0.0, 0.0));
}

computorv2::Polynomial computorv2::pow(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    if (left.isnull())
    {
        return (computorv2::Polynomial::null());
    }
    computorv2::Polynomial res("x");
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

#endif//!__COMPUTORV2_SOURCES_COMPUTORV2
