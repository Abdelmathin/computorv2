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

/* --------------------------------------------- eql --------------------------------------------- */

bool computorv2::eql(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Can't do operation 'eql' between NULL objects!");
    else if (IS_VECTOR(left) && IS_VECTOR(left))
        return (computorv2::eql(*AS_VECTOR(left), *AS_VECTOR(right)));
    else if (IS_VECTOR(left) && IS_MATRIX(left))
        return (computorv2::eql(*AS_VECTOR(left), *AS_MATRIX(right)));
    else if (IS_VECTOR(left) && IS_COMPLEX(left))
        return (computorv2::eql(*AS_VECTOR(left), *AS_COMPLEX(right)));
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(left))
        return (computorv2::eql(*AS_VECTOR(left), *AS_POLYNOMIAL(right)));
    else if (IS_VECTOR(left) && IS_USUALFUNCTION(left))
        return (computorv2::eql(*AS_VECTOR(left), *AS_USUALFUNCTION(right)));
    else if (IS_VECTOR(left) && IS_INDEPENDENTVARIABLE(left))
        return (computorv2::eql(*AS_VECTOR(left), *AS_INDEPENDENTVARIABLE(right)));
    else if (IS_MATRIX(left) && IS_VECTOR(left))
        return (computorv2::eql(*AS_MATRIX(left), *AS_VECTOR(right)));
    else if (IS_MATRIX(left) && IS_MATRIX(left))
        return (computorv2::eql(*AS_MATRIX(left), *AS_MATRIX(right)));
    else if (IS_MATRIX(left) && IS_COMPLEX(left))
        return (computorv2::eql(*AS_MATRIX(left), *AS_COMPLEX(right)));
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(left))
        return (computorv2::eql(*AS_MATRIX(left), *AS_POLYNOMIAL(right)));
    else if (IS_MATRIX(left) && IS_USUALFUNCTION(left))
        return (computorv2::eql(*AS_MATRIX(left), *AS_USUALFUNCTION(right)));
    else if (IS_MATRIX(left) && IS_INDEPENDENTVARIABLE(left))
        return (computorv2::eql(*AS_MATRIX(left), *AS_INDEPENDENTVARIABLE(right)));
    else if (IS_COMPLEX(left) && IS_VECTOR(left))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_VECTOR(right)));
    else if (IS_COMPLEX(left) && IS_MATRIX(left))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_MATRIX(right)));
    else if (IS_COMPLEX(left) && IS_COMPLEX(left))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_COMPLEX(right)));
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(left))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)));
    else if (IS_COMPLEX(left) && IS_USUALFUNCTION(left))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_USUALFUNCTION(right)));
    else if (IS_COMPLEX(left) && IS_INDEPENDENTVARIABLE(left))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_INDEPENDENTVARIABLE(right)));
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(left))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_VECTOR(right)));
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(left))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_MATRIX(right)));
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(left))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)));
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(left))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)));
    else if (IS_POLYNOMIAL(left) && IS_USUALFUNCTION(left))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_USUALFUNCTION(right)));
    else if (IS_POLYNOMIAL(left) && IS_INDEPENDENTVARIABLE(left))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_INDEPENDENTVARIABLE(right)));
    else if (IS_USUALFUNCTION(left) && IS_VECTOR(left))
        return (computorv2::eql(*AS_USUALFUNCTION(left), *AS_VECTOR(right)));
    else if (IS_USUALFUNCTION(left) && IS_MATRIX(left))
        return (computorv2::eql(*AS_USUALFUNCTION(left), *AS_MATRIX(right)));
    else if (IS_USUALFUNCTION(left) && IS_COMPLEX(left))
        return (computorv2::eql(*AS_USUALFUNCTION(left), *AS_COMPLEX(right)));
    else if (IS_USUALFUNCTION(left) && IS_POLYNOMIAL(left))
        return (computorv2::eql(*AS_USUALFUNCTION(left), *AS_POLYNOMIAL(right)));
    else if (IS_USUALFUNCTION(left) && IS_USUALFUNCTION(left))
        return (computorv2::eql(*AS_USUALFUNCTION(left), *AS_USUALFUNCTION(right)));
    else if (IS_USUALFUNCTION(left) && IS_INDEPENDENTVARIABLE(left))
        return (computorv2::eql(*AS_USUALFUNCTION(left), *AS_INDEPENDENTVARIABLE(right)));
    else if (IS_INDEPENDENTVARIABLE(left) && IS_VECTOR(left))
        return (computorv2::eql(*AS_INDEPENDENTVARIABLE(left), *AS_VECTOR(right)));
    else if (IS_INDEPENDENTVARIABLE(left) && IS_MATRIX(left))
        return (computorv2::eql(*AS_INDEPENDENTVARIABLE(left), *AS_MATRIX(right)));
    else if (IS_INDEPENDENTVARIABLE(left) && IS_COMPLEX(left))
        return (computorv2::eql(*AS_INDEPENDENTVARIABLE(left), *AS_COMPLEX(right)));
    else if (IS_INDEPENDENTVARIABLE(left) && IS_POLYNOMIAL(left))
        return (computorv2::eql(*AS_INDEPENDENTVARIABLE(left), *AS_POLYNOMIAL(right)));
    else if (IS_INDEPENDENTVARIABLE(left) && IS_USUALFUNCTION(left))
        return (computorv2::eql(*AS_INDEPENDENTVARIABLE(left), *AS_USUALFUNCTION(right)));
    else if (IS_INDEPENDENTVARIABLE(left) && IS_INDEPENDENTVARIABLE(left))
        return (computorv2::eql(*AS_INDEPENDENTVARIABLE(left), *AS_INDEPENDENTVARIABLE(right)));
    throw std::logic_error("Can't do operation 'eql' between '" + left->getTypeName() + "' and '" + right->getTypeName() + "'!");
    return (0);
}

