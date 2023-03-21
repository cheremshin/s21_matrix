#include "s21_matrix.h"
#include "s21_common.h"
#include "s21_determinant_support.h"

int s21_determinant(matrix_t *A, double *result) {
    int status = EXIT_SUCCESS;

    if ((A != NULL) && s21_check_on_square(A)) {
        if (A->rows == 1) {
            *result = A->matrix[0][0];
        } else {
            *result = s21_minor_method(A);
        }
    } else {
        status = EXIT_CALCULATION_ERROR;
    }

    return status;
}
