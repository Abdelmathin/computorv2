/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Matrix.cpp                                         :+:      :+:    :+:    */
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

#ifndef __COMPUTORV2_SOURCES_MATRIX
# define __COMPUTORV2_SOURCES_MATRIX

# include "../include/computorv2.hpp"
# include "../include/Matrix.hpp"
# include "../include/Object.hpp"
# include <iostream>
# include <sstream>

int computorv2::Matrix::getType(void) const
{
	return (COMPUTORV2_TYPE_MATRIX);
}

std::string computorv2::Matrix::getTypeName(void) const
{
    return ("Matrix");
}

std::string computorv2::Matrix::toString(void) const
{
	throw std::runtime_error("Not implemented: `computorv2::Matrix::toString`");
	return ("");
}

computorv2::Object* computorv2::Matrix::copy(void) const
{
	return ( new computorv2::Matrix(*this) );
}

computorv2::Object* computorv2::Matrix::evaluate(void) const
{
	throw std::runtime_error("Not implemented: `computorv2::Matrix::evaluate`");
	return (NULL);
}

bool computorv2::Matrix::isnull(void) const
{
	throw std::runtime_error("Not implemented: `computorv2::Matrix::isnull`");
	return (false);
}

bool computorv2::Matrix::isunity(void) const
{
	throw std::runtime_error("Not implemented: `computorv2::Matrix::isunity`");
	return (false);
}

computorv2::Matrix computorv2::Matrix::null(void)
{
	computorv2::Matrix res(0.0, 0.0, 0.0, 0.0);
	return (res);
}

computorv2::Matrix::Matrix(void)
{
	throw std::runtime_error("Not implemented: `computorv2::Matrix`");
}

computorv2::Matrix::~Matrix(void)
{
	throw std::runtime_error("Not implemented: `computorv2::Matrix::~Matrix`");
}

computorv2::Matrix::Matrix(const computorv2::Matrix& other)
{
	throw std::runtime_error("Not implemented: `computorv2::Matrix::Matrix(other)`");
	*this = other;
}

computorv2::Matrix& computorv2::Matrix::operator=(const computorv2::Matrix& other)
{
	throw std::runtime_error("Not implemented: `computorv2::Matrix::operator=`");
	return (*this);
}

computorv2::Matrix::Matrix(const computorv2::Complex& i00, const computorv2::Complex& i01, const computorv2::Complex& i10, const computorv2::Complex& i11)
{
	throw std::runtime_error("Not implemented: `computorv2::Matrix(i00, i01, i10, i11)`");
}

std::ostream& operator<<(std::ostream& left, const computorv2::Matrix& right)
{
	left << right.toString();
	return (left);
}

#endif//!__COMPUTORV2_SOURCES_MATRIX
