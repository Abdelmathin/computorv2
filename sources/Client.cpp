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
# include "../include/Polynomial.hpp"
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

	const computorv2::Complex             i         = computorv2::Complex(0.0, 1.0)        ;
	const computorv2::IndependentVariable x         = computorv2::IndependentVariable("x") ;
	const computorv2::UsualFunction       ln_x      = computorv2::ln(x)                    ;
	const computorv2::UsualFunction       exp_x     = computorv2::exp(x)                   ;
	const computorv2::UsualFunction       sin_x     = computorv2::sin(x)                   ;
	const computorv2::UsualFunction       cos_x     = computorv2::cos(x)                   ;
	const computorv2::UsualFunction       tan_x     = computorv2::tan(x)                   ;
	const computorv2::UsualFunction       arcsin_x  = computorv2::arcsin(x)                ;
	const computorv2::UsualFunction       arccos_x  = computorv2::arccos(x)                ;
	const computorv2::UsualFunction       arctan_x  = computorv2::arctan(x)                ;
	const computorv2::UsualFunction       sinh_x    = computorv2::sinh(x)                  ;
	const computorv2::UsualFunction       cosh_x    = computorv2::cosh(x)                  ;
	const computorv2::UsualFunction       tanh_x    = computorv2::tanh(x)                  ;
	const computorv2::UsualFunction       arcsinh_x = computorv2::arcsinh(x)               ;
	const computorv2::UsualFunction       arccosh_x = computorv2::arccosh(x)               ;
	const computorv2::UsualFunction       arctanh_x = computorv2::arctanh(x)               ;

	this->_vm.setConstantByName("i"              , AS_OBJECT(&i         ));
	this->_vm.setConstantByName("x"              , AS_OBJECT(&x         ));
	this->_vm.setConstantByName("ln"             , AS_OBJECT(&ln_x      ));
	this->_vm.setConstantByName("exp"            , AS_OBJECT(&exp_x     ));
	this->_vm.setConstantByName("sin"            , AS_OBJECT(&sin_x     ));
	this->_vm.setConstantByName("cos"            , AS_OBJECT(&cos_x     ));
	this->_vm.setConstantByName("tan"            , AS_OBJECT(&tan_x     ));
	this->_vm.setConstantByName("arcsin"         , AS_OBJECT(&arcsin_x  ));
	this->_vm.setConstantByName("arccos"         , AS_OBJECT(&arccos_x  ));
	this->_vm.setConstantByName("arctan"         , AS_OBJECT(&arctan_x  ));
	this->_vm.setConstantByName("sinh"           , AS_OBJECT(&sinh_x    ));
	this->_vm.setConstantByName("cosh"           , AS_OBJECT(&cosh_x    ));
	this->_vm.setConstantByName("tanh"           , AS_OBJECT(&tanh_x    ));
	this->_vm.setConstantByName("arcsinh"        , AS_OBJECT(&arcsinh_x ));
	this->_vm.setConstantByName("arccosh"        , AS_OBJECT(&arccosh_x ));
	this->_vm.setConstantByName("arctanh"        , AS_OBJECT(&arctanh_x ));

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
		this->_outputstream << "line[" << i << "]: " << (*it) << computorv2::crlf;
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

