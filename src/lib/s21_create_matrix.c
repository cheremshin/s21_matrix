#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int status = EXIT_SUCCESS;

    result->rows = rows;
    result->columns = columns;

    if ((rows <= 0) || (columns <= 0)) {
        status = EXIT_INCORRECT_MATRIX;
    }

    if (status != EXIT_INCORRECT_MATRIX) {
        result->matrix = (double **)malloc(sizeof(double *) * result->rows);
        for (size_t i = 0; i < result->rows; i++) {
            result->matrix[i] = (double *)malloc(sizeof(double) * result->columns);
        }
    }

    return status;
}
