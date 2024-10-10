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
# include "../include/statment.hpp"
# include <iostream>
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
		this->_fdin   = other._fdin;
		this->_fdout  = other._fdout;
		this->_fderr  = other._fderr;
		this->_buffer = other._buffer;
		this->_vm     = other._vm;
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
}

void computorv2::Client::setFdErr(int fd)
{
	if (fd >= 0)
	{
		this->_connected = true;
	}
	this->_fderr = fd;
}

void computorv2::Client::init(void)
{
	this->_connected = false;
	this->_fdin      = -1;
	this->_fdout     = -1;
	this->_fderr     = -1;
	this->_buffer    = "";
	this->_vm.clear();
	this->_vm.setConstantByName("i", new computorv2::Complex(0.0, 1.0));
}

void computorv2::Client::clear(void)
{
	
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
	const std::string s(buffer, rd);
	this->addBuffer(s);
	if (rd < 1)
	{
		this->_connected = false;
	}
	return (rd);
}

int computorv2::Client::error(const computorv2::statment *st, const std::string prompt, std::string message)
{
	if (st)
	{
		message = computorv2::ltrim(message);
		std::cout << "Error: " << prompt << std::endl << "       ";
		for (std::string::size_type i = st->_eri; i <= st->_pos; i++)
		{
			std::cout << "^";
		}
		std::cout << std::endl;
		if (message != "")
		{
			std::cout << message << std::endl;
		}
	}
	return (0);
}

int computorv2::Client::parse_line(std::string line)
{
	line = computorv2::ltrim(line);
	if (line != "")
	{
		computorv2::statment st;
		computorv2::statment_init(&st);
		st._pos = 0;
		st._str = line;
		st._len = st._str.size();
		st._vm  = &(this->_vm);
		try
		{
			computorv2::statment_parseline(&st);
			if ((st._err != 0) || (st._pos < st._len))
			{
				this->error(&st, line, "");
				st._err = COMPUTORV2_ERROR;
			}
		}
		catch (const std::exception& e)
		{
			this->error(&st, line, e.what());
			st._err = COMPUTORV2_ERROR;
		}
		if ((st._err == 0) && (st._result))
		{
			std::cout << st._result->toString() << std::endl;
		}
		computorv2::statment_fini(&st);
	}
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
