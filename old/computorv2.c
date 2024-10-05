# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define COMPUTORV2_MAX_VARLEN       1024
# define COMPUTORV2_BUFFER_SIZE      1024

# define COMPUTORV2_SUCCESS          (0 << 0)
# define COMPUTORV2_ERROR            (1 << 0)

# define ERROR_NOT_ENOUGH_MEMORY     (1 << 0)
# define ERROR_NAN                   (1 << 1)

# define STATMENT_TYPE_GET           (1 << 0)
# define STATMENT_TYPE_SET           (1 << 1)
# define STATMENT_TYPE_SOLVE         (1 << 2)

# define COMPUTORV2_OPERATION_ADD    (1 << 0)
# define COMPUTORV2_OPERATION_SUB    (1 << 1)
# define COMPUTORV2_OPERATION_MULT   (1 << 2)
# define COMPUTORV2_OPERATION_DIV    (1 << 3)
# define COMPUTORV2_OPERATION_EXP    (1 << 4)

# define COMPUTORV2_TYPE_INTEGER     (1 << 0)
# define COMPUTORV2_TYPE_RATIONAL    (1 << 1)

# define COMPUTORV2_OBJECT_INTERFACE struct s_object *next; char *name; int type
# define RATIONAL2NUMBER(o)          (((t_rational*)o)->value)
# define ISRATIONAL(o)               ((o) && (o->type & COMPUTORV2_TYPE_RATIONAL))

typedef int t_error;

// static t_irrational PI;
// static t_irrational E;
// static t_irrational PHI;
// static t_complex    i;

typedef struct s_object t_object;

typedef struct s_buffer
{
    struct s_buffer *next;
    char            *str;
    unsigned int    len;
}   t_buffer;

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

typedef struct s_computorv2
{
    t_object     *variables;
} t_computorv2;

