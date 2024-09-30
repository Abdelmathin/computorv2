#include "../include/utils.hpp"
#include "../include/Object.hpp"
#include "../include/Function.hpp"
#include "../include/IndependentVariable.hpp"
#include <iostream>

t_error computorv2::statment_init(computorv2::statment *st)
{
	if (st)
	{
		st->_pos       = 0     ;
		st->_str       = ""    ;
		st->_len       = 0     ;
		st->_err       = 0     ;
		st->_type      = 0     ;
		st->_operation = 0     ;
		st->_varname   = ""    ;
		st->_result    = NULL  ;
		st->_vm        = NULL  ;
		return (COMPUTORV2_SUCCESS);
	}
	return (COMPUTORV2_ERROR);
}

int computorv2::statment_operation_code(computorv2::statment *st)
{
	if (!st)
	{
		return (COMPUTORV2_OPERATION_NONE);
	}
	computorv2::statment_skip_spaces(st);
	char c = computorv2::statment_getc(st);
	if (c == '+')
	{
		computorv2::statment_next(st);
		return (COMPUTORV2_OPERATION_ADD);
	}
	else if (c == '-')
	{
		computorv2::statment_next(st);
		return (COMPUTORV2_OPERATION_SUB);		
	}
	else if (c == '*')
	{
		c = computorv2::statment_next(st);
		if (c == '*')
		{
			return (COMPUTORV2_OPERATION_MATRIX_MULT);
		}
		return (COMPUTORV2_OPERATION_MULT);		
	}
	else if (c == '/')
	{
		computorv2::statment_next(st);
		return (COMPUTORV2_OPERATION_DIV);		
	}
	else if (c == '%')
	{
		computorv2::statment_next(st);
		return (COMPUTORV2_OPERATION_MOD);		
	}
	else if (c == '^')
	{
		computorv2::statment_next(st);
		return (COMPUTORV2_OPERATION_EXP);		
	}
	return (COMPUTORV2_OPERATION_NONE);
}

t_error computorv2::statment_skip_spaces(computorv2::statment *st)
{
	if (st)
	{
		while (st->_pos < st->_len)
		{
			if (!ISSPACE(st->_str[st->_pos]))
			{
				return (COMPUTORV2_SUCCESS);
			}
			st->_pos += 1;
		}
		return (COMPUTORV2_SUCCESS);
	}
	return (COMPUTORV2_ERROR);
}

t_error computorv2::statment_skip(computorv2::statment *st, const std::string charset)
{
	if (st)
	{
		while (st->_pos < st->_len)
		{
			const char c = st->_str[st->_pos];
			if (c == '\0')
			{
				return (COMPUTORV2_SUCCESS);
			}
			int found = 0;
			for (std::string::size_type k = 0; k < charset.size(); k++)
			{
				if (charset[k] == c)
				{
					found = 1;
					break ;
				}
			}
			if (!found)
			{
				return (COMPUTORV2_SUCCESS);
			}
			st->_pos += 1;
		}
		return (COMPUTORV2_SUCCESS);
	}
	return (COMPUTORV2_ERROR);
}

char computorv2::statment_getc(const computorv2::statment *st)
{
	if (st)
	{
		if (st->_pos < st->_len)
		{
			return (st->_str[st->_pos]);
		}
	}
	return (0);
}

char computorv2::statment_next(computorv2::statment *st)
{
	if (st)
	{
		if (st->_pos < st->_len)
		{
			st->_pos += 1;
		}		
		if (st->_pos < st->_len)
		{
			return (st->_str[st->_pos]);
		}
	}
	return (0);
}

bool computorv2::statment_eos(const computorv2::statment *st)
{
	if (st)
	{
		const char c = statment_getc(st);
		if ((c == '\r') || (c == '\n') || (c == '\0'))
		{
			return (true);
		}
		return (false);
	}
	return (true);
}

std::string computorv2::statment_parsename(computorv2::statment *st)
{
	if (st)
	{
		computorv2::statment_skip_spaces(st);
		char c = computorv2::statment_getc(st);
		if (ISVARSTART(c))
		{
			std::string name = "";
			while (IS_VAR_CHAR(c))
			{
				name += c;
				c = computorv2::statment_next(st);
			}
			return (name);
		}
	}
	return ("");
}