bool computorv2::eql(const computorv2::Vector& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'eql' between 'Vector' and 'Vector'");
    return (false);
}

bool computorv2::eql(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'eql' between 'Vector' and 'Matrix'");
    return (false);
}

bool computorv2::eql(const computorv2::Vector& left, const computorv2::Complex& right)
{
    std::logic_error("Can't do operation 'eql' between 'Vector' and 'Complex'");
    return (false);
}

bool computorv2::eql(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    std::logic_error("Can't do operation 'eql' between 'Vector' and 'Polynomial'");
    return (false);
}

bool computorv2::eql(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    std::logic_error("Can't do operation 'eql' between 'Vector' and 'UsualFunction'");
    return (false);
}

bool computorv2::eql(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'eql' between 'Vector' and 'IndependentVariable'");
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'eql' between 'Matrix' and 'Vector'");
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'eql' between 'Matrix' and 'Matrix'");
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::Complex& right)
{
    std::logic_error("Can't do operation 'eql' between 'Matrix' and 'Complex'");
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    std::logic_error("Can't do operation 'eql' between 'Matrix' and 'Polynomial'");
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    std::logic_error("Can't do operation 'eql' between 'Matrix' and 'UsualFunction'");
    return (false);
}

bool computorv2::eql(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'eql' between 'Matrix' and 'IndependentVariable'");
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'eql' between 'Complex' and 'Vector'");
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'eql' between 'Complex' and 'Matrix'");
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Complex& right)
{
    std::logic_error("Can't do operation 'eql' between 'Complex' and 'Complex'");
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    std::logic_error("Can't do operation 'eql' between 'Complex' and 'Polynomial'");
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::UsualFunction& right)
{
    std::logic_error("Can't do operation 'eql' between 'Complex' and 'UsualFunction'");
    return (false);
}

bool computorv2::eql(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'eql' between 'Complex' and 'IndependentVariable'");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'eql' between 'Polynomial' and 'Vector'");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'eql' between 'Polynomial' and 'Matrix'");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Complex& right)
{
    std::logic_error("Can't do operation 'eql' between 'Polynomial' and 'Complex'");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    std::logic_error("Can't do operation 'eql' between 'Polynomial' and 'Polynomial'");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    std::logic_error("Can't do operation 'eql' between 'Polynomial' and 'UsualFunction'");
    return (false);
}

bool computorv2::eql(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'eql' between 'Polynomial' and 'IndependentVariable'");
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'eql' between 'UsualFunction' and 'Vector'");
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'eql' between 'UsualFunction' and 'Matrix'");
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Complex& right)
{
    std::logic_error("Can't do operation 'eql' between 'UsualFunction' and 'Complex'");
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::Polynomial& right)
{
    std::logic_error("Can't do operation 'eql' between 'UsualFunction' and 'Polynomial'");
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::UsualFunction& right)
{
    std::logic_error("Can't do operation 'eql' between 'UsualFunction' and 'UsualFunction'");
    return (false);
}

