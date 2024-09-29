#pragma once
#include <Python.h>
#include "CfgMatrix.h"
#include "MatrixData.h"

class Convertor
{
    const int CFG_INDEX_ROWS = 0;
    const int CFG_INDEX_COLUMNS = 1;
    const int CFG_INDEX_TYPE_VAL = 2;
    bool is_matrix_double(const char*);

public:
    CfgMatrix convert_pyobj_to_matrix_cfg(PyObject*);
    MatrixData convert_pyobj_to_matrix_data(CfgMatrix, PyObject*);
    void convert_matrix_data_to_pyobj(MatrixData, PyObject*, PyObject*);
};