t_error computorv2::statment_parse_number(computorv2::statment *st)
{
	char c = computorv2::statment_getc(st);
	if (ISDIGIT(c) == 0)
	{
		return (COMPUTORV2_ERROR);
	}
	st->_result = NULL;
	double r = 0.0;
	while (ISDIGIT(c))
	{
		r = 10 * r + (CHARCODE(c) - CHARCODE('0'));
		c = computorv2::statment_next(st);
	}
	if (c != '.')
	{
		st->_result = new computorv2::Rational(r);
		return (COMPUTORV2_SUCCESS);
	}
	c = computorv2::statment_next(st);
	double f = 0.1;
	while (ISDIGIT(c))
	{
		r = r + f * (CHARCODE(c) - CHARCODE('0'));
		c = computorv2::statment_next(st);
		f = f / 10.0;		
	}
	st->_result = new computorv2::Rational(r);
	return (0);
}

t_error computorv2::statment_parse_variable(computorv2::statment *st)
{
	st->_result = NULL;
	std::string name = "";
	while (IS_VAR_CHAR(computorv2::statment_getc(st)))
	{
		name += computorv2::statment_getc(st);
		computorv2::statment_next(st);
	}
	if (st->_vm)
	{
		st->_result = st->_vm->getVariableByName(name);
		if (st->_result)
		{
			return (COMPUTORV2_SUCCESS);
		}
	}
	return (COMPUTORV2_ERROR);
}

t_error computorv2::statment_parse_object(computorv2::statment *st)
{
	if (!st)
	{
		return (COMPUTORV2_ERROR);
	}
	st->_operation = 0;
	st->_result    = 0;
	computorv2::statment_skip_spaces(st);
	const char c = computorv2::statment_getc(st);
	if (ISDIGIT(c))
	{
		st->_err = computorv2::statment_parse_number(st);
	}
	else if (ISVARSTART(c))
	{
		st->_err = computorv2::statment_parse_variable(st);
	}
	if (st->_err == 0)
	{
		computorv2::statment_skip_spaces(st);
		if (computorv2::statment_getc(st) == 0)
		{
			return (COMPUTORV2_SUCCESS);
		}
		st->_operation = computorv2::statment_operation_code(st);
		if (ISVARSTART(computorv2::statment_getc(st)))
		{
			/* caseOf(2i) */
			st->_operation = COMPUTORV2_OPERATION_MULT;			
		}
	}
	return (st->_err);
}

t_error computorv2::statment_operation(computorv2::statment *st, const computorv2::Object* left, const computorv2::Object* right, const int operation_code)
{
	st->_result = NULL;
	if (operation_code == COMPUTORV2_OPERATION_ADD)
	{
		if (ISRATIONAL(left) and ISRATIONAL(right))
		{
			const computorv2::Rational* rleft  = static_cast<const computorv2::Rational*>(left);
			const computorv2::Rational* rright = static_cast<const computorv2::Rational*>(right);
			st->_result = new computorv2::Rational(rleft->getValue() + rright->getValue());
			return (COMPUTORV2_SUCCESS);
		}
	}
	else if (operation_code == COMPUTORV2_OPERATION_SUB)
	{
		if (ISRATIONAL(left) and ISRATIONAL(right))
		{
			const computorv2::Rational* rleft  = static_cast<const computorv2::Rational*>(left);
			const computorv2::Rational* rright = static_cast<const computorv2::Rational*>(right);
			st->_result = new computorv2::Rational(rleft->getValue() - rright->getValue());
			return (COMPUTORV2_SUCCESS);
		}
	}
	else if (operation_code == COMPUTORV2_OPERATION_MULT)
	{
		if (ISRATIONAL(left) and ISRATIONAL(right))
		{
			const computorv2::Rational* rleft  = static_cast<const computorv2::Rational*>(left);
			const computorv2::Rational* rright = static_cast<const computorv2::Rational*>(right);
			st->_result = new computorv2::Rational(rleft->getValue() * rright->getValue());
			return (COMPUTORV2_SUCCESS);
		}
	}
	else if (operation_code == COMPUTORV2_OPERATION_DIV)
	{
		if (ISRATIONAL(left) and ISRATIONAL(right))
		{
			const computorv2::Rational* rleft  = static_cast<const computorv2::Rational*>(left);
			const computorv2::Rational* rright = static_cast<const computorv2::Rational*>(right);
			if (rright->getValue() == 0.0)
			{
				throw "Zero Division Error!";
			}
			st->_result = new computorv2::Rational(rleft->getValue() / rright->getValue());
			return (COMPUTORV2_SUCCESS);
		}
	}
	throw "Unknown operation!";
	return (COMPUTORV2_SUCCESS);
}

