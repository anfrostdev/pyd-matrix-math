#include <cstring>
#include "CfgMatrix.h"

CfgMatrix::CfgMatrix() {
    rows = 0;
    columns = 0;
    typeVal = "";
}

CfgMatrix::CfgMatrix(int countRows, int countColumns, const char* typeValues) {
    if (countRows < 1) {
        throw "Count rows matrix must be positive (c++)";
    }

    if (countColumns < 1) {
        throw "Count columns matrix must be positive (c++)";
    }

    rows = countRows;
    columns = countColumns;
    typeVal = typeValues;

    if (!is_type("int") && !is_type("double")) {
        throw "Unknown type matrix values (c++)";
    }
}

int CfgMatrix::get_count_rows() {
    return rows;
}

void CfgMatrix::set_count_rows(int countRows) {
    rows = countRows;
}

int CfgMatrix::get_count_columns() {
    return columns;
}

void CfgMatrix::set_count_columns(int countColumns) {
    columns = countColumns;
}

const char* CfgMatrix::get_type_val() {
    return typeVal;
}

void CfgMatrix::set_type_val(const char* typeValues) {
    typeVal = typeValues;
}

bool CfgMatrix::is_type(const char* typeMatrix) {
    return !strcmp(typeVal, typeMatrix);
}
