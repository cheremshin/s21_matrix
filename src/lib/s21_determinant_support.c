#include "s21_determinant_support.h"
#include "s21_common.h"

#include <math.h>

double s21_minor_method(matrix_t *A) {
    double determinant = 0;

    if (A->rows == 2) {
        determinant = s21_second_order_matrix_determinant(A);
    } else {
        matrix_t *minor = (matrix_t *)malloc(sizeof(matrix_t));

        for (int j = 0; j < A->columns; j++) {
            s21_get_minor(A, 0, j, minor);

            determinant += s21_sign(0, j) * A->matrix[0][j] * s21_minor_method(minor);

            s21_remove_matrix(minor);
        }

        free(minor);
    }

    return determinant;
}

double s21_second_order_matrix_determinant(matrix_t *A) {
    return (A->matrix[0][0] * A->matrix[1][1]) - (A->matrix[1][0] * A->matrix[0][1]);
}
