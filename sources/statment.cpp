/* **************************************************************************  */
/*                                                                             */
/*                                                         :::      ::::::::   */
/*   statment.cpp                                       :+:      :+:    :+:    */
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

#ifndef __COMPUTORV2_SOURCES_UTILS
# define __COMPUTORV2_SOURCES_UTILS

# include "../include/computorv2.hpp"
# include "../include/Object.hpp"
# include "../include/VirtualMachine.hpp"
# include "../include/Matrix.hpp"
# include "../include/Complex.hpp"
# include "../include/Polynomial.hpp"
# include "../include/UsualFunction.hpp"
# include "../include/statment.hpp"
# include <iostream>
# include <sstream>

t_error computorv2::statment_init(computorv2::statment *st)
{
	if (st)
	{
		st->_eri       = 0     ;
		st->_pos       = 0     ;
		st->_str       = ""    ;
		st->_len       = 0     ;
		st->_err       = 0     ;
		st->_errmsg    = ""    ;
		st->_type      = 0     ;
		st->_operation = 0     ;
		st->_varname   = ""    ;
		st->_result    = NULL  ;
		st->_vm        = NULL  ;
		return (COMPUTORV2_SUCCESS);
	}
	return (COMPUTORV2_ERROR);
}

t_error computorv2::statment_fini(computorv2::statment *st)
{
	if (st)
	{
		delete (st->_result);
		st->_result = NULL;
		return (computorv2::statment_init(st));
	}
	return (COMPUTORV2_ERROR);
}

t_error computorv2::statment_error(computorv2::statment *st)
{
	if (st)
	{
		if (st->_err == 0)
		{
			st->_err = COMPUTORV2_ERROR;
		}
		return (st->_err);
	}
	return (COMPUTORV2_ERROR);
}

int computorv2::statment_operation_code(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (COMPUTORV2_OPERATION_NONE);
	}
	computorv2::statment_skip_spaces(st);
	char c = computorv2::statment_getc(st);
	if (c == CHARACTER_PLUS)
	{
		computorv2::statment_next(st);
		return (COMPUTORV2_OPERATION_ADD);
	}
	else if (c == CHARACTER_MINUS)
	{
		computorv2::statment_next(st);
		return (COMPUTORV2_OPERATION_SUB);		
	}
	else if (c == CHARACTER_ASTERISK)
	{
		c = computorv2::statment_next(st);
		if (c == CHARACTER_ASTERISK)
		{
			computorv2::statment_next(st);
			return (COMPUTORV2_OPERATION_MATRIX_MULT);
		}
		return (COMPUTORV2_OPERATION_MULT);		
	}
	else if (c == CHARACTER_SLASH)
	{
		computorv2::statment_next(st);
		return (COMPUTORV2_OPERATION_DIV);		
	}
	else if (c == CHARACTER_MODULUS)
	{
		computorv2::statment_next(st);
		return (COMPUTORV2_OPERATION_MOD);		
	}
	else if (c == CHARACTER_CARET)
	{
		computorv2::statment_next(st);
		return (COMPUTORV2_OPERATION_POW);		
	}
	return (COMPUTORV2_OPERATION_NONE);
}

t_error computorv2::statment_skip_spaces(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	while (st->_pos < st->_len)
	{
		if (st->_str[st->_pos] == '#')
		{
			while (st->_pos < st->_len)
			{
				st->_pos += 1;
			}
			return (st->_err);
		}
		if (!IS_SPACE(st->_str[st->_pos]))
		{
			return (COMPUTORV2_SUCCESS);
		}
		st->_pos += 1;
	}
	return (st->_err);
}

t_error computorv2::statment_skip(computorv2::statment *st, const std::string charset)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	for (std::string::size_type k = 0; (k < charset.size()) && (charset[k] != '\0'); k++)
	{
		if (computorv2::statment_getc(st) == charset[k])
		{
			k = 0;
			st->_pos += 1;
		}
	}
	return (st->_err);
}

bool computorv2::statment_eos(const computorv2::statment *st)
{
	const char c = statment_getc(st);
	return ((c == '\r') || (c == '\n') || (c == '\0'));
}