t_error computorv2::statment_precedence(computorv2::statment *st, t_error (*perv)(computorv2::statment *st), int operations)
{
	if (!st || !perv)
	{
		return (COMPUTORV2_ERROR);
	}
	perv(st);
	while ((st->_err == 0) && ((operations & st->_operation) != 0))
	{
		const int old_operation   = st->_operation;
		const computorv2::Object* left  = st->_result;
		st->_result               = NULL;
		perv(st);
		const computorv2::Object* right = st->_result;
		st->_result               = NULL;
		st->_err                  =  computorv2::statment_operation(st, left, right, old_operation);
		if (left)
		{
			delete (left);
		}
		if (right)
		{
			delete (right);
		}
	}
	return (st->_err);
}

t_error computorv2::statment_parse_exponentiation(computorv2::statment *st)
{
	t_error err = computorv2::statment_precedence(st, computorv2::statment_parse_object, COMPUTORV2_OPERATION_NONE);
    return (err);
}

t_error computorv2::statment_parse_multiplicatives(computorv2::statment *st)
{
	t_error err = computorv2::statment_precedence(st, computorv2::statment_parse_exponentiation, COMPUTORV2_OPERATION_EXP);
    return (err);
}

t_error computorv2::statment_parse_additional(computorv2::statment *st)
{
	t_error err = computorv2::statment_precedence(st, computorv2::statment_parse_multiplicatives, COMPUTORV2_OPERATION_MULT | COMPUTORV2_OPERATION_DIV | COMPUTORV2_OPERATION_MOD | COMPUTORV2_OPERATION_MATRIX_MULT);
    return (err);
}

