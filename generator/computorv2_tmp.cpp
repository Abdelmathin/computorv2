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

/* ------------------------------ inverse ------------------------------ */

computorv2::Polynomial computorv2::inverse(const computorv2::Object* left)
{
    if (!left)
        throw std::logic_error("Operation 'inverse' not supported for null types.");
    else if (IS_VECTOR(left))
        return (computorv2::inverse(*AS_VECTOR(left)));
    else if (IS_MATRIX(left))
        return (computorv2::inverse(*AS_MATRIX(left)));
    else if (IS_COMPLEX(left))
        return (computorv2::inverse(*AS_COMPLEX(left)));
    else if (IS_POLYNOMIAL(left))
        return (computorv2::inverse(*AS_POLYNOMIAL(left)));
    else if (IS_USFUNC(left))
        return (computorv2::inverse(*AS_USFUNC(left)));
    else if (IS_INDVAR(left))
        return (computorv2::inverse(*AS_INDVAR(left)));
    throw std::logic_error("Operation 'inverse' not supported for type '" + left->getTypeName() + "'.");
    return (0);
}

computorv2::Polynomial computorv2::inverse(const computorv2::Vector& left)
{
    (void)left;
    throw std::logic_error("Operation 'inverse' not supported for type: 'Vector'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::inverse(const computorv2::Matrix& left)
{
    (void)left;
    throw std::logic_error("Operation 'inverse' not supported for type: 'Matrix'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::inverse(const computorv2::Complex& left)
{
    (void)left;
    throw std::logic_error("Operation 'inverse' not supported for type: 'Complex'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::inverse(const computorv2::Polynomial& left)
{
    (void)left;
    throw std::logic_error("Operation 'inverse' not supported for type: 'Polynomial'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::inverse(const computorv2::UsualFunction& left)
{
    (void)left;
    throw std::logic_error("Operation 'inverse' not supported for type: 'UsualFunction'");
    return (computorv2::Polynomial("x"));
}

computorv2::Polynomial computorv2::inverse(const computorv2::IndependentVariable& left)
{
    (void)left;
    throw std::logic_error("Operation 'inverse' not supported for type: 'IndependentVariable'");
    return (computorv2::Polynomial("x"));
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
