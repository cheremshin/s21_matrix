#include "s21_matrix.h"
#include "s21_common.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int status = EXIT_SUCCESS;

    if (A != NULL) {
        s21_create_matrix(A->rows, A->columns, result);

        for (size_t i = 0; i < A->rows; i++) {
            for (size_t j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] * number;
            }
        }
    } else {
        status = EXIT_CALCULATION_ERROR;
    }

    return status;
}