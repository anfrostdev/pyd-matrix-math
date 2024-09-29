#pragma once

class CfgMatrix
{
    int rows;
    int columns;
    const char* typeVal;

public:
    CfgMatrix();
    CfgMatrix(int, int, const  char*);
    int get_count_rows();
    void set_count_rows(int);
    int get_count_columns();
    void set_count_columns(int);
    const char* get_type_val();
    void set_type_val(const char*);
    bool is_type(const char*);
};
