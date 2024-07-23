# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>

# define COMPUTORV2_SUCCESS          0
# define COMPUTORV2_ERROR            1

# define COMPUTORV2_MAX_VARLEN       1024

# define ERROR_NOT_ENOUGH_MEMORY 1
# define ERROR_NAN               2

# define COMPUTORV2_OPERATION_MULT           (1 << 0)
# define COMPUTORV2_OPERATION_ADD            (1 << 1)
# define COMPUTORV2_OPERATION_SUB            (1 << 2)
# define COMPUTORV2_OPERATION_EXPONENTIATION (1 << 3)

# define COMPUTORV2_TYPE_INTEGER    1
# define COMPUTORV2_TYPE_RATIONAL   2

# define COMPUTORV2_OBJECT_INTERFACE struct s_object *next; char *name; int type
# define RATIONAL2NUMBER(o) (((t_rational*)o)->value)
# define ISRATIONAL(o) ((o) && (o->type & COMPUTORV2_TYPE_RATIONAL))

typedef struct s_computorv2
{

} t_computorv2;

typedef int t_error;

typedef struct s_object t_object;

typedef struct s_object
{
    COMPUTORV2_OBJECT_INTERFACE;
}   t_object;

typedef struct s_rational
{
    COMPUTORV2_OBJECT_INTERFACE;
    double value;
}   t_rational;

typedef struct s_complex
{
    COMPUTORV2_OBJECT_INTERFACE;
    t_rational real;
    t_rational imag;
}   t_complex;

typedef struct s_vector
{
    COMPUTORV2_OBJECT_INTERFACE;
    t_complex *numbers;
    int       dimension;
}   t_vector;

typedef struct s_matrix
{
    COMPUTORV2_OBJECT_INTERFACE;
    t_complex *numbers;
    int       ncolumns;
    int       nrows;
}   t_matrix;

typedef struct s_function
{
    COMPUTORV2_OBJECT_INTERFACE;
    char *variable;
}   t_function;

typedef struct s_statment
{
    unsigned int pos;
    char         *str;
    unsigned int len;
    int          err;
    int          operation;
    char         *var;
    t_object     *result;
    t_computorv2 *vm;
}	t_statment;

int computorv2_init(t_computorv2 *vm)
{
	if (vm)
	{
		
	}
	return (COMPUTORV2_SUCCESS);
}

int computorv2_fini(t_computorv2 *vm)
{
	if (vm)
	{

	}
	return (COMPUTORV2_SUCCESS);
}

int computorv2_print(t_object *obj)
{
    if (!obj)
    {
        return (1);
    }
    if (ISRATIONAL(obj))
    {
        printf("%.15f\n", RATIONAL2NUMBER(obj));
    }
    return (0);
}

int computorv2_init_statment(t_statment *st)
{
    if (st)
    {
        st->pos       = 0;
        st->str       = (void *)0;
        st->len       = 0;
        st->err       = 0;
        st->operation = 0;
        st->var       = (void *)0;
        st->result    = (void *)0;
        st->vm        = (void *)0;
        return (0);
    }
    return (1);
}

int computorv2_skip_spaces(t_statment *st)
{
    if (st->str)
    {
        while ((st->pos < st->len) && isspace(st->str[st->pos]))
        {
            st->pos++;
        }
    }
    return (COMPUTORV2_SUCCESS);
}

char computorv2_getc(t_statment *st)
{
    if ((st && st->str) && (st->pos < st->len))
    {
        return (st->str[st->pos]);
    }
    return (0);
}

char computorv2_getc_at(t_statment *st, int at)
{
    if ((st && st->str) && (0 <= st->pos + at) && (st->pos + at < st->len))
    {
        return (st->str[st->pos + at]);
    }
    return (0);
}

char computorv2_next(t_statment *st)
{
    if (st && (st->pos < st->len))
    {
        st->pos++;
    }
    if (st->str)
    {
        return (st->str[st->pos]);
    }
    return (0);
}

t_rational *computorv2_new_rational(double value)
{
    t_rational *r = malloc(sizeof(t_rational));
    if (r)
    {
        r->next  = (void *)0;
        r->name  = (void *)0;
        r->type  = COMPUTORV2_TYPE_RATIONAL;
        r->value = value;
    }
    return (r);
}

int computorv2_operation(t_object **result, const t_object *left, const t_object *right, int operation_code)
{
    if (!left || !right)
    {
        return (1);
    }
    if (operation_code == COMPUTORV2_OPERATION_ADD)
    {
        if (ISRATIONAL(left) && ISRATIONAL(right))
        {
            *result = (t_object *) computorv2_new_rational(RATIONAL2NUMBER(left) + RATIONAL2NUMBER(right));
            return (0);
        }
    }
    else if (operation_code == COMPUTORV2_OPERATION_SUB)
    {
        if (ISRATIONAL(left) && ISRATIONAL(right))
        {
            *result = (t_object *) computorv2_new_rational(RATIONAL2NUMBER(left) - RATIONAL2NUMBER(right));
            return (0);
        }
    }
    else if (operation_code == COMPUTORV2_OPERATION_MULT)
    {
        if (ISRATIONAL(left) && ISRATIONAL(right))
        {
            *result = (t_object *) computorv2_new_rational(RATIONAL2NUMBER(left) * RATIONAL2NUMBER(right));
            return (0);
        }
    }
    printf("\n\n\n\nEOS\n\ncomputorv2_operation(%p, %p, %i)", left, right, operation_code);
    exit(0);
    return (1);
}

