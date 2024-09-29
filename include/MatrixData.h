#pragma once
#include <vector>
#include <string>
#include "CfgMatrix.h"

class MatrixData
{
    CfgMatrix cfgMatrix;
    std::vector <std::vector <int>> dataInt;
    std::vector <std::vector <double>> dataDouble;
    void resize_matrix_int();
    void resize_matrix_double();
    void validate_indexes(int, int);

public:
    MatrixData();
    MatrixData(CfgMatrix);
    void get_value(int, int, int&);
    void get_value(int, int, double&);
    void set_value(int, int, int);
    void set_value(int, int, double);
    CfgMatrix get_cfg();
    void set_cfg(CfgMatrix);
    std::string dump_matrix();
};
