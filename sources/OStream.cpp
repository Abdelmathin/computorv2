/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   OStream.cpp                                        :+:      :+:    :+:    */
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

#ifndef __COMPUTORV2_SOURCES_OSTREAM
# define __COMPUTORV2_SOURCES_OSTREAM

#include "../include/OStream.hpp"
#include <sstream>
#include <unistd.h>

computorv2::OStream::OStream(void)
{
	this->_fdout = -1;
	this->_stream.str("");
}

computorv2::OStream::OStream(const computorv2::OStream& other)
{
	*this = other;
}

computorv2::OStream& computorv2::OStream::operator=(const computorv2::OStream& other)
{
	if (this != &other)
	{
		this->_fdout = other._fdout;
		this->_stream.str(other._stream.str());
	}
	return (*this);
}

computorv2::OStream& computorv2::OStream::operator<<(int number)
{
	this->_stream << number;
	return (*this);
}

computorv2::OStream& computorv2::OStream::operator<<(const std::string& msg)
{
	if (msg == computorv2::crlf)
	{
		if (this->getFdOut() >= 0)
		{
			const std::string str = this->_stream.str();
			write(this->getFdOut(), str.data(), str.size());
			write(this->getFdOut(), msg.data(), msg.size());
		}
		this->_stream.str("");
		return (*this);
	}
	this->_stream << msg;
	return (*this);
}

computorv2::OStream::~OStream(void)
{
	this->_fdout = -1;
	this->_stream.str("");
}

int computorv2::OStream::getFdOut(void) const
{
	return (this->_fdout);
}

void computorv2::OStream::setFdOut(int fd)
{
	this->_fdout = fd;
}

#endif//!__COMPUTORV2_SOURCES_OSTREAM
