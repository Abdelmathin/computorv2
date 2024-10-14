/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:    */
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

#ifndef __COMPUTORV2_SOURCES_CLIENT
# define __COMPUTORV2_SOURCES_CLIENT

# include "../include/computorv2.hpp"
# include "../include/Client.hpp"
# include "../include/Complex.hpp"
# include "../include/UsualFunction.hpp"
# include "../include/IndependentVariable.hpp"
# include "../include/statment.hpp"
# include <iostream>
# include <sstream>
# include <unistd.h>

computorv2::Client::Client(void)
{
	this->init();
}

computorv2::Client::~Client(void)
{
	this->clear();
}

computorv2::Client::Client(const computorv2::Client& other)
{
	*this = other;
}

computorv2::Client& computorv2::Client::operator=(const computorv2::Client& other)
{
	if (this != &other)
	{
		this->_fdin    = other._fdin;
		this->_fdout   = other._fdout;
		this->_fderr   = other._fderr;
		this->_buffer  = other._buffer;
		this->_vm      = other._vm;
		this->_history = other._history;
	}
	return (*this);
}

int computorv2::Client::getFdIn(void)  const
{
	return (this->_fdin);
}

int computorv2::Client::getFdOut(void) const
{
	return (this->_fdout);
}

int computorv2::Client::getFdErr(void) const
{
	return (this->_fderr);
}

void computorv2::Client::setFdIn(int fd)
{
	if (fd >= 0)
	{
		this->_connected = true;
	}
	this->_fdin = fd;
}

void computorv2::Client::setFdOut(int fd)
{
	if (fd >= 0)
	{
		this->_connected = true;
	}
	this->_fdout = fd;
	this->_outputstream.setFdOut(fd);
}

void computorv2::Client::setFdErr(int fd)
{
	if (fd >= 0)
	{
		this->_connected = true;
	}
	this->_fderr = fd;
	this->_errorstream.setFdOut(fd);
}

void computorv2::Client::init(void)
{
	this->_connected = false;
	this->_fdin      = -1;
	this->_fdout     = -1;
	this->_fderr     = -1;
	this->_buffer    = "";
	this->_vm.clear();

	const computorv2::Complex       im_i      = computorv2::Complex(0.0, 1.0)                            ;
	const computorv2::UsualFunction ln_x      = computorv2::ln(computorv2::IndependentVariable("x"))     ;
	const computorv2::UsualFunction exp_x     = computorv2::exp(computorv2::IndependentVariable("x"))    ;
	const computorv2::UsualFunction sin_x     = computorv2::sin(computorv2::IndependentVariable("x"))    ;
	const computorv2::UsualFunction cos_x     = computorv2::cos(computorv2::IndependentVariable("x"))    ;
	const computorv2::UsualFunction tan_x     = computorv2::tan(computorv2::IndependentVariable("x"))    ;
	const computorv2::UsualFunction arcsin_x  = computorv2::arcsin(computorv2::IndependentVariable("x")) ;
	const computorv2::UsualFunction arccos_x  = computorv2::arccos(computorv2::IndependentVariable("x")) ;
	const computorv2::UsualFunction arctan_x  = computorv2::arctan(computorv2::IndependentVariable("x")) ;
	const computorv2::UsualFunction sinh_x    = computorv2::sinh(computorv2::IndependentVariable("x"))   ;
	const computorv2::UsualFunction cosh_x    = computorv2::cosh(computorv2::IndependentVariable("x"))   ;
	const computorv2::UsualFunction tanh_x    = computorv2::tanh(computorv2::IndependentVariable("x"))   ;
	const computorv2::UsualFunction arcsinh_x = computorv2::arcsinh(computorv2::IndependentVariable("x"));
	const computorv2::UsualFunction arccosh_x = computorv2::arccosh(computorv2::IndependentVariable("x"));
	const computorv2::UsualFunction arctanh_x = computorv2::arctanh(computorv2::IndependentVariable("x"));

	this->_vm.setConstantByName("i"      , AS_OBJECT(&im_i      ));
	this->_vm.setConstantByName("ln"     , AS_OBJECT(&ln_x      ));
	this->_vm.setConstantByName("exp"    , AS_OBJECT(&exp_x     ));
	this->_vm.setConstantByName("sin"    , AS_OBJECT(&sin_x     ));
	this->_vm.setConstantByName("cos"    , AS_OBJECT(&cos_x     ));
	this->_vm.setConstantByName("tan"    , AS_OBJECT(&tan_x     ));
	this->_vm.setConstantByName("arcsin" , AS_OBJECT(&arcsin_x  ));
	this->_vm.setConstantByName("arccos" , AS_OBJECT(&arccos_x  ));
	this->_vm.setConstantByName("arctan" , AS_OBJECT(&arctan_x  ));
	this->_vm.setConstantByName("sinh"   , AS_OBJECT(&sinh_x    ));
	this->_vm.setConstantByName("cosh"   , AS_OBJECT(&cosh_x    ));
	this->_vm.setConstantByName("tanh"   , AS_OBJECT(&tanh_x    ));
	this->_vm.setConstantByName("arcsinh", AS_OBJECT(&arcsinh_x ));
	this->_vm.setConstantByName("arccosh", AS_OBJECT(&arccosh_x ));
	this->_vm.setConstantByName("arctanh", AS_OBJECT(&arctanh_x ));

	this->_vm.addFunctionParameter("ln"     , "x");
	this->_vm.addFunctionParameter("exp"    , "x");
	this->_vm.addFunctionParameter("sin"    , "x");
	this->_vm.addFunctionParameter("cos"    , "x");
	this->_vm.addFunctionParameter("tan"    , "x");
	this->_vm.addFunctionParameter("arcsin" , "x");
	this->_vm.addFunctionParameter("arccos" , "x");
	this->_vm.addFunctionParameter("arctan" , "x");
	this->_vm.addFunctionParameter("sinh"   , "x");
	this->_vm.addFunctionParameter("cosh"   , "x");
	this->_vm.addFunctionParameter("tanh"   , "x");
	this->_vm.addFunctionParameter("arcsinh", "x");
	this->_vm.addFunctionParameter("arccosh", "x");
	this->_vm.addFunctionParameter("arctanh", "x");
}