bool computorv2::eql(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'eql' between 'UsualFunction' and 'IndependentVariable'");
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'eql' between 'IndependentVariable' and 'Vector'");
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'eql' between 'IndependentVariable' and 'Matrix'");
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Complex& right)
{
    std::logic_error("Can't do operation 'eql' between 'IndependentVariable' and 'Complex'");
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::Polynomial& right)
{
    std::logic_error("Can't do operation 'eql' between 'IndependentVariable' and 'Polynomial'");
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::UsualFunction& right)
{
    std::logic_error("Can't do operation 'eql' between 'IndependentVariable' and 'UsualFunction'");
    return (false);
}

bool computorv2::eql(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'eql' between 'IndependentVariable' and 'IndependentVariable'");
    return (false);
}

/* ------------------------------------------------------ add ------------------------------------------------------ */

computorv2::Object* computorv2::add(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Can't do operation 'add' between NULL objects!");
    else if (IS_VECTOR(left) && IS_VECTOR(left))
        return (computorv2::add(*AS_VECTOR(left), *AS_VECTOR(right)));
    else if (IS_VECTOR(left) && IS_MATRIX(left))
        return (computorv2::add(*AS_VECTOR(left), *AS_MATRIX(right)));
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(left))
        return (computorv2::add(*AS_VECTOR(left), *AS_POLYNOMIAL(right)));
    else if (IS_VECTOR(left) && IS_USUALFUNCTION(left))
        return (computorv2::add(*AS_VECTOR(left), *AS_USUALFUNCTION(right)));
    else if (IS_VECTOR(left) && IS_INDEPENDENTVARIABLE(left))
        return (computorv2::add(*AS_VECTOR(left), *AS_INDEPENDENTVARIABLE(right)));
    else if (IS_MATRIX(left) && IS_VECTOR(left))
        return (computorv2::add(*AS_MATRIX(left), *AS_VECTOR(right)));
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(left))
        return (computorv2::add(*AS_MATRIX(left), *AS_POLYNOMIAL(right)));
    else if (IS_MATRIX(left) && IS_USUALFUNCTION(left))
        return (computorv2::add(*AS_MATRIX(left), *AS_USUALFUNCTION(right)));
    else if (IS_MATRIX(left) && IS_INDEPENDENTVARIABLE(left))
        return (computorv2::add(*AS_MATRIX(left), *AS_INDEPENDENTVARIABLE(right)));
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(left))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_VECTOR(right)));
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(left))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_MATRIX(right)));
    else if (IS_USUALFUNCTION(left) && IS_VECTOR(left))
        return (computorv2::add(*AS_USUALFUNCTION(left), *AS_VECTOR(right)));
    else if (IS_USUALFUNCTION(left) && IS_MATRIX(left))
        return (computorv2::add(*AS_USUALFUNCTION(left), *AS_MATRIX(right)));
    else if (IS_INDEPENDENTVARIABLE(left) && IS_VECTOR(left))
        return (computorv2::add(*AS_INDEPENDENTVARIABLE(left), *AS_VECTOR(right)));
    else if (IS_INDEPENDENTVARIABLE(left) && IS_MATRIX(left))
        return (computorv2::add(*AS_INDEPENDENTVARIABLE(left), *AS_MATRIX(right)));
    throw std::logic_error("Can't do operation 'add' between '" + left->getTypeName() + "' and '" + right->getTypeName() + "'!");
    return (0);
}

computorv2::Vector computorv2::add(const computorv2::Vector& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'add' between 'Vector' and 'Vector'");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::add(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'add' between 'Vector' and 'Matrix'");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Polynomial computorv2::add(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    std::logic_error("Can't do operation 'add' between 'Vector' and 'Polynomial'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    std::logic_error("Can't do operation 'add' between 'Vector' and 'UsualFunction'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'add' between 'Vector' and 'IndependentVariable'");
    return (computorv2::Polynomial("x"));
}

computorv2::Matrix computorv2::add(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'add' between 'Matrix' and 'Vector'");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Polynomial computorv2::add(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    std::logic_error("Can't do operation 'add' between 'Matrix' and 'Polynomial'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    std::logic_error("Can't do operation 'add' between 'Matrix' and 'UsualFunction'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'add' between 'Matrix' and 'IndependentVariable'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'add' between 'Polynomial' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'add' between 'Polynomial' and 'Matrix'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'add' between 'UsualFunction' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'add' between 'UsualFunction' and 'Matrix'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'add' between 'IndependentVariable' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'add' between 'IndependentVariable' and 'Matrix'");
    return (computorv2::Polynomial("x"));
}

#endif//!__COMPUTORV2_SOURCES_COMPUTORV2
