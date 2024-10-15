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
# include "../include/Complex.hpp"
# include "../include/Polynomial.hpp"
# include "../include/UsualFunction.hpp"
# include "../include/IndependentVariable.hpp"
# include <sstream>
# include <cmath>
# include <unistd.h>
# include <math.h>

std::string computorv2::tolower(const std::string s)
{
	std::string u = "";
	for (std::string::size_type i = 0; i < s.length(); i++)
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

std::string computorv2::toname(const std::string& name)
{
    #if COMPUTORV2_CASE_INSENSITIVE
    return (computorv2::tolower(name));
    #endif//COMPUTORV2_CASE_INSENSITIVE
    return (name);
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

std::string computorv2::ltrim(const std::string str)
{
    return (computorv2::ltrim(str, "\v\f\t "));
}

std::string computorv2::rtrim(const std::string str)
{
    return (computorv2::rtrim(str, "\v\f\t "));
}

std::string computorv2::trim(const std::string str)
{
    return (computorv2::trim(str, "\v\f\t "));
}

std::string computorv2::ltrim(const std::string str, const std::string charset)
{
    std::string::size_type first = str.find_first_not_of(charset);
    if (first == std::string::npos)
    {
        return ("");
    }
    return (str.substr(first));
}

std::string computorv2::rtrim(const std::string str, const std::string charset)
{
    std::string::size_type last = str.find_last_not_of(charset);
    return (str.substr(0, last + 1));
}

std::string computorv2::trim(const std::string str, const std::string charset)
{
    return (computorv2::ltrim(computorv2::rtrim(str, charset), charset));
}

void computorv2::variables(const computorv2::Object* left, std::map< std::string, const computorv2::Object*>& right)
{
    if (IS_INDVAR(left))
    {
        const computorv2::IndependentVariable& o = *AS_INDVAR(left);
        if (!computorv2::eql(o, computorv2::IndependentVariable::null()))
        {
            right[o.getName()] = left;
        }
    }
    else if (IS_USFUNC(left))
    {
        const computorv2::UsualFunction* o = AS_USFUNC(left);
        computorv2::variables(o->getBody(), right);
    }
    else if (IS_POLYNOMIAL(left))
    {
        const computorv2::Polynomial* o = AS_POLYNOMIAL(left);
        computorv2::variables(o->getCoefficient(), right);
        computorv2::variables(o->getBase(), right);
        computorv2::variables(o->getExponent(), right);
        computorv2::variables(o->getFreeTerm(), right);
    }
    else if (IS_MATRIX(left))
    {
        const computorv2::Matrix* o = AS_MATRIX(left);
        for (unsigned int r = 0; r < o->rows(); r++)
        {
            for (unsigned int c = 0; c < o->columns(); c++)
            {
                computorv2::variables(o->getElementAt(r, c), right);
            }
        }
    }
}

computorv2::Object* computorv2::replace(const computorv2::Object* left, std::map< std::string, const computorv2::Object*>& right)
{
    if (left == NULL)
    {
        return (NULL);
    }
    if (IS_INDVAR(left))
    {
        std::map< std::string, const computorv2::Object*>::iterator it = right.find(AS_INDVAR(left)->getName());
        if ((it != right.end()) && (it->second != NULL))
        {
            return (it->second->copy());
        }
    }
    else if (IS_POLYNOMIAL(left))
    {
        computorv2::Object* a = NULL;
        computorv2::Object* x = NULL;
        computorv2::Object* n = NULL;
        computorv2::Object* b = NULL;
        computorv2::Object* m = NULL;
        computorv2::Object* q = NULL;
        computorv2::Object* r = NULL;
        try
        {
            a = computorv2::replace(AS_POLYNOMIAL(left)->getCoefficient(), right);
            x = computorv2::replace(AS_POLYNOMIAL(left)->getBase()       , right);
            n = computorv2::replace(AS_POLYNOMIAL(left)->getExponent()   , right);
            b = computorv2::replace(AS_POLYNOMIAL(left)->getFreeTerm()   , right);
            m = computorv2::pow(x, n);
            q = computorv2::mul(a, m);
            r = computorv2::add(q, b);
        }
        catch (const std::exception& e)
        {
            delete (a);
            delete (x);
            delete (n);
            delete (b);
            delete (m);
            delete (q);
            throw (e);
        }
        delete (a);
        delete (x);
        delete (n);
        delete (b);
        delete (m);
        delete (q);
        return (r);
    }
    else if (IS_USFUNC(left))
    {
        const computorv2::Object* body = computorv2::replace(AS_USFUNC(left)->getBody(), right);
        computorv2::UsualFunction res(AS_USFUNC(left)->getName(), body);
        delete (body);
        return (res.copy());
    }
    else if (IS_MATRIX(left))
    {
        const computorv2::Matrix* e = AS_MATRIX(left);
        computorv2::Matrix res(e->rows(), e->columns());
        for (unsigned int row = 0; row < e->rows(); row++)
        {
            for (unsigned int column = 0; column < e->columns(); column++)
            {
                const computorv2::Object* u = computorv2::replace(AS_USFUNC(left)->getBody(), right);
                res.setElementAt(row, column, u);
                delete (u);
            }
        }
        return (res.copy());
    }
    return (left->copy());
}

computorv2::Object* computorv2::evaluate(const computorv2::Object* left)
{
    std::map< std::string, const computorv2::Object*> right; right.clear();
    return (computorv2::replace(left, right));
}


/* --------------------------- transpose --------------------------- */

computorv2::Matrix computorv2::transpose(const computorv2::Matrix& left)
{
    computorv2::Matrix res(left.columns(), left.rows());
    for (unsigned int row = 0; row < left.rows(); row++)
    {
        for (unsigned int column = 0; column < left.columns(); column++)
        {
            res.setElementAt(column, row, left.getElementAt(row, column));
        }
    }
    return (res);
}

/* --------------------------- cofactor --------------------------- */

computorv2::Matrix computorv2::cofactor(const computorv2::Matrix& left)
{
    computorv2::Matrix res(left.rows(), left.columns());
    for (unsigned int r = 0; r < left.rows(); r++)
    {
        for (unsigned int c = 0; c < left.columns(); c++)
        {
            const computorv2::Object* d = computorv2::det(computorv2::Matrix(left, r, c));
            if ((r + c) % 2)
            {
                const computorv2::Object* q = computorv2::neg(d);
                res.setElementAt(r, c, q);
                delete (q);
            }
            else
            {
                res.setElementAt(r, c, d);
            }
            delete (d);
        }
    }
    return (res);
}

/* --------------------------- adjugate --------------------------- */

computorv2::Matrix computorv2::adjugate(const computorv2::Matrix& left)
{
    return (computorv2::transpose(computorv2::cofactor(left)));
}

/* ---------------------------- det ---------------------------- */

computorv2::Object* computorv2::det(const computorv2::Matrix& left)
{
    const unsigned int n = (unsigned int) left.rows();
    if ((left.rows() != left.columns()) || (n < 1) || (n > MAX_MATRIX_DET_SIZE))
    {
        throw std::logic_error("Can't calculate determinant!");
    }
    if (n == 1)
    {
        return (left.getElementAt(0, 0)->copy());
    }
    computorv2::Object* res = NULL;
    for (unsigned int r = 0; r < n; r++)
    {
        computorv2::Object* d = computorv2::det(computorv2::Matrix(left, r, 0));
        computorv2::Object* p = computorv2::mul(left.getElementAt(r, 0), d);
        computorv2::Object* q = p;
        delete (d);
        if (r == 0)
        {
            res = q;
            continue ;
        }
        if (r % 2)
        {
            q = computorv2::sub(res, p);
        }
        else
        {
            q = computorv2::add(res, p);
        }
        delete (res);
        delete (p);
        res = q;
    }
    return (res);
}


/* ----------------------------- sqrt ----------------------------- */

computorv2::Complex computorv2::sqrt(const computorv2::Complex& left)
{
    const double a = left.getReal();
    const double b = left.getImage();
    const double t = ::atan(b / a);
    const double r = ::abs(a / ::cos(t));

    return (computorv2::Complex(
        ::sqrt(r) * ::cos(0.5 * t),
        ::sqrt(r) * ::sin(0.5 * t)
    ));
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
    const computorv2::Object* e = computorv2::evaluate(AS_OBJECT(&left));
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
    const computorv2::Object* r = computorv2::evaluate(AS_OBJECT(&right));
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
    computorv2::Matrix res(left.rows(), left.columns());
    for (unsigned int r = 0; r < left.rows(); r++)
    {
        for (unsigned int c = 0; c < left.columns(); c++)
        {
            const computorv2::Object* e = computorv2::neg(left.getElementAt(r, c));
            res.setElementAt(r, c, e);
            delete (e);
        }
    }
    return (res);
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
    res.setCoefficient(0.0 - 1.0);
    return (res);
}

computorv2::Polynomial computorv2::neg(const computorv2::IndependentVariable& left)
{
    computorv2::Polynomial res(left);
    res.setCoefficient(0.0 - 1.0);
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
    if (left.rows() != left.columns())
    {
        throw std::logic_error("The matrix is not square.");
    }
    const computorv2::Object* d = computorv2::det(left);
    if (d->isnull())
    {
        delete (d);
        throw std::logic_error("The matrix is singular.");
    }
    const computorv2::Object* q = computorv2::inv(d);
    delete (d);
    const computorv2::Matrix  g = computorv2::adjugate(left);
    const computorv2::Object* m = computorv2::mul(AS_OBJECT(q), AS_OBJECT(&g));
    delete (q);
    if (!IS_MATRIX(m))
    {
        delete (m);
        throw std::logic_error("Can't calculate matrix inverse.");
    }
    computorv2::Matrix res = *AS_MATRIX(m);
    delete (m);
    return (res);
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
    if (left.columns() != right.rows())
    {
        throw std::logic_error("Can't multiply matrices with incompatible dimensions!");
    }
    computorv2::Matrix res(left.rows(), right.columns());
    for (unsigned int r = 0; r < left.rows(); r++)
    {
        for (unsigned int c = 0; c < right.columns(); c++)
        {
            for (unsigned int i = 0; i < left.columns(); i++)
            {
                const computorv2::Object* e = res.getElementAt(r, c);
                const computorv2::Object* p = computorv2::mul(left.getElementAt(r, i), right.getElementAt(i, c));
                if (e->isnull())
                {
                    res.setElementAt(r,c, p);
                }
                else
                {
                    const computorv2::Object* q = computorv2::add(e, p);
                    res.setElementAt(r,c, q);
                    delete (q);
                }
                delete (p);
            }                
        }
    }
    return (res);
}

computorv2::Matrix computorv2::mul(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    computorv2::Matrix res(left.rows(), left.columns());
    if (!left.isnull() && !right.isnull())
    {
        for (unsigned int row = 0; row < left.rows(); row++)
        {
            for (unsigned int column = 0; column < left.columns(); column++)
            {
                const computorv2::Object* e = computorv2::mul(left.getElementAt(row, column), AS_OBJECT(&right));
                res.setElementAt(row, column, e);
                delete (e);
            }
        }
    }
    return (res);
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
    /* (ax^n + b) * (cy^m + d) */
    if (left.isnull() || right.isnull())
    {
        return (computorv2::Polynomial::null());
    }

    const computorv2::Object* a = left.getCoefficient();
    const computorv2::Object* x = left.getBase();
    const computorv2::Object* n = left.getExponent();
    const computorv2::Object* b = left.getFreeTerm();

    const computorv2::Object* c = right.getCoefficient();
    const computorv2::Object* y = right.getBase();
    const computorv2::Object* m = right.getExponent();
    const computorv2::Object* d = right.getFreeTerm();

    computorv2::Polynomial result(computorv2::Polynomial::null());
    if (b->isnull() && d->isnull()) /* ax^n * cy^m */
    {
        computorv2::Polynomial c1(computorv2::Polynomial::null());
        c1.setCoefficient(0.0);
        c1.setBase(y);
        c1.setExponent(0.0);
        c1.setFreeTerm(c);
        const computorv2::Polynomial axnc = computorv2::mul(left, c1);
        if (computorv2::eql(axnc.getBase(), y))
        {
            const computorv2::Object* nm = computorv2::add(axnc.getExponent(), m);
            result.setCoefficient(axnc.getCoefficient());
            result.setBase(y);
            result.setExponent(nm);
            result.setFreeTerm(0.0);
            delete (nm);
        }
        else
        {
            result.setCoefficient(AS_OBJECT(&axnc));
            result.setBase(y);
            result.setExponent(m);
            result.setFreeTerm(0.0);            
        }
    }
    else if (b->isnull() && (c->isnull() || y->isnull())) /* ax^n * d */
    {
        if (IS_MATRIX(d))
        {
            result.setCoefficient(AS_OBJECT(&left));
            result.setBase(d);
            result.setExponent(1.0);
            result.setFreeTerm(0.0);
        }
        else
        {
            const computorv2::Object* ad = computorv2::mul(a, d);
            result.setCoefficient(ad);
            result.setBase(x);
            result.setExponent(n);
            result.setFreeTerm(0.0);
            delete (ad);            
        }
    }
    else if ((a->isnull() || x->isnull()) && d->isnull()) /* b * cy^m */
    {
        const computorv2::Object* bc = computorv2::mul(b, c);
        result.setCoefficient(bc);
        result.setBase(y);
        result.setExponent(m);
        result.setFreeTerm(0.0);
        delete (bc);
    }
    else if ((a->isnull() || x->isnull()) && (c->isnull() || y->isnull())) /* b * d */
    {
        const computorv2::Object* bd = computorv2::mul(b, d);
        result.setCoefficient(0.0);
        result.setBase(x);
        result.setExponent(0.0);
        result.setFreeTerm(bd);
        delete (bd);
    }
    else
    {        
        computorv2::Polynomial A(computorv2::Polynomial::null());
        A.setCoefficient(a);
        A.setBase(x);
        A.setExponent(n);
        A.setFreeTerm(0.0);

        computorv2::Polynomial B(computorv2::Polynomial::null());
        B.setCoefficient(0.0);
        B.setBase(x);
        B.setExponent(0.0);
        B.setFreeTerm(b);

        computorv2::Polynomial C(computorv2::Polynomial::null());
        C.setCoefficient(c);
        C.setBase(y);
        C.setExponent(m);
        C.setFreeTerm(0.0);

        computorv2::Polynomial D(computorv2::Polynomial::null());
        D.setCoefficient(0.0);
        D.setBase(y);
        D.setExponent(0.0);
        D.setFreeTerm(d);
        result = (computorv2::add(computorv2::add(computorv2::mul(A, C), computorv2::mul(A, D)), computorv2::add(computorv2::mul(B, C), computorv2::mul(B, D))));
    }
    return (result);
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
    if ((left.rows() != right.rows()) || (left.columns() != right.columns()))
    {
        throw std::logic_error("Can't add matrices of different sizes!");
    }
    computorv2::Matrix res(left.rows(), left.columns());
    for (unsigned int r = 0; r < left.rows(); r++)
    {
        for (unsigned int c = 0; c < left.columns(); c++)
        {
            const computorv2::Object* e = computorv2::add(left.getElementAt(r, c), right.getElementAt(r, c));
            res.setElementAt(r, c, e);
            delete (e);
        }
    }
    return (res);
}

computorv2::Matrix computorv2::add(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix(3, 3));
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
    return (computorv2::Matrix(3, 3));
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
    return (computorv2::Matrix(3, 3));
}

computorv2::Matrix computorv2::mod(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mod' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix(3, 3));
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
    return (computorv2::Matrix(3, 3));
}

computorv2::Complex computorv2::mod(const computorv2::Complex& left, const computorv2::Complex& right)
{
    if (right.isnull())
    {
        throw std::logic_error("Division by zero!");
    }
    const double r1 = left.getReal();
    const double m1 = left.getImage();
    const double r2 = right.getReal();
    const double m2 = right.getImage();

    if (IS_ZERO(m1) && IS_ZERO(m2) && IS_ZERO(ABS(r1) - ::floor(ABS(r1))) && IS_ZERO(ABS(r2) - ::floor(ABS(r2))))
    {
        const long ir1 = r1;
        const long ir2 = r2;
        return (computorv2::Complex((ir1 % ir2), 0.0));
    }
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
    return (computorv2::Matrix(3, 3));
}

computorv2::Matrix computorv2::pow(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Matrix' and 'Complex'.");
    return (computorv2::Matrix(3, 3));
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Matrix computorv2::pow(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Complex' and 'Matrix'.");
    return (computorv2::Matrix(3, 3));
}

computorv2::Complex computorv2::pow(const computorv2::Complex& left, const computorv2::Complex& right)
{
    const double a = left.getReal();
    const double b = left.getImage();
    const double c = right.getReal();
    const double d = right.getImage();
    const double t = ::atan(b / a);
    const double r = ::abs(a / ::cos(t));

    const computorv2::Complex A = computorv2::Complex(::pow(r, c) * ::cos(c * t), ::pow(r, c) * ::sin(c * t));
    if (IS_ZERO(d))
    {
        return (A);
    }
    const computorv2::Complex B = computorv2::Complex(::exp(-t * d) * ::cos(::log(r * d)), ::exp(-t * d) * ::sin(::log(r * d)));
    return (computorv2::mul(A, B));
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
        return (computorv2::Polynomial::null());
    }
    if (left.isunity())
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
    if (IS_ZERO(right.getImage()) && IS_ZERO(2.0 - right.getReal()))
    {
        double i = 1;
        computorv2::Polynomial res = left;
        while (!IS_ZERO(right.getReal() - i))
        {
            res = computorv2::mul(res, left);
            i = i + 1;
        }
        return (res);
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
        return (computorv2::Polynomial::null());
    }
    if (left.isunity())
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
        return (computorv2::Polynomial::null());
    }
    if (left.isunity())
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

computorv2::Polynomial computorv2::pow(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    if (right.isnull())
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
    if (right.isnull())
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
    if (right.isnull())
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
    computorv2::Polynomial res(computorv2::IndependentVariable::null());
    res.setBase(AS_OBJECT(&left));
    res.setExponent(AS_OBJECT(&right));
    return (res);
}

/* ----------------------------------------------------- drv ----------------------------------------------------- */

computorv2::Polynomial computorv2::drv(const computorv2::Object* left)
{
    computorv2::Polynomial res = computorv2::Polynomial::null();
    std::map< std::string, const computorv2::Object*> independent_variables;
    computorv2::variables(left, independent_variables);
    std::map< std::string, const computorv2::Object*>::iterator it = independent_variables.begin();
    while (it != independent_variables.end())
    {
        res = computorv2::add(res, computorv2::drv(left, computorv2::IndependentVariable(it->first)));
        it++;
    }
    return (res);
}

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
