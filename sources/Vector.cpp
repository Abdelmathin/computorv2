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

# include "../include/computorv2.hpp"
# include "../include/Vector.hpp"
# include "../include/Object.hpp"
# include <iostream>
# include <sstream>

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
	std::stringstream ss("");
	ss << "[";
	for (
		computorv2::Vector::const_iterator it = this->begin();
		it != this->end(); it++
	)
	{
		ss << " " << (*it)->toString() << " ";
		if ((it + 1) != this->end())
		{
			ss << ",";
		}
	}
	ss << "]";
	return (ss.str());
}

computorv2::Object* computorv2::Vector::copy(void) const
{
	return ( new computorv2::Vector(*this) );
}

computorv2::Object* computorv2::Vector::evaluate(void) const
{
	return ( new computorv2::Vector(*this) );
}

bool computorv2::Vector::isnull(void) const
{
	for (
		computorv2::Vector::const_iterator it = this->begin();
		it != this->end(); it++
	)
	{
		if (!((*it)->isnull()))
		{
			return (false);
		}
	}
	return (true);
}

bool computorv2::Vector::isunity(void) const
{
	return (false);
}

bool computorv2::Vector::isnegative(void) const
{
    return (false);
}

computorv2::Vector computorv2::Vector::null(void)
{
	return (computorv2::Vector(0.0, 0.0));
}

computorv2::Vector::Vector(void)
{
	this->init();
}

computorv2::Vector::~Vector(void)
{
	this->clear();
}

computorv2::Vector::Vector(const computorv2::Vector& other)
{
	*this = other;
}

computorv2::Vector& computorv2::Vector::operator=(const computorv2::Vector& other)
{
	if (this != &other)
	{
		this->clear();
		for (
			computorv2::Vector::const_iterator it = other.begin();
			it != other.end(); it++
		)
		{
			this->push(*it);
		}
	}
	return (*this);
}

computorv2::Vector::Vector(const computorv2::Complex &a, const computorv2::Complex &b)
{
	this->init();
	this->push(AS_OBJECT(&a));
	this->push(AS_OBJECT(&b));
}

computorv2::Vector::Vector(const computorv2::Complex &a, const computorv2::Complex &b, const computorv2::Complex &c)
{
	this->init();
	this->push(AS_OBJECT(&a));
	this->push(AS_OBJECT(&b));
	this->push(AS_OBJECT(&c));
}

void computorv2::Vector::init(void)
{
	this->_data.clear();
}

void computorv2::Vector::clear(void)
{
	for (
		computorv2::Vector::const_iterator it = this->begin();
		it != this->end(); it++
	)
	{
		delete (*it);
	}
	this->_data.clear();
}

void computorv2::Vector::push(const computorv2::Object* element)
{
	if (!element)
	{
		throw std::logic_error("Can't add NULL elements");
	}
	computorv2::Object* e = element->evaluate();
	this->_data.push_back(e);
}

unsigned int computorv2::Vector::size(void) const
{
	return (this->_data.size());
}

computorv2::Vector::const_iterator computorv2::Vector::begin(void) const
{
	return (this->_data.begin());
}

computorv2::Vector::const_iterator computorv2::Vector::end(void) const
{
	return (this->_data.end());
}

std::ostream& operator<<(std::ostream& left, const computorv2::Vector& right)
{
	left << right.toString();
	return (left);
}

#endif//!__COMPUTORV2_SOURCES_VECTOR
