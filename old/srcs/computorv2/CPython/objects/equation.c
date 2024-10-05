# include "../../C/include/computorv1.h"

typedef struct
{
    PyObject_HEAD
    t_computorv1 p;
} equationObject;

static PyObject* equation_new(PyTypeObject* type, PyObject* args, PyObject* kwds)
{
    equationObject* self;
    self = (equationObject*)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        computorv1_clear(&(self->p));
    }
    return (PyObject*)self;
}

static int equation_init(equationObject* self, PyObject* args, PyObject* kwds)
{
    const char* initial_str = NULL;
    if (!PyArg_ParseTuple(args, "|s", &initial_str))
    {
        return (-1);
    }
    if (initial_str)
    {
        self->p = computorv1_equation(strdup(initial_str));
    }
    return (0);
}

static void equation_dealloc(equationObject* self) {
    if (self->p.str)
    {
        free(self->p.str);
        computorv1_clear(&(self->p));
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject* equation_solutions(equationObject* self)
{
    computorv1_solve(&(self->p));
    PyObject* solutions = PyList_New(self->p.solutions_number);
    if (solutions)
    {
        for (int index = 0; index < self->p.solutions_number; index++)
        {
            PyList_SetItem(solutions, index, PyFloat_FromDouble(self->p.solutions[index]));
        }
    }
    return (solutions);
}

static PyObject* equation_reduced_form(equationObject* self)
{
    char *reduced_form = computorv1_reduced_form(&(self->p));
    return(PyUnicode_FromString(reduced_form));
}

static PyObject* equation_degree(equationObject* self)
{
    return (PyLong_FromLong(computorv1_degree(&(self->p))));
}

static PyMethodDef equation_methods[] = {
    {"solutions"   , (PyCFunction) equation_solutions    , METH_NOARGS, "Solve the equation"},
    {"reduced_form", (PyCFunction) equation_reduced_form , METH_NOARGS, "description here!"},
    {"degree"      , (PyCFunction) equation_degree       , METH_NOARGS, "description here!"},
    {NULL}
};

static PyTypeObject equationType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name      = "computorv1.Equation",
    .tp_doc       = "Equation object",
    .tp_basicsize = sizeof(equationObject),
    .tp_itemsize  = 0,
    .tp_flags     = Py_TPFLAGS_DEFAULT,
    .tp_new       = equation_new,
    .tp_init      = (initproc)equation_init,
    .tp_dealloc   = (destructor)equation_dealloc,
    .tp_methods   = equation_methods,
};