t_error computorv2::statment_type(computorv2::statment *st)
{
	if (!st)
	{
		return (COMPUTORV2_ERROR);
	}
	st->_type = STATMENT_TYPE_UNKNOWN;
	const std::string::size_type old_pos = st->_pos;
	computorv2::statment_skip_spaces(st);
	char c = statment_getc(st);
	if ((c == '=') || (c == '?'))
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
		if (c == '?')
		{
			ex++;
			if (!computorv2::statment_eos(st))
			{
				return (COMPUTORV2_ERROR);
			}
			break ;
		}
		else if (c == '=')
		{
			eq++;
			c = computorv2::statment_getc(st);
			if (computorv2::statment_eos(st))
			{
				return (COMPUTORV2_ERROR);
			}
			if ((c != '?') && (c != '='))
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
		if (c == '=')
		{
			computorv2::statment_next(st);
			computorv2::statment_skip_spaces(st);
			st->_type     = STATMENT_TYPE_SET_VARIABLE;
			st->_varname  = st->_funcname;
			return (COMPUTORV2_SUCCESS);
		}
		else if (c == '(')
		{
			computorv2::statment_next(st);
			st->_varname = computorv2::statment_parsename(st);
			computorv2::statment_skip_spaces(st);
			c = statment_getc(st);
			if ((st->_varname != "") && (c == ')'))
			{
				computorv2::statment_next(st);
				computorv2::statment_skip_spaces(st);
				c = statment_getc(st);
				if (c == '=')
				{
					computorv2::statment_next(st);
					computorv2::statment_skip_spaces(st);
					st->_type = STATMENT_TYPE_SET_FUNCTION;
					return (COMPUTORV2_SUCCESS);
				}
			}
		}
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

t_error computorv2::statment_assign(computorv2::statment *st)
{
	return (COMPUTORV2_SUCCESS);
}

t_error computorv2::statment_parse(computorv2::statment *st)
{
	computorv2::statment_type(st);
	std::cout << "type: " << st->_type << std::endl;
	exit(0);



	/*
		varA = 2        (0)
		varA = ?        (0)
		varA + varB = 2 (1)
	*/
	if (!st)
	{
		return (COMPUTORV2_ERROR);
	}
	while (1)
	{
		st->_type = 0;
		computorv2::statment_skip(st, "\r\n\t\v\f ");
		const std::string::size_type old_pos = st->_pos;
		std::string varname = "";
		char c = computorv2::statment_getc(st);
		if (ISVARSTART(c))
		{
			while (IS_VAR_CHAR(c))
			{
				varname += c;
				c = computorv2::statment_next(st);
			}
			computorv2::statment_skip_spaces(st);
			c = computorv2::statment_getc(st);
			if (c == '(')
			{
				/* function(x) */
				computorv2::statment_next(st);
				computorv2::statment_skip_spaces(st);
				c = computorv2::statment_getc(st);
				if (ISVARSTART(c))
				{
					std::string independent_variable = "";
					while (IS_VAR_CHAR(c))
					{
						independent_variable += c;
						c = computorv2::statment_next(st);
					}
					computorv2::statment_skip_spaces(st);
					c = computorv2::statment_getc(st);
					if (c == ')')
					{
						computorv2::statment_next(st);
						computorv2::statment_skip_spaces(st);
						c = computorv2::statment_getc(st);
						if (c == '=')
						{
							computorv2::statment_next(st);
							computorv2::statment_skip_spaces(st);
							c = computorv2::statment_getc(st);
							if (c == '?')
							{
								std::cout << "evaluate f(x) " << varname << std::endl;
								exit(0);
							}
							else
							{
								if (st->_vm)
								{
									computorv2::Object* v = new computorv2::IndependentVariable();
									v->setName(independent_variable);
									st->_vm->setIndependentVariable(v);
								}
								t_error err = computorv2::statment_precedence(st, computorv2::statment_parse_additional, COMPUTORV2_OPERATION_ADD | COMPUTORV2_OPERATION_SUB);
								if (st->_result)
								{
									computorv2::Function* f = new computorv2::Function();
									f->setName(varname);
									f->setBody(st->_result->toString());
									f->setIndependentVariable(independent_variable);
									if (st->_vm)
									{
										st->_vm->setVariableByName(varname, f);
									}
									delete (st->_result);
									st->_result = f;
								}
								else
								{
									throw "// error";
								}
								if (st->_vm)
								{
									computorv2::Object* v = st->_vm->getIndependentVariable();
									st->_vm->setIndependentVariable(NULL);
									delete (v);
								}
								c = computorv2::statment_getc(st);
								if (c == '\n')
								{
									continue ;
								}
								return (COMPUTORV2_ERROR);
							}
						}
					}
					st->_pos  = old_pos;
					st->_type = STATMENT_TYPE_GET;
					return (COMPUTORV2_SUCCESS);
				}
				std::cout << ">>>> " << computorv2::statment_getc(st) << std::endl;
				exit(0);
			}
			else if (c == '=')
			{
				computorv2::statment_next(st);
				computorv2::statment_skip_spaces(st);
				c = computorv2::statment_getc(st);
				if (c == '?')
				{
					std::cout << "get value of: " << varname << std::endl;
					exit(0);
				}
				else
				{
					t_error err = computorv2::statment_precedence(st, computorv2::statment_parse_additional, COMPUTORV2_OPERATION_ADD | COMPUTORV2_OPERATION_SUB);
					if (err != COMPUTORV2_SUCCESS)
					{
						return (err);
					}
					if (st->_vm)
					{
						st->_vm->setVariableByName(varname, st->_result);
					}
					c = computorv2::statment_getc(st);
					if (c == '\n')
					{
						continue ;
					}
					return (COMPUTORV2_ERROR);
				}
			}
		}
		st->_pos  = old_pos;
		st->_type = STATMENT_TYPE_GET;
		return (COMPUTORV2_SUCCESS);
	}



	// while (1)
	// {
	// 	computorv2::statment_type(st);
	// 	t_error err = computorv2::statment_precedence(st, computorv2::statment_parse_additional, COMPUTORV2_OPERATION_ADD | COMPUTORV2_OPERATION_SUB);
	// 	if (err != COMPUTORV2_SUCCESS)
	// 	{
	// 		return (err);
	// 	}
	// 	if (computorv2::statment_getc(st) != '\n')
	// 	{
	// 		return (err);
	// 	}
	// 	computorv2::statment_next(st);
	// }
	return (COMPUTORV2_SUCCESS);
}
