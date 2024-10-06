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

#include "../include/utils.hpp"
#include "../include/Object.hpp"
#include "../include/Matrix.hpp"
#include "../include/Vector.hpp"
#include "../include/Complex.hpp"
#include "../include/Polynomial.hpp"
#include "../include/UsualFunction.hpp"
#include "../include/IndependentVariable.hpp"
#include "../include/computorv2.hpp"
#include <sstream>
#include <unistd.h>

/* --------------------------------------------- eql --------------------------------------------- */

bool computorv2::eql(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Can't do operation 'eql' between NULL objects!");
    else if (IS_VECTOR(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_VECTOR(right)));
    else if (IS_VECTOR(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_MATRIX(right)));
    else if (IS_VECTOR(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_COMPLEX(right)));
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_POLYNOMIAL(right)));
    else if (IS_VECTOR(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_USUAL_FUNCTION(right)));
    else if (IS_VECTOR(left) && IS_INDEPENDENT(right))
        return (computorv2::eql(*AS_VECTOR(left), *AS_INDEPENDENT(right)));
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_VECTOR(right)));
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_MATRIX(right)));
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_COMPLEX(right)));
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_POLYNOMIAL(right)));
    else if (IS_MATRIX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_USUAL_FUNCTION(right)));
    else if (IS_MATRIX(left) && IS_INDEPENDENT(right))
        return (computorv2::eql(*AS_MATRIX(left), *AS_INDEPENDENT(right)));
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_VECTOR(right)));
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_MATRIX(right)));
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_COMPLEX(right)));
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)));
    else if (IS_COMPLEX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_USUAL_FUNCTION(right)));
    else if (IS_COMPLEX(left) && IS_INDEPENDENT(right))
        return (computorv2::eql(*AS_COMPLEX(left), *AS_INDEPENDENT(right)));
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_VECTOR(right)));
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_MATRIX(right)));
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)));
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)));
    else if (IS_POLYNOMIAL(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_USUAL_FUNCTION(right)));
    else if (IS_POLYNOMIAL(left) && IS_INDEPENDENT(right))
        return (computorv2::eql(*AS_POLYNOMIAL(left), *AS_INDEPENDENT(right)));
    else if (IS_USUAL_FUNCTION(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_USUAL_FUNCTION(left), *AS_VECTOR(right)));
    else if (IS_USUAL_FUNCTION(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_USUAL_FUNCTION(left), *AS_MATRIX(right)));
    else if (IS_USUAL_FUNCTION(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_USUAL_FUNCTION(left), *AS_COMPLEX(right)));
    else if (IS_USUAL_FUNCTION(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_USUAL_FUNCTION(left), *AS_POLYNOMIAL(right)));
    else if (IS_USUAL_FUNCTION(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::eql(*AS_USUAL_FUNCTION(left), *AS_USUAL_FUNCTION(right)));
    else if (IS_USUAL_FUNCTION(left) && IS_INDEPENDENT(right))
        return (computorv2::eql(*AS_USUAL_FUNCTION(left), *AS_INDEPENDENT(right)));
    else if (IS_INDEPENDENT(left) && IS_VECTOR(right))
        return (computorv2::eql(*AS_INDEPENDENT(left), *AS_VECTOR(right)));
    else if (IS_INDEPENDENT(left) && IS_MATRIX(right))
        return (computorv2::eql(*AS_INDEPENDENT(left), *AS_MATRIX(right)));
    else if (IS_INDEPENDENT(left) && IS_COMPLEX(right))
        return (computorv2::eql(*AS_INDEPENDENT(left), *AS_COMPLEX(right)));
    else if (IS_INDEPENDENT(left) && IS_POLYNOMIAL(right))
        return (computorv2::eql(*AS_INDEPENDENT(left), *AS_POLYNOMIAL(right)));
    else if (IS_INDEPENDENT(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::eql(*AS_INDEPENDENT(left), *AS_USUAL_FUNCTION(right)));
    else if (IS_INDEPENDENT(left) && IS_INDEPENDENT(right))
        return (computorv2::eql(*AS_INDEPENDENT(left), *AS_INDEPENDENT(right)));
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

/* ----------------------------- isfreeterm ----------------------------- */

bool computorv2::isfreeterm(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Can't do operation 'isfreeterm' for NULL objects!");
    else if (IS_VECTOR(left))
        return (computorv2::isfreeterm(*AS_VECTOR(left)));
    else if (IS_MATRIX(left))
        return (computorv2::isfreeterm(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::isfreeterm(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::isfreeterm(*AS_POLYNOMIAL(left)));
    else if (IS_USUAL_FUNCTION(left))
        return (computorv2::isfreeterm(*AS_USUAL_FUNCTION(left)));
    else if (IS_INDEPENDENT(left))
        return (computorv2::isfreeterm(*AS_INDEPENDENT(left)));
    throw std::logic_error("Can't do operation 'isfreeterm' for '" + left->getTypeName() + "'!");
    return (0);
}

bool computorv2::isfreeterm(const computorv2::Vector& left)
{
    std::logic_error("Can't do operation 'isfreeterm' between 'Vector' and 'Vector'");
    return (false);
}

bool computorv2::isfreeterm(const computorv2::Matrix& left)
{
    std::logic_error("Can't do operation 'isfreeterm' between 'Matrix' and 'Vector'");
    return (false);
}

bool computorv2::isfreeterm(const computorv2::Complex& left)
{
    std::logic_error("Can't do operation 'isfreeterm' between 'Complex' and 'Vector'");
    return (false);
}

bool computorv2::isfreeterm(const computorv2::Polynomial& left)
{
    std::logic_error("Can't do operation 'isfreeterm' between 'Polynomial' and 'Vector'");
    return (false);
}

bool computorv2::isfreeterm(const computorv2::UsualFunction& left)
{
    std::logic_error("Can't do operation 'isfreeterm' between 'UsualFunction' and 'Vector'");
    return (false);
}

bool computorv2::isfreeterm(const computorv2::IndependentVariable& left)
{
    std::logic_error("Can't do operation 'isfreeterm' between 'IndependentVariable' and 'Vector'");
    return (false);
}

/* ------------------------------------------------------ add ------------------------------------------------------ */

computorv2::Object* computorv2::add(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Can't do operation 'add' between NULL objects!");
    else if (IS_VECTOR(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_VECTOR(right)).copy());
    else if (IS_VECTOR(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_MATRIX(right)).copy());
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_VECTOR(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_VECTOR(left) && IS_INDEPENDENT(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_MATRIX(left) && IS_INDEPENDENT(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_USUAL_FUNCTION(left), *AS_VECTOR(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_USUAL_FUNCTION(left), *AS_MATRIX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_INDEPENDENT(left), *AS_VECTOR(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_INDEPENDENT(left), *AS_MATRIX(right)).copy());
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

computorv2::Matrix computorv2::add(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'add' between 'Matrix' and 'Matrix'");
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

/* ------------------------------------------------------ mul ------------------------------------------------------ */

computorv2::Object* computorv2::mul(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Can't do operation 'mul' between NULL objects!");
    else if (IS_VECTOR(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_VECTOR(right)).copy());
    else if (IS_VECTOR(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_MATRIX(right)).copy());
    else if (IS_VECTOR(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_VECTOR(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_VECTOR(left) && IS_INDEPENDENT(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_MATRIX(left) && IS_INDEPENDENT(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_USUAL_FUNCTION(left), *AS_VECTOR(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_USUAL_FUNCTION(left), *AS_MATRIX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_INDEPENDENT(left), *AS_VECTOR(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_INDEPENDENT(left), *AS_MATRIX(right)).copy());
    throw std::logic_error("Can't do operation 'mul' between '" + left->getTypeName() + "' and '" + right->getTypeName() + "'!");
    return (0);
}

computorv2::Vector computorv2::mul(const computorv2::Vector& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'mul' between 'Vector' and 'Vector'");
    return (computorv2::Vector(0.0, 0.0));
}

computorv2::Matrix computorv2::mul(const computorv2::Vector& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'mul' between 'Vector' and 'Matrix'");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Polynomial computorv2::mul(const computorv2::Vector& left, const computorv2::Polynomial& right)
{
    std::logic_error("Can't do operation 'mul' between 'Vector' and 'Polynomial'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Vector& left, const computorv2::UsualFunction& right)
{
    std::logic_error("Can't do operation 'mul' between 'Vector' and 'UsualFunction'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'mul' between 'Vector' and 'IndependentVariable'");
    return (computorv2::Polynomial("x"));
}

computorv2::Matrix computorv2::mul(const computorv2::Matrix& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'mul' between 'Matrix' and 'Vector'");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Matrix computorv2::mul(const computorv2::Matrix& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'mul' between 'Matrix' and 'Matrix'");
    return (computorv2::Matrix(0.0, 0.0, 0.0, 0.0));
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::Polynomial& right)
{
    std::logic_error("Can't do operation 'mul' between 'Matrix' and 'Polynomial'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::UsualFunction& right)
{
    std::logic_error("Can't do operation 'mul' between 'Matrix' and 'UsualFunction'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'mul' between 'Matrix' and 'IndependentVariable'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'mul' between 'Polynomial' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'mul' between 'Polynomial' and 'Matrix'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'mul' between 'UsualFunction' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::UsualFunction& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'mul' between 'UsualFunction' and 'Matrix'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Vector& right)
{
    std::logic_error("Can't do operation 'mul' between 'IndependentVariable' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::IndependentVariable& left, const computorv2::Matrix& right)
{
    std::logic_error("Can't do operation 'mul' between 'IndependentVariable' and 'Matrix'");
    return (computorv2::Polynomial("x"));
}

/* ---------------------------------------- pow ---------------------------------------- */

computorv2::Object* computorv2::pow(const computorv2::Object* left, const computorv2::Object* right)
{
    if (!left || !right)
        throw std::logic_error("Can't do operation 'pow' between NULL objects!");
    throw std::logic_error("Can't do operation 'pow' between '" + left->getTypeName() + "' and '" + right->getTypeName() + "'!");
    return (0);
}

/* ------------------------------------------------------------- derivative ------------------------------------------------------------- */

computorv2::Polynomial computorv2::derivative(const computorv2::Object* left, const computorv2::IndependentVariable& right)
{
    if (!left)
        throw std::logic_error("Can't do operation 'derivative' for NULL objects!");
    else if (IS_VECTOR(left))
        return (computorv2::derivative(*AS_VECTOR(left), right));
    else if (IS_MATRIX(left))
        return (computorv2::derivative(*AS_MATRIX(left), right));
    else if (IS_COMPLEX(left))
        return (computorv2::derivative(*AS_COMPLEX(left), right));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::derivative(*AS_POLYNOMIAL(left), right));
    else if (IS_USUAL_FUNCTION(left))
        return (computorv2::derivative(*AS_USUAL_FUNCTION(left), right));
    else if (IS_INDEPENDENT(left))
        return (computorv2::derivative(*AS_INDEPENDENT(left), right));
    throw std::logic_error("Can't do operation 'derivative' for '" + left->getTypeName() + "'!");
    return (0);
}

computorv2::Polynomial computorv2::derivative(const computorv2::Vector& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'derivative' between 'Vector' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::derivative(const computorv2::Matrix& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'derivative' between 'Matrix' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::derivative(const computorv2::Complex& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'derivative' between 'Complex' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::derivative(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'derivative' between 'Polynomial' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::derivative(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'derivative' between 'UsualFunction' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::derivative(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    std::logic_error("Can't do operation 'derivative' between 'IndependentVariable' and 'Vector'");
    return (computorv2::Polynomial("x"));
}

#endif//!__COMPUTORV2_SOURCES_COMPUTORV2