char computorv2::statment_getc(const computorv2::statment *st)
{
	if ((st != NULL) && (st->_err == 0) && (st->_pos < st->_len))
	{
		return (st->_str[st->_pos]);
	}
	return (0);
}

char computorv2::statment_next(computorv2::statment *st)
{
	if ((st != NULL) && (st->_err == 0) && (st->_pos < st->_len))
	{
		st->_pos += 1;
	}
	return (computorv2::statment_getc(st));
}

std::string computorv2::statment_parsename(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return ("");
	}
	computorv2::statment_skip_spaces(st);
	char c = computorv2::statment_getc(st);
	if (IS_VARSTART(c))
	{
		std::string name = "";
		while (IS_VARCHAR(c))
		{
			name += c;
			c = computorv2::statment_next(st);
		}
		return (name);
	}
	return ("");
}

t_error computorv2::statment_parse_number(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	st->_result = NULL;
	std::stringstream ss("");
	if (!IS_DIGIT(computorv2::statment_getc(st)))
	{
		return (computorv2::statment_error(st));
	}
	while (IS_DIGIT(computorv2::statment_getc(st)))
	{
		ss << computorv2::statment_getc(st);
		computorv2::statment_next(st);
	}
	if (computorv2::statment_getc(st) == '.')
	{
		ss << computorv2::statment_getc(st);
		computorv2::statment_next(st);
		if (!IS_DIGIT(computorv2::statment_getc(st)))
		{
			return (computorv2::statment_error(st));
		}
		while (IS_DIGIT(computorv2::statment_getc(st)))
		{
			ss << computorv2::statment_getc(st);
			computorv2::statment_next(st);
		}
	}
	double r = 0.0; ss >> r;
	if (ss.fail() || !ss.eof())
	{
		return (computorv2::statment_error(st));
	}
	st->_result = new computorv2::Complex(r);
	return (st->_err);
}

t_error computorv2::statment_parse_matrix(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	st->_result = NULL;
	if (computorv2::statment_getc(st) != CHARACTER_LEFT_BRACKET)
		return (computorv2::statment_error(st));
	computorv2::statment_next(st);
	std::vector< std::vector< computorv2::Object* > > elements;
	while (st->_err == 0)
	{
		computorv2::statment_skip_spaces(st);
		if (computorv2::statment_getc(st) != CHARACTER_LEFT_BRACKET)
		{
			st->_err = computorv2::statment_error(st);
			break ;
		}
		computorv2::statment_next(st);
		computorv2::statment_skip_spaces(st);
		if (computorv2::statment_getc(st) == CHARACTER_RIGHT_BRACKET)
		{
			st->_err = computorv2::statment_error(st);
			break ;
		}
		std::vector< computorv2::Object* > row_elements;
		while ((st->_err == 0) && (computorv2::statment_getc(st)))
		{
			st->_result = NULL;
			st->_err = computorv2::statment_parse_expression(st);
			row_elements.push_back(st->_result);
			if ((st->_result == NULL) || (st->_err != 0))
			{
				st->_err = computorv2::statment_error(st);
				break ;
			}
			computorv2::statment_skip_spaces(st);
			const char c = computorv2::statment_getc(st);
			if (c == ',')
			{
				computorv2::statment_next(st);
				continue ;
			}
			else if (c == CHARACTER_RIGHT_BRACKET)
			{
				break ;
			}
			st->_err = computorv2::statment_error(st);
		}
		if ((row_elements.size() < 1) || (st->_result == NULL) || (st->_err != 0) || (computorv2::statment_getc(st) != CHARACTER_RIGHT_BRACKET))
		{
			st->_err = computorv2::statment_error(st);
			break ;
		}
		elements.push_back(row_elements);
		computorv2::statment_next(st);
		computorv2::statment_skip_spaces(st);
		if (computorv2::statment_getc(st) == ';')
		{
			computorv2::statment_next(st);
			continue ;
		}
		else if (computorv2::statment_getc(st) == CHARACTER_RIGHT_BRACKET)
		{
			break ;
		}
		st->_err = computorv2::statment_error(st);
	}
	if (elements.size() < 1)
	{
		st->_err = computorv2::statment_error(st);
		return (st->_err);
	}
	const unsigned int rows    = elements.size();
	const unsigned int columns = elements[0].size();
	computorv2::Matrix res(rows, columns);
	for (unsigned int r = 0; r < elements.size(); r++)
	{
		if (elements[r].size() != columns)
		{
			st->_err = computorv2::statment_error(st);
		}
		for (unsigned int c = 0; c < elements[r].size(); c++)
		{
			const computorv2::Object* e = elements[r][c];
			if (e)
			{
				res.setElementAt(r, c, e);
				delete (e);
				continue ;
			}
			st->_err = computorv2::statment_error(st);
		}
	}
	if (computorv2::statment_getc(st) == CHARACTER_RIGHT_BRACKET)
	{
		computorv2::statment_next(st);
	}
	else
	{
		st->_err = computorv2::statment_error(st);
	}
	st->_result = NULL;
	if (st->_err == 0)
	{
		st->_result = res.clone();
	}
	return (st->_err);
}

