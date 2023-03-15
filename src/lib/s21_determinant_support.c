#include "s21_determinant_support.h"
#include "s21_common.h"

#include <math.h>

int s21_diagonal_check(matrix_t *A) {
    int status = SUCCESS;

    for (int i = 0; i < A->rows && status; i++) {
        if (fabs(A->matrix[i][i]) < EPSILON) {
            status = FAILURE;
        }
    }

    return status;
}

double s21_gaussian_method(matrix_t *A) {
    double determinant;

    matrix_t *copy = (matrix_t *)malloc(sizeof(matrix_t));
    s21_copy_matrix(A, copy);

    double multiplier = 1;

    for (int column = 0; column < copy->columns - 1; column++) {
        multiplier *= s21_normalize(copy, column, column);
        for (size_t row = column + 1; row < copy->rows; row++) {
            s21_nullify(copy, row, column);
        }
    }

    determinant = copy->matrix[copy->rows - 1][copy->columns - 1] * multiplier;

    s21_remove_matrix(copy);
    free(copy);

    return determinant;
}

double s21_normalize(matrix_t *A, int row, int column) {
    double divider = A->matrix[row][column];
    for (int i = column; i < A->columns; i++) {
        A->matrix[row][i] /= divider;
    }

    return divider;
}

void s21_nullify(matrix_t *A, int row, int column) {
    double multiplier = A->matrix[row][column];
    for (int i = column; i < A->columns; i++) {
        A->matrix[row][i] -= A->matrix[column][i] * multiplier;
    }
}

double s21_second_order_matrix_determinant(matrix_t *A) {
    return (A->matrix[0][0] * A->matrix[1][1]) - (A->matrix[1][0] * A->matrix[0][1]);
}

double s21_minor_method(matrix_t *A) {
    double determinant = 0;

    if (A->rows == 2) {
        determinant = s21_second_order_matrix_determinant(A);
    } else {
        for (int j = 0; j < A->columns; j++) {
            matrix_t *minor = (matrix_t *)malloc(sizeof(matrix_t));
            s21_get_minor(A, 0, j, minor);

            determinant += s21_sign(0, j) * A->matrix[0][j] * s21_minor_method(minor);

            free(minor);
        }
    }

    return determinant;
}