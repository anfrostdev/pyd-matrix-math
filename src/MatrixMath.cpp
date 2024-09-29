#include "MatrixMath.h"

MatrixData MatrixMath::multiply(MatrixData matrixOne, MatrixData matrixTwo) {

    const char* typeValResultMatrix = (matrixOne.get_cfg().is_type("double") || matrixTwo.get_cfg().is_type("double"))
    ? "double"
    : "int";

    CfgMatrix cnfResultMatrix(
        matrixOne.get_cfg().get_count_rows(),
        matrixTwo.get_cfg().get_count_columns(),
        typeValResultMatrix
    );
    MatrixData resultMatrix(cnfResultMatrix);
    int rowResultMatrix = matrixOne.get_cfg().get_count_rows();
    int columnResaltMatrix = matrixTwo.get_cfg().get_count_columns();
    int column = matrixOne.get_cfg().get_count_columns();
    int matrixType = 0;
    if (matrixOne.get_cfg().is_type("int")) {
        matrixType = 1;
    }
    else if (matrixOne.get_cfg().is_type("double")) {
        matrixType = 2;
    }
    else {
        throw "unknoun matrix type (c++)";
    }

    for (int i = 0; i < rowResultMatrix; i++) {
        for (int j = 0; j < columnResaltMatrix; j++) {
            if (matrixType == 1) {
                int sum = 0;
                for (int k = 0; k < column; k++) {
                    int multOne = 0;
                    int multTwo = 0;
                    matrixOne.get_value(i, k, multOne);
                    matrixTwo.get_value(k, j, multTwo);
                    sum += multOne * multTwo;
                }

                resultMatrix.set_value(i, j, sum);
            }
            else if (matrixType == 2) {
                double sum = 0;
                for (int k = 0; k < column; k++) {
                    double multOne = 0;
                    double multTwo = 0;
                    matrixOne.get_value(i, k, multOne);
                    matrixTwo.get_value(k, j, multTwo);
                    sum += multOne * multTwo;
                }

                resultMatrix.set_value(i, j, sum);
            }
        }
    }

    return resultMatrix;
}