t_error computorv2::statment_parse_derivative(computorv2::statment *st)
{
	if ((st == NULL) || (st->_result == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	if (computorv2::statment_getc(st) != CHARACTER_SINGLE_QUOTE)
	{
		return (computorv2::statment_error(st));
	}
	const computorv2::Polynomial df = computorv2::drv(st->_result);
	computorv2::statment_next(st);
	computorv2::statment_skip_spaces(st);
	delete (st->_result);
	st->_result = df.clone();
	return (st->_err);
}

t_error statment_map_arguments(computorv2::statment *st, const computorv2::args_t& arguments, computorv2::args_t& values)
{
	st->_result = NULL;
	if (computorv2::statment_getc(st) != CHARACTER_LEFT_PARENTHESIS)
	{
		return (computorv2::statment_error(st));
	}
	computorv2::statment_next(st);
	const unsigned int old_pos = st->_pos;
	computorv2::statment_skip_spaces(st);
	if (computorv2::statment_getc(st) == CHARACTER_RIGHT_PARENTHESIS)
	{
		return (computorv2::statment_error(st));
	}
	std::string argname = statment_parsename(st);
	computorv2::statment_skip_spaces(st);
	if (computorv2::statment_getc(st) != CHARACTER_COLON)
	{
		if (arguments.size() != 1)
		{
			std::stringstream ss(""); ss << "arguments: ";
			for(computorv2::args_t::const_iterator it = arguments.begin(); it != arguments.end(); it++)
			{
				ss << it->first << " ";
			}
			st->_errmsg = ss.str();
			return (computorv2::statment_error(st));
		}
		st->_pos = old_pos;
		st->_err = computorv2::statment_parse_expression(st);
		if ((st->_err != 0) || (st->_result == NULL) || (computorv2::statment_getc(st) != CHARACTER_RIGHT_PARENTHESIS))
		{
			return (computorv2::statment_error(st));
		}
		computorv2::statment_next(st);
		values[arguments.begin()->first] = AS_OBJECT(st->_result);
		st->_result = NULL;
		return (st->_err);
	}
	while (1)
	{
		if ((argname == "") || (values.find(argname) != values.end()) || (computorv2::statment_getc(st) != CHARACTER_COLON))
		{
			return (computorv2::statment_error(st));
		}
		st->_result = NULL;
		computorv2::statment_next(st);
		st->_err = computorv2::statment_parse_expression(st);
		if ((st->_err != 0) || (st->_result == NULL))
		{
			return (computorv2::statment_error(st));
		}
		computorv2::statment_skip_spaces(st);
		if (computorv2::statment_getc(st) == CHARACTER_COMMA)
		{
			computorv2::statment_next(st);
			computorv2::statment_skip_spaces(st);
			if (computorv2::statment_getc(st) == CHARACTER_RIGHT_PARENTHESIS)
			{
				return (computorv2::statment_error(st));
			}
		}
		values[argname] = st->_result;
		st->_result = NULL;
		if (computorv2::statment_getc(st) == CHARACTER_RIGHT_PARENTHESIS)
		{
			computorv2::statment_next(st);
			return (st->_err);
		}
		computorv2::statment_skip_spaces(st);
		argname = statment_parsename(st);
		computorv2::statment_skip_spaces(st);
	}
	return (computorv2::statment_error(st));
}

t_error computorv2::statment_parse_function_call(computorv2::statment *st)
{
	if ((st == NULL) || (st->_result == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	if (computorv2::statment_getc(st) != CHARACTER_LEFT_PARENTHESIS)
	{
		return (computorv2::statment_error(st));
	}
	computorv2::args_t values;
	computorv2::args_t arguments;
	computorv2::variables(st->_result, arguments);
	if (arguments.size() < 1)
	{
		st->_errmsg = "'" + st->_result->toString() + "' is not callable.";
		return (computorv2::statment_error(st));
	}
	const computorv2::Object* function = AS_OBJECT(st->_result);
	try
	{
		st->_result = NULL;
		st->_err = statment_map_arguments(st, arguments, values);
		delete (st->_result);
		st->_result = NULL;
		if ((st->_err == 0) && (values.size() > 0))
		{
			st->_result = computorv2::replace(function, values);
		}
	}
	catch (const std::exception& xcp)
	{
		st->_errmsg = xcp.what();
		st->_err = computorv2::statment_error(st);
	}
	delete (function);
	for(computorv2::args_it it = values.begin(); it != values.end(); it++)
	{
		delete (it->second);
	}
	if ((st->_err != 0) || (st->_result == NULL))
	{
		return (computorv2::statment_error(st));
	}
	return (st->_err);
}

t_error computorv2::statment_parse_variable(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	st->_result      = NULL;
	std::string name = computorv2::statment_parsename(st);
	if (name == "")
	{
		return (computorv2::statment_error(st));
	}
	if (st->_vm)
	{
		st->_result = st->_vm->getLocalVariableByName(name);
		if (st->_result == NULL)
		{
			st->_result = st->_vm->getConstantByName(name);
		}
		if (st->_result == NULL)
		{
			st->_result = st->_vm->getVariableByName(name);
		}
		if (st->_result == NULL)
		{
			std::stringstream ss(""); ss << "Undefined variable: '" << name << "'";
			st->_err    = computorv2::statment_error(st);
			st->_errmsg = ss.str();
			return (st->_err);
		}
		st->_result = st->_result->clone();
	}
	else
	{
		st->_result = new computorv2::IndependentVariable(name);
	}
	computorv2::statment_skip_spaces(st);
	while (computorv2::statment_getc(st) == CHARACTER_SINGLE_QUOTE)
	{
		st->_err = computorv2::statment_parse_derivative(st);
	}
	if (computorv2::statment_getc(st) == CHARACTER_LEFT_PARENTHESIS)
	{
		st->_err = computorv2::statment_parse_function_call(st);
	}
	computorv2::statment_skip_spaces(st);
	if (IS_VARCHAR(computorv2::statment_getc(st)))
	{
		return (computorv2::statment_error(st));
	}
	return (st->_err);
}

t_error computorv2::statment_parse_object(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	st->_operation = 0;
	st->_result    = NULL;
	computorv2::statment_skip_spaces(st);
	const char c = computorv2::statment_getc(st);
	if (IS_DIGIT(c))
	{
		st->_err = computorv2::statment_parse_number(st);
	}
	else if (IS_VARSTART(c))
	{
		st->_err = computorv2::statment_parse_variable(st);
	}
	else if (c == CHARACTER_LEFT_PARENTHESIS)
	{
		computorv2::statment_next(st);
		computorv2::statment_skip_spaces(st);
		st->_err = computorv2::statment_parse_expression(st);
		if ((st->_err != 0) || (st->_result == NULL) || (computorv2::statment_getc(st) != CHARACTER_RIGHT_PARENTHESIS))
		{
			st->_err = computorv2::statment_error(st);
		}
		else
		{
			computorv2::statment_next(st);
		}
	}
	else if (c == CHARACTER_LEFT_BRACKET)
	{
		st->_err = computorv2::statment_parse_matrix(st);
	}
	if ((st->_err == 0) && (st->_result != NULL))
	{
		computorv2::statment_skip_spaces(st);
		if (computorv2::statment_getc(st) == 0)
		{
			return (st->_err);
		}
		if (IS_VARSTART(computorv2::statment_getc(st)))
		{
			/* caseOf(2i) */
			st->_operation = COMPUTORV2_OPERATION_MULT;
		}
		else
		{
			st->_operation = computorv2::statment_operation_code(st);
		}
		return (st->_err);
	}
	return (computorv2::statment_error(st));
}

t_error computorv2::statment_operation(computorv2::statment *st, const computorv2::Object* left, const computorv2::Object* right, const int operation_code)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	st->_result = NULL;
	if (operation_code & COMPUTORV2_OPERATION_ADD)
	{
		st->_result = computorv2::add(left, right);
	}
	else if (operation_code & COMPUTORV2_OPERATION_SUB)
	{
		st->_result = computorv2::sub(left, right);
	}
	else if (operation_code & COMPUTORV2_OPERATION_MULT)
	{
		st->_result = computorv2::mul(left, right);
	}
	else if (operation_code & COMPUTORV2_OPERATION_DIV)
	{
		st->_result = computorv2::div(left, right);
	}
	else if (operation_code & COMPUTORV2_OPERATION_POW)
	{
		st->_result = computorv2::pow(left, right);
	}
	else if (operation_code & COMPUTORV2_OPERATION_MATRIX_MULT)
	{
		if (!IS_MATRIX(left) || !IS_MATRIX(right))
		{
			st->_errmsg = "** Only used for term-to-term multiplication!";
			return (computorv2::statment_error(st));
		}
		st->_result = computorv2::mul(left, right);
	}
	else if (operation_code & COMPUTORV2_OPERATION_MOD)
	{
		st->_result = computorv2::mod(left, right);
	}
	else
	{
		st->_errmsg = "Unknown operation!";
		return (computorv2::statment_error(st));
	}
	return (st->_err);
}

t_error computorv2::statment_precedence(computorv2::statment *st, t_error (*perv)(computorv2::statment *st), int operations)
{
	if ((perv == NULL) || (st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	try
	{
		st->_err = perv(st);
	}
	catch (const std::exception& e)
	{
		st->_errmsg = e.what();
		st->_err    = computorv2::statment_error(st);
	}
	while ( (st->_result != NULL) && (st->_err == 0) && (st->_operation & operations) )
	{
		const int old_operation = st->_operation;
		const computorv2::Object* left = st->_result;
		st->_result = NULL;
		try
		{
			st->_err = perv(st);
		}
		catch (const std::exception& e)
		{
			delete (left);
			st->_errmsg = e.what();
			st->_err    = computorv2::statment_error(st);
		}
		if ((st->_result == NULL) || (st->_err != 0))
		{
			delete (left);
			break ;
		}
		const computorv2::Object* right = st->_result;
		st->_result = NULL;
		try
		{
			st->_err = computorv2::statment_operation(st, left, right, old_operation);
		}
		catch (const std::exception& e)
		{
			st->_errmsg = e.what();
			st->_err    = computorv2::statment_error(st);
		}
		delete (left);
		delete (right);
	}
	if ((st->_result == NULL) && (st->_err == 0))
	{
		st->_err = computorv2::statment_error(st);
	}
	return (st->_err);
}

t_error computorv2::statment_parse_negation(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	computorv2::statment_skip_spaces(st);
	if (computorv2::statment_getc(st) == CHARACTER_MINUS)
	{
		computorv2::statment_next(st);
		computorv2::statment_skip_spaces(st);
		st->_err = computorv2::statment_parse_object(st);
		if ((st->_err == 0) && (st->_result != NULL))
		{
			computorv2::Object* e = computorv2::neg(st->_result);
			delete (st->_result);
			st->_result = e;
		}
	}
	else
	{
		st->_err = computorv2::statment_parse_object(st);
	}
    return (st->_err);
}

t_error computorv2::statment_parse_exponentiation(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	st->_err = computorv2::statment_precedence(st, computorv2::statment_parse_negation, COMPUTORV2_OPERATION_POW);
    return (st->_err);
}

t_error computorv2::statment_parse_multiplicatives(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	st->_err = computorv2::statment_precedence(st,
		computorv2::statment_parse_exponentiation,
		COMPUTORV2_OPERATION_MULT | COMPUTORV2_OPERATION_DIV | COMPUTORV2_OPERATION_MOD | COMPUTORV2_OPERATION_MATRIX_MULT
	);
    return (st->_err);
}

t_error computorv2::statment_parse_additional(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	st->_err = computorv2::statment_precedence(st,
		computorv2::statment_parse_multiplicatives,
		COMPUTORV2_OPERATION_ADD | COMPUTORV2_OPERATION_SUB
	);
    return (st->_err);
}

t_error computorv2::statment_parse_expression(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	st->_err = computorv2::statment_parse_additional(st);
	return (st->_err);
}

t_error computorv2::statment_type(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	st->_type = STATMENT_TYPE_UNKNOWN;
	const std::string::size_type old_pos = st->_pos;
	computorv2::statment_skip_spaces(st);
	char c = statment_getc(st);
	if ((c == CHARACTER_EQUALS) || (c == CHARACTER_QUESTION_MARK))
	{
		return (COMPUTORV2_ERROR);
	}
	unsigned int eq = 0;
	unsigned int ex = 0;
	int in_between  = 0;
	while (!computorv2::statment_eos(st))
	{
		computorv2::statment_next(st);
		computorv2::statment_skip_spaces(st);
		if (c == CHARACTER_QUESTION_MARK)
		{
			ex++;
			if (!computorv2::statment_eos(st))
			{
				return (COMPUTORV2_ERROR);
			}
			break ;
		}
		else if (c == CHARACTER_EQUALS)
		{
			eq++;
			c = computorv2::statment_getc(st);
			if (computorv2::statment_eos(st))
			{
				return (COMPUTORV2_ERROR);
			}
			if ((c != CHARACTER_QUESTION_MARK) && (c != CHARACTER_EQUALS))
			{
				in_between = 1;
			}
		}
		if ((eq > 1) || (ex > eq))
		{
			return (COMPUTORV2_ERROR);
		}
		c = computorv2::statment_getc(st);
	}
	if ((eq == 0) && (ex == 0))
	{
		st->_pos     = old_pos;
		st->_type    = STATMENT_TYPE_GET;
		return (COMPUTORV2_SUCCESS);
	}
	else if ((eq == 1) && (ex == 0))
	{
		st->_pos = old_pos;
		st->_funcname = computorv2::statment_parsename(st);
		computorv2::statment_skip_spaces(st);
		c = statment_getc(st);
		if (c == CHARACTER_EQUALS)
		{
			computorv2::statment_next(st);
			computorv2::statment_skip_spaces(st);
			st->_type     = STATMENT_TYPE_SET_VARIABLE;
			st->_varname  = st->_funcname;
			return (COMPUTORV2_SUCCESS);
		}
		else if (c == CHARACTER_LEFT_PARENTHESIS)
		{
			computorv2::statment_next(st);
			st->_varname = computorv2::statment_parsename(st);
			computorv2::statment_skip_spaces(st);
			c = statment_getc(st);
			if ((st->_varname != "") && (c == CHARACTER_RIGHT_PARENTHESIS))
			{
				computorv2::statment_next(st);
				computorv2::statment_skip_spaces(st);
				c = statment_getc(st);
				if (c == CHARACTER_EQUALS)
				{
					computorv2::statment_next(st);
					computorv2::statment_skip_spaces(st);
					st->_type = STATMENT_TYPE_SET_FUNCTION;
					return (COMPUTORV2_SUCCESS);
				}
			}
		}
		st->_pos  = old_pos;
		st->_type = STATMENT_TYPE_SOLVE;
		return (COMPUTORV2_SUCCESS);
	}
	else if ((eq == 1) && (ex == 1))
	{
		st->_pos  = old_pos;
		st->_type = STATMENT_TYPE_GET;
		if (in_between)
		{
			st->_type = STATMENT_TYPE_SOLVE;
		}
		return (COMPUTORV2_SUCCESS);
	}
	return (COMPUTORV2_ERROR);
}

t_error computorv2::statment_assign_variable(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	const std::string varname = st->_varname;
	if ((st->_vm != NULL) && (st->_vm->getConstantByName(varname) != NULL))
	{
		st->_errmsg = "Cannot redefine constant.";
		return (computorv2::statment_error(st));
	}
	st->_err = computorv2::statment_parse_expression(st);
	computorv2::statment_skip_spaces(st);
	if (computorv2::statment_getc(st) == '=')
	{
		computorv2::statment_next(st);
		computorv2::statment_skip_spaces(st);
		if (computorv2::statment_getc(st) != '?')
		{
			return (computorv2::statment_error(st));
		}
		computorv2::statment_next(st);
		computorv2::statment_skip_spaces(st);
	}
	if ((st->_result == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	if (st->_vm)
	{
		st->_vm->setVariableByName(varname, st->_result);
	}
	return (st->_err);
}

t_error computorv2::statment_assign_function(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	const std::string funcname = st->_funcname;
	const std::string varname  = st->_varname;
	if ((st->_vm != NULL) && (st->_vm->getConstantByName(funcname) != NULL))
	{
		st->_errmsg = "Cannot redefine constant.";
		return (computorv2::statment_error(st));
	}
	const computorv2::IndependentVariable var(varname);
	if (st->_vm)
	{
		st->_vm->setLocalVariableByName(varname, &var);
	}
	st->_err = computorv2::statment_parse_expression(st);
	if (st->_vm)
	{
		st->_vm->delLocalVariableByName(varname);
	}
	if ((st->_result == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	if (st->_vm)
	{		
		st->_vm->setVariableByName(funcname, st->_result);
	}
	return (st->_err);
}

t_error computorv2::statment_solve_equation(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	st->_err = computorv2::statment_parse_additional(st);
	computorv2::statment_skip_spaces(st);
	if ((st->_err != 0) || (st->_result == NULL) || (computorv2::statment_getc(st) != '='))
	{
		return (computorv2::statment_error(st));
	}
	computorv2::statment_next(st);
	computorv2::statment_skip_spaces(st);
	const computorv2::Object* left = st->_result;
	st->_result = NULL;
	st->_err = computorv2::statment_parse_additional(st);
	computorv2::statment_skip_spaces(st);
	if ((st->_err != 0) || (st->_result == NULL))
	{
		delete (left);
		return (computorv2::statment_error(st));
	}
	if (computorv2::statment_getc(st) == '?')
	{
		computorv2::statment_next(st);
	}
	computorv2::statment_skip_spaces(st);
	if ((st->_err != 0) || (st->_result == NULL) || !computorv2::statment_eos(st))
	{
		delete (left);
		return (computorv2::statment_error(st));
	}
	const computorv2::Object* right = st->_result;
	st->_result = NULL;
	try
	{
		st->_result = computorv2::sub(left, right);
	}
	catch (const std::exception& e)
	{
		st->_errmsg = e.what();
		st->_err = computorv2::statment_error(st);
	}
	delete (left);
	delete (right);
	st->_type = STATMENT_TYPE_SOLVE;
	return (st->_err);
}

t_error computorv2::statment_parse(computorv2::statment *st)
{
	if ((st == NULL) || (st->_err != 0))
	{
		return (computorv2::statment_error(st));
	}
	computorv2::statment_skip(st, "\r\n\t\v\f ");
	computorv2::statment_type(st);
	if (st->_type == STATMENT_TYPE_GET)
	{
		st->_varname = "";
		st->_err = computorv2::statment_assign_variable(st);
	}
	else if (st->_type == STATMENT_TYPE_SET_VARIABLE)
	{
		st->_err = computorv2::statment_assign_variable(st);
	}
	else if (st->_type == STATMENT_TYPE_SET_FUNCTION)
	{
		st->_err = computorv2::statment_assign_function(st);
	}
	else if (st->_type == STATMENT_TYPE_SOLVE)
	{
		st->_err = computorv2::statment_solve_equation(st);
	}
	else
	{
		st->_err = computorv2::statment_error(st);
	}

	computorv2::statment_skip(st, "\r\n\t\v\f ");
	return (st->_err);
}

#endif//!__COMPUTORV2_SOURCES_UTILS
