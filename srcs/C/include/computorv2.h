#ifndef COMPUTORV2_H
# define COMPUTORV2_H
# include <ctype.h>

/*
	* :
		number * number
		number * matrix
	/
	+
	-
	%
	** : matrix ** matrix
	^ : power
	()
	 = ?
*/

# define COMPUTORV2_SUCCESS          0
# define COMPUTORV2_ERROR            1
# define COMPUTORV2_MAX_VARLEN       1024
# define COMPUTORV2_OBJECT_INTERFACE struct s_object *next; char *name; int type

typedef double t_number;
typedef struct s_object t_object;

typedef struct s_computorv2
{
	t_object *obj;
}	t_computorv2;

typedef struct s_statment
{
	int  pos;
	char *str;
	int  len;
	char *var;
}	t_statment;

typedef struct s_object
{
	COMPUTORV2_OBJECT_INTERFACE;
}	t_object;

typedef struct s_rational
{
	COMPUTORV2_OBJECT_INTERFACE;
	t_number value;
}	t_rational;

typedef struct s_complex
{
	COMPUTORV2_OBJECT_INTERFACE;
	t_rational real;
	t_rational imag;
}	t_complex;

typedef struct s_vector
{
	COMPUTORV2_OBJECT_INTERFACE;
	t_complex *numbers;
	int       dimension;
}	t_vector;

typedef struct s_matrix
{
	COMPUTORV2_OBJECT_INTERFACE;
	t_complex *rows;
	t_complex *columns;
	int       nrows;
	int       ncolumns;
}	t_matrix;

typedef struct s_function
{
	COMPUTORV2_OBJECT_INTERFACE;
	char *variable;
}	t_function;

int computorv2_assignment(t_statment *st);
int computorv2_define_function(t_statment *st, const char *function_name, const char *variable_name);

#endif//COMPUTORV2_H