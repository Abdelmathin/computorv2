#include "../include/Client.hpp"
#include "../include/Complex.hpp"
#include "../include/utils.hpp"
#include <iostream>

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
	this->_fdin = fd;
}

void computorv2::Client::setFdOut(int fd)
{
	this->_fdout = fd;
}

void computorv2::Client::setFdErr(int fd)
{
	this->_fderr = fd;
}

void computorv2::Client::init(void)
{
	this->_fdin   = -1;
	this->_fdout  = -1;
	this->_fderr  = -1;
	this->_buffer = "";
	this->_vm.clear();
	this->_vm.setConstantByName("i", new computorv2::Complex(0.0, 1.0));
}

void computorv2::Client::clear(void)
{
	
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
			computorv2::statment_parse(&st);			
		}
		catch (const std::exception& e)
		{
			// write(fderr, ...)
			std::cout << e.what() << std::endl;
		}
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

void computorv2::Client::addBuffer(std::string buffer)
{
	this->_buffer += buffer;
	this->check_line();
}
