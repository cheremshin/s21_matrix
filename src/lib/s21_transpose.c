#include "s21_matrix.h"
#include "s21_common.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
    int status = EXIT_SUCCESS;

    if (A != NULL) {
        s21_create_matrix(A->columns, A->rows, result);

        for (size_t i = 0; i < A->rows; i++) {
            for (size_t j = 0; j < A->columns; j++) {
                result->matrix[j][i] = A->matrix[i][j];
            }
        }
    } else {
        status = EXIT_CALCULATION_ERROR;
    }

    return status;
}
