#include "s21_matrix.h"
#include "s21_common.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int status = EXIT_SUCCESS;

    double determinant;
    status = s21_determinant(A, &determinant);

    if (status == EXIT_SUCCESS && determinant != 0.0) {
        if (A->rows != 1) {
            matrix_t complements = {0, 0, 0};
            matrix_t transpose = {0, 0, 0};

            s21_calc_complements(A, &complements);
            s21_transpose(&complements, &transpose);

            s21_mult_number(&transpose, 1 / determinant, result);
        } else {
            s21_create_matrix(A->rows, A->columns, result);
            result->matrix[0][0] = 1 / determinant;
        }
    } else {
        status = EXIT_CALCULATION_ERROR;
    }

    return status;
}