int computorv2_parse_matrix(t_statment *st)
{
    computorv2_skip_spaces(st);
    char c = computorv2_getc(st);
    if (c != '[')
    {
        st->result = (void *)0;
        return (1);
    }
    computorv2_next(st);
    computorv2_skip_spaces(st);
    c = computorv2_getc(st);
    if (c != '[')
    {
        // vector: [1, 2, 3]
    }
    printf("c = [%c]\n", c);
    exit(0);
    return (0);
}

int computorv2_parse_number(t_statment *st)
{
    char c = computorv2_getc(st);
    if ((c < '0') || (c > '9'))
    {
        st->result = (void *)0;
        return (1);
    }
    t_rational *r = computorv2_new_rational(0);
    if (!r)
    {
        st->err = ERROR_NOT_ENOUGH_MEMORY;
        st->result = (void *)0;
        return (1); 
    }
    while (('0' <= c) && (c <= '9'))
    {
        r->value = 10 * r->value + (c - '0');
        c = computorv2_next(st);
    }
    if (c != '.')
    {
        r->type |= COMPUTORV2_TYPE_INTEGER;
        st->result  = (void *) r;
        return (0);
    }
    c = computorv2_next(st);
    if ((c < '0') || (c > '9'))
    {
        free(r);
        st->err = ERROR_NAN;
        st->result = (void *)0;
        return (1);
    }
    double ratio = 1.0;
    while (('0' <= c) && (c <= '9'))
    {
        ratio /= 10;
        r->value = r->value + ratio * (c - '0');
        c = computorv2_next(st);
    }
    st->result = (void *) r;
    return (0);
}
int computorv2_del_object(t_object *obj)
{
    return (0);
}

int computorv2_operation_code(t_statment *st)
{
    computorv2_skip_spaces(st);
    const char c = computorv2_getc(st);
    const char z = computorv2_next(st);
    switch (c)
    {
        case '+':
            return (COMPUTORV2_OPERATION_ADD);
        case '-':
            return (COMPUTORV2_OPERATION_SUB);
        case '*':
            return (COMPUTORV2_OPERATION_MULT);
    }
    return (0);
}

/* [START] statment [START] */

t_error computorv2_parse_object(t_statment *st)
{
    st->operation = 0;
    computorv2_skip_spaces(st);
    const char c = computorv2_getc(st);
    if (('0' <= c) && (c <= '9'))
    {
        st->err = computorv2_parse_number(st);
    }
    else
    {
        printf("\n\n\n\n>>>>>> invalid object!\n");
        exit(0);
    }
    if (!st->err)
    {
        st->operation = computorv2_operation_code(st);        
        printf("st->operation = %i\n", st->operation);
    }
    return (st->err);
}

t_error computorv2_precedence(t_statment *st, t_error (*perv)(t_statment *st))
{
    perv(st);
    while (!st->err)
    {
        const int operation = st->operation;
        if (!operation)
        {
            return (st->err);
        }
        t_object *left   = (t_object *) st->result;
        st->result       = (t_object *) 0;
        perv(st);
        t_object *right  = (t_object *) st->result;
        st->result       = (t_object *) 0;
        st->err          = computorv2_operation(&(st->result), left, right, operation);
        computorv2_del_object(left);
        computorv2_del_object(right);
    }
    return (st->err);
}

t_error computorv2_parse_exponentiation(t_statment *st)
{
    return (computorv2_precedence(st, computorv2_parse_object));
}

t_error computorv2_parse_multiplicatives(t_statment *st)
{
    return (computorv2_precedence(st, computorv2_parse_exponentiation));
}

t_error computorv2_parse_additional(t_statment *st)
{
    return (computorv2_precedence(st, computorv2_parse_multiplicatives));
}

t_error computorv2_parse_statment(t_statment *st)
{
    computorv2_parse_additional(st);
    return (st->err);
}

/* [STOP] statment [STOP] */

int main(int argc, char **argv)
{
	t_computorv2 vm;
    t_statment   st;
	if (computorv2_init(&vm) != 0)
	{
		return (computorv2_fini(&vm));
	}
    computorv2_init_statment(&st);

    st.pos = 0;
    st.str = "  4 * 5 + 2 ";
    st.len = -1;
    st.vm  = &vm;

    computorv2_parse_statment(&st);

    computorv2_print(st.result);
	return (0);
}
