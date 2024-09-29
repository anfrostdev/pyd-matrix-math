#include "Convertor.h"

bool Convertor::is_matrix_double(const char* matrixType) {
    return strcmp(matrixType, "int");
}

CfgMatrix Convertor::convert_pyobj_to_matrix_cfg(PyObject* pyConfMatrix) {
    int rowsMatrix;
    int columnMatrix;
    const char* typeValues;
    try {
        rowsMatrix = PyLong_AsLong(PyList_GetItem(pyConfMatrix, CFG_INDEX_ROWS));
        columnMatrix = PyLong_AsLong(PyList_GetItem(pyConfMatrix, CFG_INDEX_COLUMNS));
        typeValues = PyUnicode_AsUTF8(PyList_GetItem(pyConfMatrix, CFG_INDEX_TYPE_VAL));
    }
    catch (...) {
        throw "Incorrect valyes in matrix config (c++)";
    }

    return CfgMatrix(rowsMatrix, columnMatrix, typeValues);
}

MatrixData Convertor::convert_pyobj_to_matrix_data(CfgMatrix cfgMatrix, PyObject* pyDataMatrix) {
    if (PyList_Size(pyDataMatrix) != cfgMatrix.get_count_rows()) {
        throw "There are more(less) rows in matrix (c++)";
    }

    MatrixData matrixResult(cfgMatrix);
    int row = matrixResult.get_cfg().get_count_rows();
    int column = matrixResult.get_cfg().get_count_columns();
    bool isMatrixDouble = is_matrix_double(matrixResult.get_cfg().get_type_val());
    for (int i = 0; i < row; i++) {
        if (PyList_Size(PyList_GetItem(pyDataMatrix, i)) != column) {
            throw "There are more(less) values in row (c++)";
        }

        for (int j = 0; j < column; j++) {
            if (isMatrixDouble) {
                double doubleMatrixItem = PyFloat_AsDouble(PyList_GetItem(PyList_GetItem(pyDataMatrix, i), j));
                matrixResult.set_value(i, j, doubleMatrixItem);
            }
            else {
                int intMatrixItem = PyLong_AsLong(PyList_GetItem(PyList_GetItem(pyDataMatrix, i), j));
                matrixResult.set_value(i, j, intMatrixItem);
            }
        }
    }

    return matrixResult;
}

void Convertor::convert_matrix_data_to_pyobj(MatrixData matrixData, PyObject* cfgMatrix, PyObject* pyDataMatrix) {

    PyList_Append(cfgMatrix, PyLong_FromLong(matrixData.get_cfg().get_count_rows()));
    PyList_Append(cfgMatrix, PyLong_FromLong(matrixData.get_cfg().get_count_columns()));
    PyList_Append(cfgMatrix, PyUnicode_FromString(matrixData.get_cfg().get_type_val()));
    int row = matrixData.get_cfg().get_count_rows();
    int column = matrixData.get_cfg().get_count_columns();
    bool isMatrixDouble = is_matrix_double(matrixData.get_cfg().get_type_val());
    for (int i = 0; i < row; i++) {
        PyObject* rowMatrix = PyList_New(column);
        for (int j = 0; j < column; j++) {
            if (isMatrixDouble) {
                double doubleMatrixItem = 0;
                matrixData.get_value(i, j, doubleMatrixItem);
                PyList_SetItem(rowMatrix, j, PyFloat_FromDouble(doubleMatrixItem));
            }
            else {
                int intMatrixItem = 0;
                matrixData.get_value(i, j, intMatrixItem);
                PyList_SetItem(rowMatrix, j, PyLong_FromLong(intMatrixItem));
            }
        }

        PyList_Append(pyDataMatrix, rowMatrix);
    }
}