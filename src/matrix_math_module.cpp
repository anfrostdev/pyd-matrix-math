#include <Python.h>

static PyMethodDef matrix_math_methods[] = {
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
