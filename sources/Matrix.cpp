/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   Matrix.cpp                                         :+:      :+:    :+:    */
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

#ifndef __COMPUTORV2_SOURCES_MATRIX
# define __COMPUTORV2_SOURCES_MATRIX

# include "../include/computorv2.hpp"
# include "../include/Matrix.hpp"
# include "../include/Object.hpp"
# include <iostream>
# include <sstream>

int computorv2::Matrix::getType(void) const
{
	return (COMPUTORV2_TYPE_MATRIX);
}

std::string computorv2::Matrix::getTypeName(void) const
{
    return ("Matrix");
}

std::string computorv2::Matrix::toString(void) const
{
	std::stringstream ss("");
	for (unsigned int row = 0; row < this->rows(); row++)
	{
		if (row > 0)
		{
			ss << std::endl;
		}
		ss << "[";
		for (unsigned int column = 0; column < this->columns(); column++)
		{
			if (column > 0)
			{
				ss << ",";
			}
			const computorv2::Object* e = this->getElementAt(row, column);
			if (e)
			{
				ss << " " << e->toString() << " ";
			}
			else
			{
				ss << " 0 ";
			}
		}
		ss << "]";
	}
	return (ss.str());
}

std::string computorv2::Matrix::toMarkdown(void) const
{
	std::stringstream ss("");
	ss << "\\begin{bmatrix}" << std::endl;
	for (unsigned int row = 0; row < this->rows(); row++)
	{
		for (unsigned int column = 0; column < this->columns(); column++)
		{
			if (column > 0)
			{
				ss << "&";
			}
			const computorv2::Object* e = this->getElementAt(row, column);
			if (e)
			{
				ss << " " << e->toString() << " ";
			}
			else
			{
				ss << " 0 ";
			}
		}
		ss << "\\\\" << std::endl;
	}
	ss << "\\end{bmatrix}";
	return (ss.str());
}

computorv2::Object* computorv2::Matrix::copy(void) const
{
	return ( new computorv2::Matrix(*this) );
}

bool computorv2::Matrix::isnull(void) const
{
	std::vector< computorv2::Object* >::const_iterator it = this->_data.begin();
	while (it != this->_data.end())
	{
		const computorv2::Object* e = (*it);
		if (!e || (e->isnull() == false))
			return (false);
		it++;
	}
	return (true);
}

bool computorv2::Matrix::isunity(void) const
{
	if (this->rows() != this->columns())
		return (false);
	for (unsigned int r = 0; r < this->rows(); r++)
	{
		for (unsigned int c = 0; c < this->columns(); c++)
		{
			const computorv2::Object* e = this->getElementAt(r, c);
			if ((r == c) && (!e || e->isnull()))
				return (false);
			if ((r != c) && e && (!e->isnull()))
				return (false);
		}
	}
	return (true);
}

bool computorv2::Matrix::isnegative(void) const
{
    return (false);
}

computorv2::Matrix::~Matrix(void)
{
	this->clear();
}

computorv2::Matrix::Matrix(const computorv2::Matrix& other)
{
	*this = other;
}

computorv2::Matrix& computorv2::Matrix::operator=(const computorv2::Matrix& other)
{
	if (this != &other)
	{
		this->clear();
		this->_rows    = other.rows();
		this->_columns = other.columns();
		const computorv2::Complex zero(0.0, 0.0);
		for (unsigned int i = 0; i < other._data.size(); i++)
		{
			const computorv2::Object* e = other._data[i];
			if (e)
			{
				this->_data.push_back(e->copy());
			}
			else
			{
				this->_data.push_back(zero.copy());
			}
		}
	}
	return (*this);
}

void computorv2::Matrix::setElementAt(unsigned int row, unsigned int column, const computorv2::Object* element)
{
	const unsigned int index = (this->columns() * row + column);
	if ((index >= this->_data.size()) || (row >= this->rows()) || (column >= this->columns()))
	{
		std::stringstream ss(""); ss << "Can't set element at (" << row << ", " << column << ")";
		throw std::logic_error(ss.str());
	}
	if (!element)
	{
		throw std::logic_error("Can't set NULL element!");
	}
	if (this->_data[index])
	{
		delete (this->_data[index]);
	}
	this->_data[index] = element->copy();
}

computorv2::Object* computorv2::Matrix::getElementAt(unsigned int row, unsigned int column) const
{
	const unsigned int index = (this->columns() * row + column);
	if ((index >= this->_data.size()) || (row >= this->rows()) || (column >= this->columns()))
	{
		std::stringstream ss(""); ss << "Can't get element at (" << row << ", " << column << ")";
		throw std::logic_error(ss.str());
	}
	return (this->_data[index]);
}

unsigned int computorv2::Matrix::rows(void) const
{
	return (this->_rows);
}

unsigned int computorv2::Matrix::columns(void) const
{
	return (this->_columns);
}

computorv2::Matrix::Matrix(unsigned int rows, unsigned int columns)
{
	if ((rows < 1) || (columns < 1))
	{
		std::stringstream ss(""); ss << "bad Matrix size: (" << rows << "," << columns << ")";
		throw std::logic_error(ss.str());
	}
	this->_rows    = rows;
	this->_columns = columns;
	const computorv2::Complex zero(0.0, 0.0);
	this->_data.clear();
	for (unsigned int i = 0; i < rows * columns; i++)
	{
		computorv2::Object* e = zero.copy();
		this->_data.push_back(e);
	}
}

computorv2::Matrix::Matrix(const computorv2::Matrix& other, unsigned int excluded_row, unsigned int excluded_column)
{
	this->clear();
    if ((other.rows() > 1) && (other.columns() > 1))
    {
    	*this = computorv2::Matrix(other.rows() - 1, other.columns() - 1);
        unsigned int r = 0;
        for (unsigned int row = 0; row < other.rows(); row++)
        {
            if (row != excluded_row)
            {
                unsigned int c = 0;
                for (unsigned int column = 0; column < other.columns(); column++)
                {
                    if (column != excluded_column)
                    {
                    	this->setElementAt(r, c, other.getElementAt(row, column));
                        c++;
                    }
                }
                r++;
            }
        }
    }
}

void computorv2::Matrix::clear(void)
{
	std::vector< computorv2::Object* >::iterator it = this->_data.begin();
	while (it != this->_data.end())
	{
		if (*it)
		{
			delete (*it);
		}
		it++;
	}
	this->_data.clear();
	this->_rows    = 0;
	this->_columns = 0;
}

computorv2::Matrix::Matrix(void)
{
	throw std::logic_error("Can't create Matrix of unknown size!");
}

std::ostream& operator<<(std::ostream& left, const computorv2::Matrix& right)
{
	left << right.toString();
	return (left);
}

#endif//!__COMPUTORV2_SOURCES_MATRIX
