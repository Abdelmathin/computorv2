/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:    */
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

#ifndef __COMPUTORV2_SOURCES_VECTOR
# define __COMPUTORV2_SOURCES_VECTOR

#include "../include/Vector.hpp"
#include "../include/Object.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <sstream>

int computorv2::Vector::getType(void) const
{
	return (COMPUTORV2_TYPE_VECTOR);
}

std::string computorv2::Vector::getTypeName(void) const
{
    return ("Vector");
}

std::string computorv2::Vector::toString(void) const
{
	throw std::runtime_error("Not implemented: `computorv2::Vector::toString`");
	return ("");
}

computorv2::Object* computorv2::Vector::copy(void) const
{
	return ( new computorv2::Vector(*this) );
}

computorv2::Object* computorv2::Vector::evaluate(void) const
{
	throw std::runtime_error("Not implemented: `computorv2::Vector::evaluate`");
	return (NULL);
}

bool computorv2::Vector::isnull(void) const
{
	throw std::runtime_error("Not implemented: `computorv2::Vector::isnull`");
	return (false);
}

bool computorv2::Vector::isunity(void) const
{
	throw std::runtime_error("Not implemented: `computorv2::Vector::isunity`");
	return (false);
}

computorv2::Vector::Vector(void)
{
	throw std::runtime_error("Not implemented: `computorv2::Vector`");
}

computorv2::Vector::~Vector(void)
{
	throw std::runtime_error("Not implemented: `computorv2::Vector::~Vector`");
}

computorv2::Vector::Vector(const computorv2::Vector& other)
{
	throw std::runtime_error("Not implemented: `computorv2::Vector::Vector(other)`");
	*this = other;
}

computorv2::Vector& computorv2::Vector::operator=(const computorv2::Vector& other)
{
	throw std::runtime_error("Not implemented: `computorv2::Vector::operator=`");
	return (*this);
}

computorv2::Vector::Vector(const computorv2::Complex &a, const computorv2::Complex &b)
{
	throw std::runtime_error("Not implemented: `computorv2::Vector(a, b)`");
}

#endif//!__COMPUTORV2_SOURCES_VECTOR
