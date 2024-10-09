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

computorv2::Object* computorv2::Matrix::copy(void) const
{
	return ( new computorv2::Matrix(*this) );
}

computorv2::Object* computorv2::Matrix::evaluate(void) const
{
	return (this->copy());
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

computorv2::Matrix computorv2::Matrix::null(void)
{
	return (computorv2::Matrix(2, 2));
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
}

computorv2::Matrix::Matrix(void)
{
	throw std::logic_error("Can't create Matrix of unknown size!");
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
		this->_data.push_back(zero.copy());
	}
}

computorv2::Matrix::Matrix(
	const computorv2::Complex& i00, const computorv2::Complex& i01,
	const computorv2::Complex& i10, const computorv2::Complex& i11
)
{
	this->_data.clear();
	this->_rows    = 2;
	this->_columns = 2;
	this->_data.push_back(i00.copy());
	this->_data.push_back(i01.copy());
	this->_data.push_back(i10.copy());
	this->_data.push_back(i11.copy());
}

computorv2::Matrix::Matrix(
	const computorv2::Complex &i00, const computorv2::Complex &i01, const computorv2::Complex &i02,
	const computorv2::Complex &i10, const computorv2::Complex &i11, const computorv2::Complex &i12,
	const computorv2::Complex &i20, const computorv2::Complex &i21, const computorv2::Complex &i22
)
{
	this->_data.clear();
	this->_rows    = 3;
	this->_columns = 3;
	this->_data.push_back(i00.copy());
	this->_data.push_back(i01.copy());
	this->_data.push_back(i02.copy());

	this->_data.push_back(i10.copy());
	this->_data.push_back(i11.copy());
	this->_data.push_back(i12.copy());

	this->_data.push_back(i20.copy());
	this->_data.push_back(i21.copy());
	this->_data.push_back(i22.copy());
}

computorv2::Matrix::Matrix(
	const computorv2::Complex &i00, const computorv2::Complex &i01, const computorv2::Complex &i02, const computorv2::Complex &i03,
	const computorv2::Complex &i10, const computorv2::Complex &i11, const computorv2::Complex &i12, const computorv2::Complex &i13,
	const computorv2::Complex &i20, const computorv2::Complex &i21, const computorv2::Complex &i22, const computorv2::Complex &i23,
	const computorv2::Complex &i30, const computorv2::Complex &i31, const computorv2::Complex &i32, const computorv2::Complex &i33
)
{
	this->_data.clear();
	this->_rows    = 4;
	this->_columns = 4;
	this->_data.push_back(i00.copy());
	this->_data.push_back(i01.copy());
	this->_data.push_back(i02.copy());
	this->_data.push_back(i03.copy());

	this->_data.push_back(i10.copy());
	this->_data.push_back(i11.copy());
	this->_data.push_back(i12.copy());
	this->_data.push_back(i13.copy());

	this->_data.push_back(i20.copy());
	this->_data.push_back(i21.copy());
	this->_data.push_back(i22.copy());
	this->_data.push_back(i23.copy());

	this->_data.push_back(i30.copy());
	this->_data.push_back(i31.copy());
	this->_data.push_back(i32.copy());
	this->_data.push_back(i33.copy());

}

void computorv2::Matrix::setElementAt(unsigned int row, unsigned int column, const computorv2::Complex& element)
{
	return (this->setElementAt(row, column, AS_OBJECT(&element)));
}

void computorv2::Matrix::setElementAt(unsigned int row, unsigned int column, const computorv2::Object* element)
{
	if ((row >= this->rows()) || (column >= this->columns()))
	{
		std::stringstream ss(""); ss << "Can't set element at (" << row << ", " << column << ")";
		throw std::logic_error(ss.str());
	}
	if (!element)
	{
		throw std::logic_error("Can't set NULL element!");
	}
	const unsigned int index = (this->rows() * row + column);
	if (this->_data[index])
	{
		delete (this->_data[index]);
	}
	this->_data[index] = element->copy();
}

computorv2::Object* computorv2::Matrix::getElementAt(unsigned int row, unsigned int column) const
{
	if ((row >= this->rows()) || (column >= this->columns()))
	{
		std::stringstream ss(""); ss << "Can't get element at (" << row << ", " << column << ")";
		throw std::logic_error(ss.str());
	}
	return (this->_data[this->rows() * row + column]);
}

unsigned int computorv2::Matrix::rows(void) const
{
	return (this->_rows);
}

unsigned int computorv2::Matrix::columns(void) const
{
	return (this->_columns);
}

std::ostream& operator<<(std::ostream& left, const computorv2::Matrix& right)
{
	left << right.toString();
	return (left);
}

#endif//!__COMPUTORV2_SOURCES_MATRIX
