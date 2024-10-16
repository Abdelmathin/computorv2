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

# include "../include/VirtualMachine.hpp"
# include "../include/computorv2.hpp"
# include "../include/Object.hpp"
# include <iostream>
# include <sstream>
# include <map>
# include <algorithm>

computorv2::VirtualMachine::VirtualMachine(void)
{
	this->init();
}

computorv2::VirtualMachine::~VirtualMachine(void)
{
	this->clear();
}

computorv2::VirtualMachine::VirtualMachine(const computorv2::VirtualMachine& other)
{
	this->init();
	*this = other;
}

computorv2::VirtualMachine& computorv2::VirtualMachine::operator=(const computorv2::VirtualMachine& other)
{
	if (this != &other)
	{
		this->clear();
		std::map< std::string, computorv2::Object* >::const_iterator it = other._variables.begin();
		while (it != other._variables.end())
		{
			this->setVariableByName(it->first, it->second);
			it++;
		}
		it = other._constants.begin();
		while (it != other._constants.end())
		{
			this->setConstantByName(it->first, it->second);
			it++;
		}
		it = other._localvariables.begin();
		while (it != other._localvariables.end())
		{
			this->setLocalVariableByName(it->first, it->second);
			it++;
		}
	}
	return (*this);
}

computorv2::Object* computorv2::VirtualMachine::getVariableByName(std::string name) const
{
	name = computorv2::toname(name);
	std::map< std::string, computorv2::Object* >::const_iterator it = this->_variables.find(name);
	if (it == this->_variables.end())
	{
		return (NULL);
	}
	return (it->second);
}

computorv2::Object* computorv2::VirtualMachine::getConstantByName(std::string name) const
{
	name = computorv2::toname(name);
	std::map< std::string, computorv2::Object* >::const_iterator it = this->_constants.find(name);
	if (it == this->_constants.end())
	{
		return (NULL);
	}
	return (it->second);
}

computorv2::Object* computorv2::VirtualMachine::getLocalVariableByName(std::string name) const
{
	name = computorv2::toname(name);
	std::map< std::string, computorv2::Object* >::const_iterator it = this->_localvariables.find(name);
	if (it == this->_localvariables.end())
	{
		return (NULL);
	}
	return (it->second);
}

void computorv2::VirtualMachine::setVariableByName(std::string name, const computorv2::Object* var)
{
	name = computorv2::toname(name);
	if (!var)
	{
		throw std::runtime_error("Can't set NULL Variable!");
	}
	this->delVariableByName(name);
	this->_variables[name] = var->clone();
}

void computorv2::VirtualMachine::setConstantByName(std::string name, const computorv2::Object* var)
{
	name = computorv2::toname(name);
	if (!var)
	{
		throw std::runtime_error("Can't set NULL Constant!");
	}
	this->delConstantByName(name);
	this->_constants[name] = var->clone();
}

void computorv2::VirtualMachine::setLocalVariableByName(std::string name, const computorv2::Object* var)
{
	name = computorv2::toname(name);
	if (!var)
	{
		throw std::runtime_error("Can't set NULL LocalVariable!");
	}
	this->delLocalVariableByName(name);
	this->_localvariables[name] = var->clone();
}

void computorv2::VirtualMachine::delVariableByName(std::string name)
{
	name = computorv2::toname(name);
	std::map< std::string, computorv2::Object* >::iterator it = this->_variables.find(name);
	if ((it != this->_variables.end()) && (it->second != NULL))
	{
		delete (it->second);
	}
	this->_variables[name] = NULL;
	this->_variables.erase(name);
}

void computorv2::VirtualMachine::delConstantByName(std::string name)
{
	name = computorv2::toname(name);
	std::map< std::string, computorv2::Object* >::iterator it = this->_constants.find(name);
	if ((it != this->_constants.end()) && (it->second != NULL))
	{
		delete (it->second);
	}
	this->_constants[name] = NULL;
	this->_constants.erase(name);
}

void computorv2::VirtualMachine::delLocalVariableByName(std::string name)
{
	name = computorv2::toname(name);
	std::map< std::string, computorv2::Object* >::iterator it = this->_localvariables.find(name);
	if ((it != this->_localvariables.end()) && (it->second != NULL))
	{
		delete (it->second);
	}
	this->_localvariables[name] = NULL;
	this->_localvariables.erase(name);
}

void computorv2::VirtualMachine::init(void)
{
	this->_variables.clear();
	this->_constants.clear();
	this->_localvariables.clear();
}

void computorv2::VirtualMachine::clear(void)
{
	std::map< std::string, computorv2::Object* >::const_iterator it = this->_variables.begin();
	while (it != this->_variables.end())
	{
		if (it->second)
		{
			delete (it->second);
		}
		it++;
	}
	it = this->_constants.begin();
	while (it != this->_constants.end())
	{
		if (it->second)
		{
			delete (it->second);
		}
		it++;
	}
	it = this->_localvariables.begin();
	while (it != this->_localvariables.end())
	{
		if (it->second)
		{
			delete (it->second);
		}
		it++;
	}
	this->init();
}

std::string computorv2::VirtualMachine::toString(void) const
{
	std::stringstream ss("");
	std::map< std::string, computorv2::Object* >::const_iterator it = this->_variables.begin();
	while (it != this->_variables.end())
	{
		const computorv2::Object* e = it->second;
		if ((e != NULL) && (it->first.size() > 0))
		{
			ss << e->getTypeName() << " " << it->first << " = '" << e->toString() << "';" << std::endl;
		}
		it++;
	}
	it = this->_constants.begin();
	while (it != this->_constants.end())
	{
		const computorv2::Object* e = it->second;
		if ((e != NULL) && (it->first.size() > 0))
		{
			ss << "const " << e->getTypeName() << " " << it->first << " = '" << e->toString() << "';" << std::endl;
		}
		it++;
	}
	it = this->_localvariables.begin();
	while (it != this->_localvariables.end())
	{
		const computorv2::Object* e = it->second;
		if ((e != NULL) && (it->first.size() > 0))
		{
			ss << "local " << e->getTypeName() << " " << it->first << " = '" << e->toString() << "';" << std::endl;
		}
		it++;
	}
	std::string res = computorv2::trim(ss.str(), "\r\n\t\v\f ");
	return (res);
}

std::ostream& operator<<(std::ostream& os, const computorv2::VirtualMachine& vm)
{
	os << vm.toString();
	return (os);
}

#endif//!__COMPUTORV2_SOURCES_VIRTUAL_MACHINE