void computorv2::Client::clear(void)
{
	this->_vm.clear();
}

bool computorv2::Client::connected(void) const
{
	return (this->_connected);
}

int computorv2::Client::read(void)
{
	if (!this->connected() || (this->getFdIn() < 0))
	{
		return (-1);
	}
	char buffer[1024];
	const int rd = ::read(this->getFdIn(), buffer, 1024);
	if (rd > 0)
	{
		std::string tmp(buffer, rd);
		if (rd < 1024)
		{
			tmp += "\n";
		}
		this->addBuffer(tmp);
		return (rd);
	}
	this->_connected = false;
	return (-1);
}

int computorv2::Client::history(void)
{
	std::vector<std::string>::const_iterator it = this->_history.begin();
	int i = 0;
	while (it != this->_history.end())
	{
		this->_outputstream << "line[" << i << "]: " << (*it);
		i++;
		it++;
	}
	return (0);
}

int computorv2::Client::error(const computorv2::statment *st, const std::string prompt)
{
	if (st)
	{
		this->_errorstream << "Error: " << prompt << computorv2::crlf << "       ";
		for (std::string::size_type i = st->_eri; i <= st->_pos; i++)
		{
			this->_errorstream << "^";
		}
		this->_errorstream << computorv2::crlf;
		const std::string message = computorv2::ltrim(st->_errmsg);
		if (message != "")
		{
			this->_errorstream << message << computorv2::crlf;
		}
	}
	return (0);
}

int computorv2::Client::parse_line(std::string line)
{
	line = computorv2::trim(line, "\r\n\t\v\f ");
	#if COMPUTORV2_CASE_INSENSITIVE
	line = computorv2::tolower(line);
	#endif//COMPUTORV2_CASE_INSENSITIVE
	if ((line == "") || (line[0] == '#') || (!this->connected()))
	{
		return (0);
	}
	if (line == "history")
	{
		return (this->history());
	}
	else if (line == "variables")
	{
		this->_outputstream << this->_vm.toString() << computorv2::crlf;
		return (0);
	}
	else if (line == "exit")
	{
		this->_connected = false;
		return (0);
	}
	this->_history.push_back(line);
	computorv2::statment st;
	computorv2::statment_init(&st);
	st._pos = 0;
	st._str = line;
	st._len = st._str.size();
	st._vm  = &(this->_vm);
	computorv2::statment_parse(&st);
	if ((st._err != 0) || (st._result == NULL) || (st._pos < st._len))
	{
		this->error(&st, line);
	}
	else
	{
		this->_outputstream << st._result->toString() << computorv2::crlf;
	}
	computorv2::statment_fini(&st);
	return (0);
}

int computorv2::Client::check_line(void)
{
	std::string::size_type i = 0;
	std::string::size_type l = this->_buffer.length();
	while (i < l)
	{
		if ((this->_buffer[i] == '\n') || (((i + 1) < l) && (this->_buffer[i] == '\r') && (this->_buffer[i + 1] == '\n')))
		{
			std::string user_input = this->_buffer.substr(0, i);
			if (this->_buffer[i] == '\n')
			{
				i += 1;
			}
			else
			{
				i += 2;
			}
			if (i >= l)
			{
				this->_buffer = "";
			}
			else
			{
				this->_buffer = this->_buffer.substr(i, this->_buffer.length() - i);
			}
			this->parse_line(user_input);
			i = 0;
			l = this->_buffer.length();
			continue ;
		}
		i++;
	}
	return (0);
}

void computorv2::Client::addBuffer(const std::string& buffer)
{
	this->_buffer += buffer;
	this->check_line();
}

#endif//!__COMPUTORV2_SOURCES_CLIENT
