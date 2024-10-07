/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Complex.cpp                                        :+:      :+:    :+:    */
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

#ifndef __COMPUTORV2_SOURCES_COMPLEX
# define __COMPUTORV2_SOURCES_COMPLEX

# include "../include/computorv2.hpp"
# include "../include/Complex.hpp"
# include "../include/Object.hpp"
# include <iostream>
# include <sstream>

int computorv2::Complex::getType(void) const
{
	return (COMPUTORV2_TYPE_COMPLEX);
}

std::string computorv2::Complex::getTypeName(void) const
{
	return ("Complex");
}

std::string computorv2::Complex::toString(void) const
{
	std::stringstream ss("");
	const double r = this->_real;
	const double m = this->_imag;
	if (!IS_ZERO(r) || IS_ZERO(m))
	{
		ss << r;
	}
	if (!IS_ZERO(m))
    {
        if (!IS_ZERO(r))
        {
            ss << " ";
        }
        if (!IS_ZERO(r) && (m > 0))
        {
            ss << "+";
        }
        if (m < 0)
        {
            ss << "-";
        }
        if (!IS_ZERO(r))
        {
            ss << " ";
        }
        const double aimg = ABS(m);
        if (!IS_ZERO(aimg - 1))
        {
            ss << aimg;
        }
        ss << this->_name;
    }
	return (ss.str());
}

computorv2::Object* computorv2::Complex::copy(void) const
{
	return ( new computorv2::Complex(*this) );
}

computorv2::Object* computorv2::Complex::evaluate(void) const
{
	return (this->copy());
}

bool computorv2::Complex::isnull(void) const
{
	return ((IS_ZERO(this->getReal())) && (IS_ZERO(this->getImage())));
}

bool computorv2::Complex::isunity(void) const
{
	return ((IS_ZERO(this->getReal() - 1.0)) && (IS_ZERO(this->getImage())));
}

computorv2::Complex computorv2::Complex::null(void)
{
	computorv2::Complex res(0.0, 0.0);
	return (res);
}

computorv2::Complex::Complex(void)
{
	this->clear();
}

computorv2::Complex::~Complex(void)
{
	this->clear();
}

computorv2::Complex::Complex(const computorv2::Complex& other)
{
	*this = other;
}

computorv2::Complex& computorv2::Complex::operator=(const computorv2::Complex& other)
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setReal(other.getReal());
		this->setImage(other.getImage());
	}
	return (*this);
}

computorv2::Complex::Complex(const double& real)
{
	this->clear();
	this->setReal(real);
}

computorv2::Complex::Complex(const double& real, const double& image)
{
	this->clear();
	this->setReal(real);
	this->setImage(image);
}

std::string computorv2::Complex::getName(void) const
{
	return (this->_name);
}

double computorv2::Complex::getReal(void) const
{
	return (this->_real);
}

double computorv2::Complex::getImage(void) const
{
	return (this->_imag);
}

void computorv2::Complex::setName(const std::string& name)
{
	this->_name = name;
}

void computorv2::Complex::setReal(const double& real) 
{
	this->_real = real;
}

void computorv2::Complex::setImage(const double& imag)
{
	this->_imag = imag;
}

void computorv2::Complex::clear(void)
{
	this->_name = "i";
	this->_real = 0.0;
	this->_imag = 0.0;
}

std::ostream& operator<<(std::ostream& left, const computorv2::Complex& right)
{
	left << right.toString();
	return (left);
}

#endif//!__COMPUTORV2_SOURCES_COMPLEX
