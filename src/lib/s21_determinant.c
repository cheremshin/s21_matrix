#include "s21_matrix.h"
#include "s21_common.h"
#include "s21_determinant_support.h"

int s21_determinant(matrix_t *A, double *result) {
    int status = EXIT_SUCCESS;

    if ((A != NULL) && s21_check_on_square(A)) {
        if (s21_diagonal_check(A)) {
            *result = s21_gaussian_method(A);
        } else {
            *result = s21_minor_method(A);
        }
    } else {
        status = EXIT_CALCULATION_ERROR;
    }

    return status;
}