typedef struct s_statment
{
    unsigned int pos;
    char         *str;
    unsigned int len;
    int          err;
    int          type;
    int          operation;
    char         *function_name;
    char         *variable_name;
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
        st->pos           = 0;
        st->str           = (void *)0;
        st->len           = 0;
        st->err           = 0;
        st->operation     = 0;
        st->result        = (void *)0;
        st->function_name = (char *)0;
        st->variable_name = (char *)0;
        st->vm            = (void *)0;
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
    else if (operation_code == COMPUTORV2_OPERATION_EXP)
    {
        if (ISRATIONAL(left) && ISRATIONAL(right))
        {
            *result = (t_object *) computorv2_new_rational(exp(RATIONAL2NUMBER(right) * log(RATIONAL2NUMBER(left))));
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
    if (!c)
    {
        return (0);
    }
    switch (c)
    {
        case '+':
            return (COMPUTORV2_OPERATION_ADD);
        case '-':
            return (COMPUTORV2_OPERATION_SUB);
        case '*':
            return (COMPUTORV2_OPERATION_MULT);
        case '/':
            return (COMPUTORV2_OPERATION_DIV);
        case '^':
            return (COMPUTORV2_OPERATION_EXP);
    }
    printf("operation_code ======> %c\n", c);
    return (0);
}

# define ISDIGIT(c)  (('0' <= c) && (c <= '9'))
# define VARSTART(c) ((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')) || (c == '_'))
# define VARCHAR(c)  (VARSTART(c) || ISDIGIT(c))

t_error computorv2_parse_variable(t_statment *st)
{
    char c = computorv2_getc(st);
    char variable_name[COMPUTORV2_MAX_VARLEN];
    unsigned int i = 0;
    while ((i < COMPUTORV2_MAX_VARLEN) && (VARCHAR(c)))
    {
        variable_name[i] = c;
        c = computorv2_next(st);
        i++;
    }
    variable_name[i] = 0;
    printf("variable_name = %s\n", variable_name);
    exit(0);
    return (st->err);
}

/* [START] statment [START] */

t_error computorv2_parse_object(t_statment *st)
{
    st->operation = 0;
    computorv2_skip_spaces(st);
    const char c = computorv2_getc(st);
    if (VARSTART(c))
    {
        st->err = computorv2_parse_variable(st);
    }
    else if (ISDIGIT(c))
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
        computorv2_skip_spaces(st);        
        if (VARSTART(computorv2_getc(st)))
        {
            /* caseOf(2i) */
            st->operation = COMPUTORV2_OPERATION_MULT;
        }
        else
        {
            st->operation = computorv2_operation_code(st);
        }
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
    printf("st->type = %i\n", st->type);
    printf("[");
    while ((st->pos < st->len) && (st->str[st->pos]))
    {
        printf("%c", st->str[st->pos]);
        st->pos++;
    }
    printf("]\n");
    exit(0);
    computorv2_parse_additional(st);
    return (st->err);
}

t_error computorv2_parse_line(t_statment *st)
{
    const unsigned int oldlen = st->len;
    int equals = 0;
    unsigned int pos = st->pos;
    while ((pos < st->len) && (st->str[pos] != '\0'))
    {
        if (st->str[pos] == '=')
        {
            equals++;
        }
        pos++;
    }
    if (equals < 1)
    {
        st->type = STATMENT_TYPE_GET;
        return (computorv2_parse_statment(st));
    }
    while ((pos > st->pos) && ((pos == st->len) || isspace(st->str[pos]) || (st->str[pos] == '\0')))
    {
        pos--;
    }
    if (st->str[pos] == '=')
    {
        st->len = pos;
        st->type = STATMENT_TYPE_GET;
        computorv2_parse_statment(st);
        st->len = oldlen;
        return (st->err);
    }
    st->type = STATMENT_TYPE_SET;
    if (st->str[pos] == '?')
    {
        pos--;
        while ((pos > st->pos) && (isspace(st->str[pos])))
        {
            pos--;
        }
        if (st->str[pos] == '=')
        {
            st->len  = pos;
            st->type = STATMENT_TYPE_GET;
        }
        else
        {
            st->len  = pos + 1;
            st->type = STATMENT_TYPE_SOLVE;
        }
    }
    computorv2_parse_statment(st);
    st->len = oldlen;
    return (st->err);
}

/* [STOP] statment [STOP] */
// ⁰¹²³⁴⁵⁶⁷⁸⁹
/*

    PGCD

    - set: variable / function:
        - varA = 2
        - funA(x) = 2*x^5 + 4x^2 - 5*x + 4
    - get: variable / function:
        a + 2
        a + 2 =
        a + 2 = ?
        funC(3) = ?
    - solve equation:
        funA(x) = 0 ?
        funA(x) = 3 + i ?
    ./computor "1 / 3" --precision=15
*/

int main(int argc, char **argv)
{
	t_computorv2 vm;
    t_statment   st;
	if (computorv2_init(&vm) != 0)
	{
		return (computorv2_fini(&vm));
	}
    computorv2_init_statment(&st);

    /*
        PI
        E
        i
    */


    st.pos = 0;
    st.str = "  aaaaaaaaaaaaaaaaaaaa0123456789 = 1 + 2 + 3 + 4 + 5 + 6 ";
    st.len = -1;
    st.vm  = &vm;

    computorv2_parse_line(&st);

    computorv2_print(st.result);
	return (0);
}

/*
------------------------------------------------------





computorv2::Complex::Complex(void)
{
    this->clear();
}

computorv2::Complex::~Complex(void)
{
    this->clear();
}

computorv2::Complex::Complex(const computorv2::Complex& other)
{
    *this = other;
}

computorv2::Complex& computorv2::Complex::operator=(const computorv2::Complex& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_real = other._real;
        this->_imag = other._imag;
    }
    return (*this);
}

computorv2::Complex::Complex(double real, double image)
{
    this->clear();
    this->setReal(real);
    this->setImage(image);
}

std::string computorv2::Complex::getName(void) const
{
    return (this->_name);
}

double computorv2::Complex::getReal(void)  const
{
    return (this->_real);
}

double computorv2::Complex::getImage(void) const
{
    return (this->_imag);
}


void computorv2::Complex::setName(std::string name) 
{
    this->_name = name;
}

void computorv2::Complex::setReal(double real) 
{
    this->_real = real;
}

void computorv2::Complex::setImage(double imag)
{
    this->_imag = imag;
}


std::string computorv2::Complex::toString(void) const
{
    std::stringstream ss("");
    const double r = this->_real;
    const double m = this->_imag;
    if (!ISNULL(r) || ISNULL(m))
    {
        ss << r;
    }
    if (!ISNULL(m))
    {
        if (!ISNULL(r))
        {
            ss << " ";
        }
        if (!ISNULL(r) && (m > 0))
        {
            ss << "+";
        }
        if (m < 0)
        {
            ss << "-";
        }
        if (!ISNULL(r))
        {
            ss << " ";
        }
        const double aimg = ABS(m);
        if (!ISNULL(aimg - 1))
        {
            ss << aimg;
        }
        ss << this->_name;
    }
    return (ss.str());
}

void computorv2::Complex::clear(void)
{
    this->_name = "i";
    this->_real = 0.0;
    this->_imag = 0.0;
}

computorv2::Object* computorv2::Complex::copy(void) const
{
    return ( new computorv2::Complex(*this) );
}

bool computorv2::Complex::isnull(void) const
{
    return (ISNULL(this->getReal()) && ISNULL(this->getImage()));
}

bool computorv2::Complex::isunity(void) const
{
    return (ISNULL(this->getReal() - 1.0) && ISNULL(this->getImage())); 
}

computorv2::Complex operator+(const computorv2::Complex& left, const computorv2::Complex& right)
{
    computorv2::Complex res;
    res.setReal(left.getReal()   + right.getReal());
    res.setImage(left.getImage() + right.getImage());
    return (res);
}

computorv2::Complex operator-(const computorv2::Complex& left, const computorv2::Complex& right)
{
    computorv2::Complex res;
    res.setReal(left.getReal()   - right.getReal());
    res.setImage(left.getImage() - right.getImage());
    return (res);
}

computorv2::Complex operator-(const computorv2::Complex& left)
{
    return (computorv2::Complex(0.0, 0.0) - left);
}

computorv2::Complex operator*(const computorv2::Complex& left, const computorv2::Complex& right)
{
    const double lr = left.getReal();
    const double lm = left.getImage();
    const double rr = right.getReal();
    const double rm = right.getImage();
    return (
        computorv2::Complex(
            (lr * rr) - (lm * rm),
            (lr * rm) + (lm * rr)
        )
    );
}

computorv2::Complex operator*(const computorv2::Complex& left, double right)
{
    return (left * computorv2::Complex(right, 0.0));
}

computorv2::Complex operator*(double left, const computorv2::Complex& right)
{
    return (right * left);
}

computorv2::Complex operator/(const computorv2::Complex& left, const computorv2::Complex& right)
{
    if (right.isnull())
    {
        throw std::logic_error("Division By Zero!");
    }
    const double lr = left.getReal();
    const double lm = left.getImage();
    const double rr = right.getReal();
    const double rm = right.getImage();
    const double q = (rr * rr + rm * rm);
    return (
        computorv2::Complex(
            (lr * rr + lm * rm) / q,
            (lm * rr - lr * rm) / q
        )
    );
}

computorv2::Complex operator/(const computorv2::Complex& left, double right)
{
    return (left / computorv2::Complex(right, 0.0));
}

computorv2::Complex operator/(double left, const computorv2::Complex& right)
{
    return (computorv2::Complex(left, 0.0) / right);
}

bool operator==(const computorv2::Complex& left, const computorv2::Complex& right)
{
    if (ISNULL(left.getReal() - right.getReal()))
    {
        if (ISNULL(left.getImage() - right.getImage()))
        {
            return (true);
        }
    }
    return (false);
}
*/