# include <libc.h>

# include "../include/computorv2.h"

#include "computorv2_skip_spaces.c"
#include "computorv2_next.c"
#include "computorv2_move.c"
#include "computorv2_copy_variable.c"
// #include "computorv2_assignment.c"
#include "computorv2_getpos.c"
#include "computorv2_setpos.c"
#include "computorv2_parse_statment.c"

int computorv2_init(t_computorv2 *p2)
{
	if (p2)
	{
		
	}
	return (COMPUTORV2_SUCCESS);
}

int computorv2_fini(t_computorv2 *p2)
{
	return (COMPUTORV2_SUCCESS);
}

int computorv2_define_function(t_statment *st, const char *function_name, const char *variable_name)
{
	printf("function_name: [%s]\n", function_name);
	printf("variable_name: [%s]\n", variable_name);
	printf("function_name: [%s]\n", st->str + st->pos);
	exit(0);
	return (0);
}

int computorv2_assignment(t_statment *st)
{
	return (0);
}

int computorv2_operation(t_object **result, t_object *left, t_object *right, int operation_code)
{
	if (operation_code == COMPUTORV2_OPERATION_MULT)
	{
		if ((left->type == COMPUTORV2_TYPE_RATIONAL) && (right->type == COMPUTORV2_TYPE_RATIONAL))
		{
			*result = malloc(sizeof(t_rational));
			((t_rational*)(*result))->type  = COMPUTORV2_TYPE_RATIONAL;
			((t_rational*)(*result))->value = (((t_rational*)left)->value) * (((t_rational*)right)->value);
			return (COMPUTORV2_SUCCESS);
		}
	}
	if (operation_code == COMPUTORV2_OPERATION_MULT)
	{
		if ((left->type == COMPUTORV2_TYPE_RATIONAL) && (right->type == COMPUTORV2_TYPE_RATIONAL))
		{
			*result = malloc(sizeof(t_rational));
			((t_rational*)(*result))->type  = COMPUTORV2_TYPE_RATIONAL;
			((t_rational*)(*result))->value = (((t_rational*)left)->value) + (((t_rational*)right)->value);
			return (COMPUTORV2_SUCCESS);
		}
	}
	return (COMPUTORV2_ERROR);
}

int computorv2_parse_rational(t_computorv2 *p2, t_statment *st)
{
	computorv2_skip_spaces(st);
	if (!isdigit(computorv2_next(st)))
	{
		return (COMPUTORV2_ERROR);
	}
	t_number integer_part = 0.0;
	while (isdigit(computorv2_next(st)))
	{
		integer_part = 10 * integer_part + (computorv2_next(st) - '0');
		st->pos++;
	}
	t_number fractional_part = 0.0;
	if (computorv2_next(st) == '.')
	{
		st->pos++;
		char c = computorv2_next(st);
		if (!isdigit(c))
		{
			return (COMPUTORV2_ERROR);
		}
		t_number fraction = 0.1;
		while (isdigit(c))
		{
			fractional_part += fraction * (computorv2_next(st) - '0');
			fraction        /= 10;
			st->pos++;
			c = computorv2_next(st);
		}
	}
	st->obj = malloc(sizeof(t_rational));
	st->obj->type = COMPUTORV2_TYPE_RATIONAL;
	((t_rational*)(st->obj))->value = integer_part + fractional_part;
	return (COMPUTORV2_SUCCESS);
}

int computorv2_parse_object(t_computorv2 *p2, t_statment *st)
{
	computorv2_skip_spaces(st);
	const char c = computorv2_next(st);
	if (isdigit(c))
	{
		return (computorv2_parse_rational(p2, st));
	}
	return (0);
}

int computorv2_parse_multiplicatives(t_computorv2 *p2, t_statment *st)
{
	computorv2_parse_object(p2, st);
	while (1)
	{
		computorv2_skip_spaces(st);
		t_object *left   = st->obj;
		t_object *result = (t_object*)0;
		if ((computorv2_next_at(st, 0) == '*') && (computorv2_next_at(st, 1) == '*'))
		{
			computorv2_move(st);
			computorv2_move(st);
			computorv2_parse_object(p2, st);
		}
		else if (computorv2_next_at(st, 0) == '*')
		{
			computorv2_move(st);
			computorv2_parse_object(p2, st);
			computorv2_operation(&result, left, st->obj, COMPUTORV2_OPERATION_MULT);
			st->obj = result;
		}
		else if (computorv2_next_at(st, 0) == '/')
		{
			computorv2_move(st);
			computorv2_parse_object(p2, st);
		}
		else if (computorv2_next_at(st, 0) == '%')
		{
			computorv2_move(st);
			computorv2_parse_object(p2, st);
		}
		break ;
	}
	return (0);
}

int computorv2_parse_additional(t_computorv2 *p2, t_statment *st)
{
	computorv2_parse_multiplicatives(p2, st);
	while (1)
	{
		computorv2_skip_spaces(st);
		exit(0);
		t_object *left   = st->obj;
		t_object *result = (t_object*)0;
		if (computorv2_next_at(st, 0) == '+')
		{
			computorv2_move(st);
			computorv2_parse_multiplicatives(p2, st);
			computorv2_operation(&result, left, st->obj, COMPUTORV2_OPERATION_ADD);
			st->obj = result;
		}
		else
		{
			break ;			
		}
	}
	return (0);
}

int computorv2_parse_expression(t_computorv2 *p2, t_statment *st)
{
	computorv2_parse_additional(p2, st);

	t_number res = ((t_rational*)(st->obj))->value;

	printf("%.10f\n", res);

	exit(0);
	return (0);
}

int main(int argc, char const *argv[])
{
	t_computorv2 p2;
	if (computorv2_init(&p2) != COMPUTORV2_SUCCESS)
	{
		return (computorv2_fini(&p2));
	}
	t_statment st;

	st.pos = 0;
	st.str = "2 * 4 + 1";
	st.len = strlen(st.str);


	computorv2_parse_expression(&p2, &st);


	st.pos = 0;
	st.str = "funB(x)  + 1= 2 * 4 + x";
	st.str = "   funA( x )    = 2 * 4 + x";
	st.len = strlen(st.str);



	computorv2_parse_statment(&st);
	printf("- - - - - - - - - \n");
	st.pos = 0;
	st.str = "funF(x) = 2 * 4 + x";
	st.len = 19;
	computorv2_parse_statment(&st);
	return 0;
}



/*

https://github.com/<name>
https://gitlab.com/<name>
https://www.linkedin.com/in/<name>
https://<name>.com



*/




















