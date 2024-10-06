/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   IndependentVariable.cpp                            :+:      :+:    :+:    */
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

#ifndef __COMPUTORV2_SOURCES_INDEPENDENT_VARIABLE
# define __COMPUTORV2_SOURCES_INDEPENDENT_VARIABLE

# include "../include/computorv2.hpp"
# include "../include/IndependentVariable.hpp"
# include <iostream>
# include <exception>

int computorv2::IndependentVariable::getType(void) const
{
    return (COMPUTORV2_TYPE_INDEPENDENT_VARIABLE);
}

std::string computorv2::IndependentVariable::getTypeName(void) const
{
    return ("IndependentVariable");
}

std::string computorv2::IndependentVariable::toString(void) const
{
    return (this->getName());
}

computorv2::Object* computorv2::IndependentVariable::copy(void) const
{
    return ( new computorv2::IndependentVariable(*this) );
}

computorv2::Object* computorv2::IndependentVariable::evaluate(void) const
{
    return (this->copy());
}

bool computorv2::IndependentVariable::isnull(void) const
{
    return (false);
}

bool computorv2::IndependentVariable::isunity(void) const
{
    return (false);
}

computorv2::IndependentVariable::IndependentVariable(void)
{
    this->_name = "";
    throw std::logic_error("Can't create variable without name!");
}

computorv2::IndependentVariable::IndependentVariable(const std::string& name)
{
    this->setName(name);
}

computorv2::IndependentVariable::~IndependentVariable(void)
{
    this->_name = "";
}

computorv2::IndependentVariable::IndependentVariable(const computorv2::IndependentVariable& other)
{
    this->setName(other.getName());
}

computorv2::IndependentVariable& computorv2::IndependentVariable::operator=(const computorv2::IndependentVariable& other)
{
    if (this != &other)
    {
       this->setName(other.getName());
    }
    return (*this);
}

std::string computorv2::IndependentVariable::getName(void) const
{
    return (this->_name);
}

void computorv2::IndependentVariable::setName(const std::string& name)
{
    const std::string::size_type len = name.size();
    if ((len < 1) || (!IS_VARSTART(name[0])))
    {
         throw std::logic_error("bad Variable Name!");
    }
    for (std::string::size_type i = 0; i < len; ++i)
    {
        if (!IS_VARCHAR(name[i]))
        {
            throw std::logic_error("bad Variable Name!");
        }
    }
    this->_name = name;
}

#endif//!__COMPUTORV2_SOURCES_INDEPENDENT_VARIABLE