int computorv2::Client::solve_equation(const computorv2::Object* equation)
{
	if (!equation)
	{
		return (COMPUTORV2_ERROR);
	}
	const computorv2::Complex zro(0.0, 0.0);
	const computorv2::Complex one(1.0, 0.0);
	const computorv2::Complex two(2.0, 0.0);
	computorv2::Object* e = computorv2::evaluate(equation);
	computorv2::Object* p = e;
	computorv2::Complex a = 0.0;
	computorv2::Complex b = 0.0;
	computorv2::Complex c = 0.0;
	while (IS_POLYNOMIAL(p))
	{
		const computorv2::Polynomial* poly    = AS_POLYNOMIAL(p);
		const computorv2::Object* coefficient = poly->getCoefficient();
		const computorv2::Object* exponent    = poly->getExponent();
		if (!IS_COMPLEX(coefficient))
		{
			break ;
		}
		if (computorv2::eql(exponent, AS_OBJECT(&two)))
		{
			a = computorv2::add(a, *AS_COMPLEX(coefficient));
		}
		else if (computorv2::eql(exponent, AS_OBJECT(&one)))
		{
			b = computorv2::add(b, *AS_COMPLEX(coefficient));
		}
		else if (computorv2::eql(exponent, AS_OBJECT(&zro)))
		{
			c = computorv2::add(c, *AS_COMPLEX(coefficient));
		}
		else
		{
			break ;
		}
		p = poly->getFreeTerm();
	}
	if (!IS_COMPLEX(p))
	{
		this->_outputstream << "I can't solve." << computorv2::crlf;
		delete (e);
		return (COMPUTORV2_ERROR);
	}
	c = computorv2::add(c, *AS_COMPLEX(p));
	delete (e);
	if (a.isnull() && b.isnull())
	{
		this->_outputstream << "Polynomial degree: 0" << computorv2::crlf;
		if (c.isnull())
		{
			this->_outputstream << "The equation admits infinite possibilities of solutions." << computorv2::crlf;
		}
		else
		{
			this->_outputstream << "There is no solution!" << computorv2::crlf;
		}
	}
	else if (a.isnull())
	{
		this->_outputstream << "Polynomial degree: 1" << computorv2::crlf;
		const computorv2::Complex s = computorv2::div(computorv2::neg(c), b);
		this->_outputstream << "The solution is: " << s.toString() << computorv2::crlf;
	}
	else
	{
		this->_outputstream << "Polynomial degree: 2"   << computorv2::crlf;
		this->_outputstream << "Identify coefficients:" << computorv2::crlf;
		this->_outputstream << "a: " << a.toString()   << computorv2::crlf;
		this->_outputstream << "b: " << b.toString()   << computorv2::crlf;
		this->_outputstream << "c: " << c.toString()   << computorv2::crlf;
		this->_outputstream << "Calculate the discriminant: (Δ = b^2 - 4ac)" << computorv2::crlf;
		this->_outputstream << "Δ = (" << b.toString() << ") ";
		this->_outputstream << "* (" << b.toString() << ")";
		this->_outputstream << " - 4 * (" << a.toString() << ")";
		this->_outputstream << " * (" << c.toString() << ")" << computorv2::crlf;
		const computorv2::Complex discriminant = b * b - 4.0 * a * c;
		this->_outputstream << "Δ = " << discriminant.toString() << computorv2::crlf;
		if (discriminant.isnull())
		{
			this->_outputstream << "The equation has one solution." << computorv2::crlf;
			this->_outputstream << ((0.0 - b) / (2.0 * a)).toString() << computorv2::crlf;
		}
		else
		{
			this->_outputstream << "The equation has two solution." << computorv2::crlf;
			this->_outputstream << ((0.0 - b + computorv2::sqrt(discriminant)) / (2.0 * a)).toString() << computorv2::crlf;
			this->_outputstream << ((0.0 - b - computorv2::sqrt(discriminant)) / (2.0 * a)).toString() << computorv2::crlf;
		}
	}
	return (COMPUTORV2_SUCCESS);
}

int computorv2::Client::parse_line(std::string line)
{
	line = computorv2::trim(line, "\r\n\t\v\f ");
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
	try
	{
		if ((st._err != 0) || (st._result == NULL) || (st._pos < st._len))
		{
			this->error(&st, line);
		}
		else
		{
			if (st._type == STATMENT_TYPE_SOLVE)
			{
				this->solve_equation(st._result);
			}
			else
			{
				this->_outputstream << st._result->toString() << computorv2::crlf;
			}
		}		
	}
	catch (const std::exception& xcp)
	{
		this->error(&st, xcp.what());
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
