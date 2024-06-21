#include <Python.h>

# include "objects/equation.c"

static PyObject* pycomputorv1_program(PyObject* self, PyObject* args)
{
    return (NULL);
}

static PyMethodDef computorv1_methods[] = {
    {"program"    , pycomputorv1_program    , METH_VARARGS , "run program"},
    {NULL         , NULL                    , 0            , NULL         }
};

static struct PyModuleDef computorv1_module = {
    PyModuleDef_HEAD_INIT,
    "computorv1",
    "Example module for solving equations",
    -1,
    computorv1_methods
};

PyMODINIT_FUNC PyInit_computorv1(void) 
{
    PyObject* m;
    if (PyType_Ready(&equationType) < 0)
    {
        return (NULL);
    }
    m = PyModule_Create(&computorv1_module);
    if (m == NULL)
    {
        return (NULL);
    }
    Py_INCREF(&equationType);
    if (PyModule_AddObject(m, "Equation", (PyObject*)&equationType) < 0)
    {
        Py_DECREF(&equationType);
        Py_DECREF(m);
        return (NULL);
    }
    return (m);
}




/*

typedef struct
{
    PyObject_HEAD
} py_computorv1;

static PyObject* pycomputorv1_solutions(py_computorv1* self)
{
    PyObject* solutions = PyList_New(3);
    if (solutions)
    {
        PyList_SetItem(solutions, 0, PyFloat_FromDouble(1.1));
        PyList_SetItem(solutions, 1, PyFloat_FromDouble(2.2));
        PyList_SetItem(solutions, 2, PyFloat_FromDouble(3.3));
    }
    return (solutions);
}

static PyMethodDef py_computorv1_methods[] = {
    {"solutions", (PyCFunction) pycomputorv1_solutions, METH_NOARGS, "Returns a greeting"},
    {NULL}  // Sentinel
};

static PyTypeObject py_computorv1Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name      = "mymodule.py_computorv1",
    .tp_doc       = "Simple object",
    .tp_basicsize = sizeof(py_computorv1),
    .tp_itemsize  = 0,
    .tp_flags     = Py_TPFLAGS_DEFAULT,
    .tp_new       = PyType_GenericNew,
    .tp_methods   = py_computorv1_methods,
};

























static PyObject* pycomputorv1_parse(PyObject* self, PyObject* args)
{
    return PyLong_FromLong(0);
}

static PyMethodDef computorv1Methods[] = {
    {"parse"    , pycomputorv1_parse    , METH_VARARGS , "parse equation"},
    {"solutions", pycomputorv1_solutions, METH_VARARGS , "solutions of equation"},
    {NULL       , NULL                  , 0            , NULL}
};

// Module definition
static struct PyModuleDef computorv1module = {
    PyModuleDef_HEAD_INIT,
    "computorv1",
    NULL,
    -1,
    computorv1Methods
};

// Module initialization
PyMODINIT_FUNC PyInit_computorv1(void) {
    return PyModule_Create(&computorv1module);
}

*/
