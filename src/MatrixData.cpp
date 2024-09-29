#include "MatrixData.h"

void MatrixData::resize_matrix_int() {
    dataInt.resize(cfgMatrix.get_count_rows());
    for (int i = 0; i < cfgMatrix.get_count_rows(); i++) {
        dataInt[i].resize(cfgMatrix.get_count_columns());
    }
}

void MatrixData::resize_matrix_double() {
    dataDouble.resize(cfgMatrix.get_count_rows());
    for (int i = 0; i < cfgMatrix.get_count_rows(); i++) {
        dataDouble[i].resize(cfgMatrix.get_count_columns());
    }
}

void MatrixData::validate_indexes(int row, int column) {
    if (row < 0 && row >= this->cfgMatrix.get_count_rows()) {
        throw "Incorrect matrix row index (c++)";
    }

    if (column < 0 && column >= this->cfgMatrix.get_count_columns()) {
        throw "Incorrect matrix column index (c++)";
    }
}

MatrixData::MatrixData() {}

MatrixData::MatrixData(CfgMatrix cfgMtx) {
    if (cfgMtx.get_count_rows() <= 0) {
        throw "Can't create matrix (incorrect count rows) (c++)";
    }

    if (cfgMtx.get_count_columns() <= 0) {
        throw "Can't create matrix (incorrect count columns) (c++)";
    }

    cfgMatrix = cfgMtx;
    if (cfgMatrix.is_type("int")) {
        resize_matrix_int();
    }
    else if (cfgMatrix.is_type("double")) {
        resize_matrix_double();
    }
    else {
        throw "Can't create matrix (unknoun type) (c++)";
    }
}

void MatrixData::get_value(int row, int column, int& value) {
    validate_indexes(row, column);
    value = dataInt[row][column];
}

void MatrixData::get_value(int row, int column, double& value) {
    validate_indexes(row, column);
    value = dataDouble[row][column];
}

void MatrixData::set_value(int row, int column, int value) {
    validate_indexes(row, column);
    dataInt[row][column] = value;
}

void MatrixData::set_value(int row, int column, double value) {
    validate_indexes(row, column);
    dataDouble[row][column] = value;
}

CfgMatrix MatrixData::get_cfg() {
    return cfgMatrix;
}

void MatrixData::set_cfg(CfgMatrix cfgMtx) {
    cfgMatrix = cfgMtx;
}

std::string MatrixData::dump_matrix() {
    std::string result;
    result += "Config: ";
    result += "rows: " + std::to_string(get_cfg().get_count_rows());
    result += ", columns: " + std::to_string(get_cfg().get_count_columns());
    result += ", type: ";
    result += get_cfg().get_type_val();
    result += "\nMatrix:\n";
    int matrixType = 0;
    if (get_cfg().is_type("int")) {
        matrixType = 1;
    }
    else if (get_cfg().is_type("double")) {
        matrixType = 2;
    }
    else {
        throw "Unknoun matrix type (c++)";
    }

    for (int i = 0; i < get_cfg().get_count_rows(); i++) {
        for (int j = 0; j < get_cfg().get_count_columns(); j++) {
            if (matrixType == 1) {
                int intItem = 0;
                get_value(i, j, intItem);
                result += std::to_string(intItem) + " ";
            }
            else if (matrixType == 2) {
                double doubleItem = 0;
                get_value(i, j, doubleItem);
                result += std::to_string(doubleItem) + " ";
            }
        }

        result += "\n";
    }

    result += "\n";

    return result;
}
