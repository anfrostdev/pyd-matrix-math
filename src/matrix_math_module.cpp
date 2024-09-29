#include <Python.h>
#include "Convertor.h"
#include "MatrixMath.h"

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

static PyObject* multiply_two_matrix(PyObject* self, PyObject* args) {
    PyObject* pyCfgMatrixOne;
    PyObject* pyCfgMatrixTwo;
    PyObject* pyCfgMatrixResult;
    PyObject* pyMatrixOne;
    PyObject* pyMatrixTwo;
    PyObject* pyMatrixResult;
    Convertor conv;
    MatrixMath matrixMath;

    if (!PyArg_ParseTuple(args, "OOOOOO", &pyCfgMatrixOne, &pyMatrixOne, &pyCfgMatrixTwo, &pyMatrixTwo, &pyCfgMatrixResult, &pyMatrixResult)) {
        PyErr_SetString(PyExc_Exception, "Not valid argument in function multiply_matrix (c++)");

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

    try {
        CfgMatrix cfgMatrixOne = conv.convert_pyobj_to_matrix_cfg(pyCfgMatrixOne);
        CfgMatrix cfgMatrixTwo = conv.convert_pyobj_to_matrix_cfg(pyCfgMatrixTwo);

        // Workaround for handling two matrices of different data types
        if (cfgMatrixOne.is_type("double") || cfgMatrixTwo.is_type("double")) {
            cfgMatrixOne.set_type_val("double");
            cfgMatrixTwo.set_type_val("double");
        }

        MatrixData matrixOne = conv.convert_pyobj_to_matrix_data(cfgMatrixOne, pyMatrixOne);
        MatrixData matrixTwo = conv.convert_pyobj_to_matrix_data(cfgMatrixTwo, pyMatrixTwo);
        
        // ToDo: Implement collection verbose output on flag value
        //std::cout << matrixOne.dump_matrix();
        //std::cout << matrixTwo.dump_matrix();

        MatrixData matrixresult = matrixMath.multiply(matrixOne, matrixTwo);
        // ToDo: Implement collection verbose output on flag value
        //std::cout << matrixresult.dump_matrix();

        conv.convert_matrix_data_to_pyobj(matrixresult, pyCfgMatrixResult, pyMatrixResult);
    }
    catch (const char* str_err) {
        PyErr_SetString(PyExc_Exception, str_err);

        return nullptr;
    }

    Py_RETURN_TRUE;
}

static PyMethodDef matrix_math_methods[] = {
    { "validate_possibility_multiply_matrix", (PyCFunction)validate_possibility_multiply_matrix, METH_O, nullptr },
    { "multiply_two_matrix", (PyCFunction)multiply_two_matrix, METH_O, nullptr },

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
