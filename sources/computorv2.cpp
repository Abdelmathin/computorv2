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
    else if (IS_USUAL_FUNCTION(left))
        return (computorv2::isfreeterm(*AS_USUAL_FUNCTION(left)));
    else if (IS_INDEPENDENT(left))
        return (computorv2::isfreeterm(*AS_INDEPENDENT(left)));
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
    else if (IS_USUAL_FUNCTION(left))
        return (computorv2::derivative(*AS_USUAL_FUNCTION(left), right));
    else if (IS_INDEPENDENT(left))
        return (computorv2::derivative(*AS_INDEPENDENT(left), right));
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
    (void)left;
    throw std::logic_error("Operation 'derivative' not supported for type: 'Complex'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::derivative(const computorv2::Polynomial& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'derivative' not supported for type: 'Polynomial'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::derivative(const computorv2::UsualFunction& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'derivative' not supported for type: 'UsualFunction'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::derivative(const computorv2::IndependentVariable& left, const computorv2::IndependentVariable& right)
{
    (void)left;
    throw std::logic_error("Operation 'derivative' not supported for type: 'IndependentVariable'");
    return (computorv2::Polynomial("x"));
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
    else if (IS_VECTOR(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_VECTOR(left) && IS_INDEPENDENT(right))
        return (computorv2::add(*AS_VECTOR(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_MATRIX(left) && IS_INDEPENDENT(right))
        return (computorv2::add(*AS_MATRIX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDEPENDENT(right))
        return (computorv2::add(*AS_COMPLEX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDEPENDENT(right))
        return (computorv2::add(*AS_POLYNOMIAL(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_USUAL_FUNCTION(left), *AS_VECTOR(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_USUAL_FUNCTION(left), *AS_MATRIX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_USUAL_FUNCTION(left), *AS_COMPLEX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_USUAL_FUNCTION(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::add(*AS_USUAL_FUNCTION(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_INDEPENDENT(right))
        return (computorv2::add(*AS_USUAL_FUNCTION(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_VECTOR(right))
        return (computorv2::add(*AS_INDEPENDENT(left), *AS_VECTOR(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_MATRIX(right))
        return (computorv2::add(*AS_INDEPENDENT(left), *AS_MATRIX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_COMPLEX(right))
        return (computorv2::add(*AS_INDEPENDENT(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_POLYNOMIAL(right))
        return (computorv2::add(*AS_INDEPENDENT(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::add(*AS_INDEPENDENT(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_INDEPENDENT(right))
        return (computorv2::add(*AS_INDEPENDENT(left), *AS_INDEPENDENT(right)).copy());
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
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Complex' and 'Complex'.");
    return (computorv2::Complex(0.0, 0.0));
}

computorv2::Polynomial computorv2::add(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Complex' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
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
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::add(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'add' not supported between types 'Polynomial' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
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
    else if (IS_VECTOR(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::sub(*AS_VECTOR(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_VECTOR(left) && IS_INDEPENDENT(right))
        return (computorv2::sub(*AS_VECTOR(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_MATRIX(left) && IS_INDEPENDENT(right))
        return (computorv2::sub(*AS_MATRIX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDEPENDENT(right))
        return (computorv2::sub(*AS_COMPLEX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDEPENDENT(right))
        return (computorv2::sub(*AS_POLYNOMIAL(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_VECTOR(right))
        return (computorv2::sub(*AS_USUAL_FUNCTION(left), *AS_VECTOR(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_USUAL_FUNCTION(left), *AS_MATRIX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_USUAL_FUNCTION(left), *AS_COMPLEX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_USUAL_FUNCTION(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::sub(*AS_USUAL_FUNCTION(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_INDEPENDENT(right))
        return (computorv2::sub(*AS_USUAL_FUNCTION(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_VECTOR(right))
        return (computorv2::sub(*AS_INDEPENDENT(left), *AS_VECTOR(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_MATRIX(right))
        return (computorv2::sub(*AS_INDEPENDENT(left), *AS_MATRIX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_COMPLEX(right))
        return (computorv2::sub(*AS_INDEPENDENT(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_POLYNOMIAL(right))
        return (computorv2::sub(*AS_INDEPENDENT(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::sub(*AS_INDEPENDENT(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_INDEPENDENT(right))
        return (computorv2::sub(*AS_INDEPENDENT(left), *AS_INDEPENDENT(right)).copy());
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
    else if (IS_VECTOR(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_VECTOR(left) && IS_INDEPENDENT(right))
        return (computorv2::mul(*AS_VECTOR(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_MATRIX(left) && IS_INDEPENDENT(right))
        return (computorv2::mul(*AS_MATRIX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDEPENDENT(right))
        return (computorv2::mul(*AS_COMPLEX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDEPENDENT(right))
        return (computorv2::mul(*AS_POLYNOMIAL(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_USUAL_FUNCTION(left), *AS_VECTOR(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_USUAL_FUNCTION(left), *AS_MATRIX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_USUAL_FUNCTION(left), *AS_COMPLEX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_USUAL_FUNCTION(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mul(*AS_USUAL_FUNCTION(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_INDEPENDENT(right))
        return (computorv2::mul(*AS_USUAL_FUNCTION(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_VECTOR(right))
        return (computorv2::mul(*AS_INDEPENDENT(left), *AS_VECTOR(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_MATRIX(right))
        return (computorv2::mul(*AS_INDEPENDENT(left), *AS_MATRIX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_COMPLEX(right))
        return (computorv2::mul(*AS_INDEPENDENT(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_POLYNOMIAL(right))
        return (computorv2::mul(*AS_INDEPENDENT(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mul(*AS_INDEPENDENT(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_INDEPENDENT(right))
        return (computorv2::mul(*AS_INDEPENDENT(left), *AS_INDEPENDENT(right)).copy());
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
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'Complex'.");
    return (computorv2::Complex(0.0, 0.0));
}

computorv2::Polynomial computorv2::mul(const computorv2::Complex& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Complex' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
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
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'Complex'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::Polynomial& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'Polynomial'.");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::mul(const computorv2::Polynomial& left, const computorv2::UsualFunction& right)
{
    (void)left; (void) right;
    throw std::logic_error("Operation 'mul' not supported between types 'Polynomial' and 'UsualFunction'.");
    return (computorv2::Polynomial("x"));
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
    else if (IS_VECTOR(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::div(*AS_VECTOR(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_VECTOR(left) && IS_INDEPENDENT(right))
        return (computorv2::div(*AS_VECTOR(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_MATRIX(left) && IS_INDEPENDENT(right))
        return (computorv2::div(*AS_MATRIX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDEPENDENT(right))
        return (computorv2::div(*AS_COMPLEX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDEPENDENT(right))
        return (computorv2::div(*AS_POLYNOMIAL(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_VECTOR(right))
        return (computorv2::div(*AS_USUAL_FUNCTION(left), *AS_VECTOR(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_USUAL_FUNCTION(left), *AS_MATRIX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_USUAL_FUNCTION(left), *AS_COMPLEX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_USUAL_FUNCTION(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::div(*AS_USUAL_FUNCTION(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_INDEPENDENT(right))
        return (computorv2::div(*AS_USUAL_FUNCTION(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_VECTOR(right))
        return (computorv2::div(*AS_INDEPENDENT(left), *AS_VECTOR(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_MATRIX(right))
        return (computorv2::div(*AS_INDEPENDENT(left), *AS_MATRIX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_COMPLEX(right))
        return (computorv2::div(*AS_INDEPENDENT(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_POLYNOMIAL(right))
        return (computorv2::div(*AS_INDEPENDENT(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::div(*AS_INDEPENDENT(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_INDEPENDENT(right))
        return (computorv2::div(*AS_INDEPENDENT(left), *AS_INDEPENDENT(right)).copy());
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
    (void)left; (void) right;
    throw std::logic_error("Operation 'div' not supported between types 'Polynomial' and 'IndependentVariable'.");
    return (computorv2::Polynomial("x"));
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
    else if (IS_VECTOR(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mod(*AS_VECTOR(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_VECTOR(left) && IS_INDEPENDENT(right))
        return (computorv2::mod(*AS_VECTOR(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_MATRIX(left) && IS_INDEPENDENT(right))
        return (computorv2::mod(*AS_MATRIX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDEPENDENT(right))
        return (computorv2::mod(*AS_COMPLEX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDEPENDENT(right))
        return (computorv2::mod(*AS_POLYNOMIAL(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_VECTOR(right))
        return (computorv2::mod(*AS_USUAL_FUNCTION(left), *AS_VECTOR(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_USUAL_FUNCTION(left), *AS_MATRIX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_USUAL_FUNCTION(left), *AS_COMPLEX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_USUAL_FUNCTION(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mod(*AS_USUAL_FUNCTION(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_INDEPENDENT(right))
        return (computorv2::mod(*AS_USUAL_FUNCTION(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_VECTOR(right))
        return (computorv2::mod(*AS_INDEPENDENT(left), *AS_VECTOR(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_MATRIX(right))
        return (computorv2::mod(*AS_INDEPENDENT(left), *AS_MATRIX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_COMPLEX(right))
        return (computorv2::mod(*AS_INDEPENDENT(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_POLYNOMIAL(right))
        return (computorv2::mod(*AS_INDEPENDENT(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::mod(*AS_INDEPENDENT(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_INDEPENDENT(right))
        return (computorv2::mod(*AS_INDEPENDENT(left), *AS_INDEPENDENT(right)).copy());
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
    else if (IS_VECTOR(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::pow(*AS_VECTOR(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_VECTOR(left) && IS_INDEPENDENT(right))
        return (computorv2::pow(*AS_VECTOR(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_MATRIX(left) && IS_VECTOR(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_VECTOR(right)).copy());
    else if (IS_MATRIX(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_MATRIX(right)).copy());
    else if (IS_MATRIX(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_COMPLEX(right)).copy());
    else if (IS_MATRIX(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_MATRIX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_MATRIX(left) && IS_INDEPENDENT(right))
        return (computorv2::pow(*AS_MATRIX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_COMPLEX(left) && IS_VECTOR(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_VECTOR(right)).copy());
    else if (IS_COMPLEX(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_MATRIX(right)).copy());
    else if (IS_COMPLEX(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_COMPLEX(right)).copy());
    else if (IS_COMPLEX(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_COMPLEX(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_COMPLEX(left) && IS_INDEPENDENT(right))
        return (computorv2::pow(*AS_COMPLEX(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_VECTOR(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_VECTOR(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_MATRIX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_COMPLEX(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_POLYNOMIAL(left) && IS_INDEPENDENT(right))
        return (computorv2::pow(*AS_POLYNOMIAL(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_VECTOR(right))
        return (computorv2::pow(*AS_USUAL_FUNCTION(left), *AS_VECTOR(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_USUAL_FUNCTION(left), *AS_MATRIX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_USUAL_FUNCTION(left), *AS_COMPLEX(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_USUAL_FUNCTION(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::pow(*AS_USUAL_FUNCTION(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_USUAL_FUNCTION(left) && IS_INDEPENDENT(right))
        return (computorv2::pow(*AS_USUAL_FUNCTION(left), *AS_INDEPENDENT(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_VECTOR(right))
        return (computorv2::pow(*AS_INDEPENDENT(left), *AS_VECTOR(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_MATRIX(right))
        return (computorv2::pow(*AS_INDEPENDENT(left), *AS_MATRIX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_COMPLEX(right))
        return (computorv2::pow(*AS_INDEPENDENT(left), *AS_COMPLEX(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_POLYNOMIAL(right))
        return (computorv2::pow(*AS_INDEPENDENT(left), *AS_POLYNOMIAL(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_USUAL_FUNCTION(right))
        return (computorv2::pow(*AS_INDEPENDENT(left), *AS_USUAL_FUNCTION(right)).copy());
    else if (IS_INDEPENDENT(left) && IS_INDEPENDENT(right))
        return (computorv2::pow(*AS_INDEPENDENT(left), *AS_INDEPENDENT(right)).copy());
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
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'Polynomial' and 'Complex'.");
    return (computorv2::Polynomial("x"));
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
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'UsualFunction' and 'Complex'.");
    return (computorv2::Polynomial("x"));
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
    (void)left; (void) right;
    throw std::logic_error("Operation 'pow' not supported between types 'IndependentVariable' and 'Complex'.");
    return (computorv2::Polynomial("x"));
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
