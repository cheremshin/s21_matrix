#include "s21_matrix.h"
#include "s21_common.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int status = EXIT_SUCCESS;

    status = s21_check_on_correct(A);
    if (status == EXIT_SUCCESS) {
        status = s21_eq_dimension(A, B);
    }

    if (status == EXIT_SUCCESS) {
        s21_create_matrix(A->rows, A->columns, result);

        for (size_t i = 0; i < A->rows; i++) {
            for (size_t j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
    }

    return status;
}
