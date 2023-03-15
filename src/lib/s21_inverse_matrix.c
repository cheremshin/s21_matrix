#include "s21_matrix.h"
#include "s21_common.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int status = EXIT_SUCCESS;

    double determinant;
    status = s21_determinant(A, &determinant);

    if (status == EXIT_SUCCESS && determinant != 0.0) {
        matrix_t *complements = (matrix_t *)malloc(sizeof(matrix_t));
        s21_calc_complements(A, complements);

        matrix_t *transpose = (matrix_t *)malloc(sizeof(matrix_t));
        s21_transpose(complements, transpose);

        s21_mult_number(transpose, 1/determinant, result);

        s21_remove_matrix(complements);
        s21_remove_matrix(transpose);
        free(complements);
        free(transpose);
    } else {
        status = EXIT_CALCULATION_ERROR;
    }

    return status;
}
