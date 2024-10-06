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
    (void)left; (void) right;
    throw std::logic_error("Operation 'eql' not supported between types 'Polynomial' and 'UsualFunction'.");
    return (false);
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
    return (0);
}

computorv2::Polynomial computorv2::derivative(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'derivative' not supported for type: 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::derivative(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'derivative' not supported for type: 'Matrix'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::derivative(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    computorv2::Polynomial res(right);
    const computorv2::Complex zero(0.0);
    res.setCoefficient(&zero);
    res.setExponent(&zero);
    res.setFreeTerm(&zero);
    return (res);
}

computorv2::Polynomial computorv2::derivative(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    const computorv2::Object* _a = left.getCoefficient();
    const computorv2::Object* _x = left.getBase();
    const computorv2::Object* _n = left.getExponent();
    const computorv2::Object* _b = left.getFreeTerm();

    const computorv2::Polynomial da = computorv2::derivative(_a, right);
    const computorv2::Polynomial dx = computorv2::derivative(_x, right);
    const computorv2::Polynomial dn = computorv2::derivative(_n, right);
    const computorv2::Polynomial db = computorv2::derivative(_b, right);
    const computorv2::Polynomial xn = computorv2::pow(_x, _n);

    const computorv2::UsualFunction lx = computorv2::UsualFunction("ln", _x);

    computorv2::Object* r1 = computorv2::mul(&da, &xn);
    computorv2::Object* r2 = computorv2::mul(&dn, &lx);
    computorv2::Object* r3 = computorv2::mul(_a, &xn);
    computorv2::Object* r4 = computorv2::mul(&dx, _n);
    computorv2::Object* r5 = computorv2::div(r3, _x);

    computorv2::Object* p1 = computorv2::mul(r2, r3);
    computorv2::Object* p3 = computorv2::mul(r4, r5);

    computorv2::Object* q1 = computorv2::add(r1, p1);
    computorv2::Object* q2 = computorv2::add(p3, _b);

    computorv2::Object* rs = computorv2::add(q1, q2);

    computorv2::Polynomial res(rs);

    delete (r1);
    delete (r2);
    delete (r3);
    delete (r4);
    delete (r5);
    delete (p1);
    delete (p3);
    delete (q1);
    delete (q2);
    delete (rs);
    return (res);
}

computorv2::Polynomial computorv2::derivative(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    if (left.getName() == "ln")
    {
        return (computorv2::div(computorv2::derivative(AS_OBJECT(left.getBody()), right), right));
    }
    throw std::runtime_error("Derivative of '" + left.getName() + "(" + left.getBody()->toString() + ")' not implemented.");
    return (computorv2::Polynomial(right));
}

computorv2::Polynomial computorv2::derivative(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    computorv2::Polynomial res(right);
    const computorv2::Complex zero(0.0);
    const computorv2::Complex one(1.0);
    if (computorv2::eql(left, right))
    {
        res.setCoefficient(&one);
    }
    else
    {
        res.setCoefficient(&zero);
    }
    res.setExponent(&zero);
    res.setFreeTerm(&zero);
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
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
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
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Vector' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Vector' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Matrix computorv2::add(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'Vector'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::add(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::add(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Polynomial computorv2::add(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
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
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Complex computorv2::add(const computorv2::Complex& left, const computorv2::Complex& right)
{
    computorv2::Complex res;
    res.setReal(left.getReal()   + right.getReal());
    res.setImage(left.getImage() + right.getImage());
    return (res);
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    return (computorv2::add(right, left));
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Complex' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Complex' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    computorv2::Polynomial res(left);
    const computorv2::Object* freeterm = computorv2::add(left.getFreeTerm(), &right);
    res.setFreeTerm(freeterm);
    delete (freeterm);
    return (res);
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

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'UsualFunction' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'IndependentVariable' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
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
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
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
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Vector' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Vector' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Matrix computorv2::sub(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'Vector'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::sub(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::sub(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Polynomial computorv2::sub(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
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
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Complex computorv2::sub(const computorv2::Complex& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Complex' and 'Complex'.");
    return (computorv2::Complex(0.0, 0.0));
}

computorv2::Polynomial computorv2::sub(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Complex' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Complex' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Complex' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Polynomial' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Polynomial' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Polynomial' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Polynomial' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'Polynomial' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'UsualFunction' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'UsualFunction' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'UsualFunction' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'UsualFunction' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'UsualFunction' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'UsualFunction' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'IndependentVariable' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'IndependentVariable' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'IndependentVariable' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'IndependentVariable' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::sub(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'sub' not supported between types 'IndependentVariable' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
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
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::mul(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'Matrix'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Vector computorv2::mul(const computorv2::Vector& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'Complex'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Polynomial computorv2::mul(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Vector' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Matrix computorv2::mul(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'Vector'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::mul(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::mul(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Vector computorv2::mul(const computorv2::Complex& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::mul(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'Matrix'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
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
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    computorv2::Polynomial res(left);
    const computorv2::Object* coefficient = computorv2::mul(left.getCoefficient(), &right);
    const computorv2::Object* freeterm    = computorv2::mul(left.getFreeTerm(),    &right);
    res.setCoefficient(coefficient);
    res.setFreeTerm(freeterm);
    delete (coefficient);
    delete (freeterm);
    return (res);
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

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    return (computorv2::mul(left, computorv2::Polynomial(right)));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'UsualFunction' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'IndependentVariable' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
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

computorv2::Vector computorv2::div(const computorv2::Vector& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Vector' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::div(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Vector' and 'Matrix'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Vector computorv2::div(const computorv2::Vector& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Vector' and 'Complex'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Polynomial computorv2::div(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Vector' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Vector' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Vector' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Matrix computorv2::div(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Matrix' and 'Vector'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::div(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::div(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Polynomial computorv2::div(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Matrix' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Matrix' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Vector computorv2::div(const computorv2::Complex& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Complex' and 'Vector'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::div(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Complex' and 'Matrix'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Complex computorv2::div(const computorv2::Complex& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Complex' and 'Complex'.");
    return (computorv2::Complex(0.0, 0.0));
}

computorv2::Polynomial computorv2::div(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Complex' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Complex' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Complex' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Polynomial' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Polynomial' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Polynomial' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Polynomial' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    return (computorv2::mul(left, computorv2::pow(right, computorv2::Complex(-1.0, 0.0))));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'UsualFunction' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'UsualFunction' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'UsualFunction' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'UsualFunction' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'UsualFunction' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'UsualFunction' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'IndependentVariable' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'IndependentVariable' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'IndependentVariable' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'IndependentVariable' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::div(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'IndependentVariable' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
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
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
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
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Vector' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Vector' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Matrix computorv2::mod(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'Vector'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::mod(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::mod(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Polynomial computorv2::mod(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
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
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
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
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Complex' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Complex' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Polynomial' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'UsualFunction' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mod(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'IndependentVariable' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
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
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Vector computorv2::pow(const computorv2::Vector& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Vector' and 'Complex'.");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Polynomial computorv2::pow(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Vector' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Vector' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Vector' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Matrix computorv2::pow(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Matrix' and 'Vector'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::pow(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Matrix' and 'Matrix'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::pow(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Polynomial computorv2::pow(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Matrix' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Matrix' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Matrix' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
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
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Complex computorv2::pow(const computorv2::Complex& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Complex' and 'Complex'.");
    return (computorv2::Complex(0.0, 0.0));
}

computorv2::Polynomial computorv2::pow(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Complex' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Complex' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Complex' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Polynomial' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Polynomial' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    computorv2::Polynomial res(&left);
    res.setExponent(right);
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Polynomial' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Polynomial' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Polynomial' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'UsualFunction' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'UsualFunction' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    computorv2::Polynomial res(&left);
    res.setExponent(right);
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'UsualFunction' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'UsualFunction' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'UsualFunction' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'IndependentVariable' and 'Vector'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'IndependentVariable' and 'Matrix'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    computorv2::Polynomial res(left);
    res.setExponent(right);
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'IndependentVariable' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'IndependentVariable' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'IndependentVariable' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
}

#endif//!__COMPUTORV2_SOURCES_COMPUTORV2
