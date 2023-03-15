#include "s21_matrix.h"
#include "s21_common.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int status = EXIT_SUCCESS;

    double determinant;
    status = s21_determinant(A, &determinant);

    if (status == EXIT_SUCCESS && determinant != 0.0) {
        
    }

    return status;
}