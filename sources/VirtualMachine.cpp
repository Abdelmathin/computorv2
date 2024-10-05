/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   VirtualMachine.cpp                                 :+:      :+:    :+:    */
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

#ifndef __COMPUTORV2_SOURCES_VIRTUAL_MACHINE
# define __COMPUTORV2_SOURCES_VIRTUAL_MACHINE

#include "../include/VirtualMachine.hpp"
#include "../include/Object.hpp"
#include <iostream>
#include <map>

computorv2::VirtualMachine::VirtualMachine(void)
{
	this->clear();
}

computorv2::VirtualMachine::~VirtualMachine(void)
{
	this->clear();
}

computorv2::VirtualMachine::VirtualMachine(const VirtualMachine& other)
{
	*this = other;
}

computorv2::VirtualMachine& computorv2::VirtualMachine::operator=(const computorv2::VirtualMachine& other)
{
	if (this != &other)
	{
		this->_variables    = other._variables   ;
		this->_constants    = other._constants   ;
		this->_independents = other._independents;
	}
	return (*this);
}

computorv2::Object* computorv2::VirtualMachine::getVariableByName(const std::string name) const
{
	std::map< std::string, computorv2::Object* >::const_iterator it = this->_variables.find(name);
	if (it == this->_variables.end())
	{
		return (NULL);
	}
	return (it->second);
}

computorv2::Object* computorv2::VirtualMachine::getConstantByName(const std::string name) const
{
	std::map< std::string, computorv2::Object* >::const_iterator it = this->_constants.find(name);
	if (it == this->_constants.end())
	{
		return (NULL);
	}
	return (it->second);
}

computorv2::Object* computorv2::VirtualMachine::getIndependentByName(const std::string name) const
{
	std::map< std::string, computorv2::Object* >::const_iterator it = this->_independents.find(name);
	if (it == this->_independents.end())
	{
		return (NULL);
	}
	return (it->second);
}

void computorv2::VirtualMachine::setVariableByName(const std::string name, computorv2::Object* var)
{
	this->_variables[name] = var;
}

void computorv2::VirtualMachine::setConstantByName(const std::string name, computorv2::Object* var)
{
	this->_constants[name] = var;
}

void computorv2::VirtualMachine::setIndependentByName(const std::string name, computorv2::Object* var)
{
	this->_independents[name] = var;
}

void computorv2::VirtualMachine::delVariableByName(const std::string name)
{
	this->_variables[name] = NULL;
	this->_variables.erase(name);
}

void computorv2::VirtualMachine::delConstantByName(const std::string name)
{
	this->_constants[name] = NULL;
	this->_constants.erase(name);
}

void computorv2::VirtualMachine::delIndependentByName(const std::string name)
{
	this->_independents[name] = NULL;
	this->_independents.erase(name);
}

void computorv2::VirtualMachine::clear(void)
{
	this->_variables.clear();
	this->_constants.clear();
	this->_independents.clear();
}

#endif//!__COMPUTORV2_SOURCES_VIRTUAL_MACHINE
