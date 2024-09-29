#include <Python.h>

static PyObject* validate_possibility_multiply_matrix(PyObject* self, PyObject* args) {
    PyObject* pyCfgMatrixOne = nullptr;
    PyObject* pyCfgMatrixTwo = nullptr;

    if (!PyArg_ParseTuple(args, "OO", &pyCfgMatrixOne, &pyCfgMatrixTwo)) {
        PyErr_SetString(PyExc_Exception, "Not valid arguments in function possibility_multipl (c++)");

        return nullptr;
    }

    if (PyList_Size(pyCfgMatrixOne) != 3) {
        PyErr_SetString(PyExc_Exception, "Not three arguments in config matrix one (c++)");

        return nullptr;
    }

    if (PyList_Size(pyCfgMatrixTwo) != 3) {
        PyErr_SetString(PyExc_Exception, "Not three arguments in config matrix two (c++)");

        return nullptr;
    }

    int columnMatrixOne = PyLong_AsLong(PyList_GetItem(pyCfgMatrixOne, 1));
    int rowMatrixTwo = PyLong_AsLong(PyList_GetItem(pyCfgMatrixTwo, 0));

    if (columnMatrixOne == rowMatrixTwo) {
        Py_RETURN_TRUE;
    }

    Py_RETURN_FALSE;
}

static PyMethodDef matrix_math_methods[] = {
    { "validate_possibility_multiply_matrix", (PyCFunction)validate_possibility_multiply_matrix, METH_O, nullptr },
    { nullptr, nullptr, 0, nullptr }
};

static PyModuleDef matrix_math_module = {
    PyModuleDef_HEAD_INIT,
    "math_matrix",
    "math_function_for_matrix",
    0,
    matrix_math_methods
};

PyMODINIT_FUNC PyInit_MatrixMath() {
    return PyModule_Create(&matrix_math_module);
}
