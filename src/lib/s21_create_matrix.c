#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int status = EXIT_SUCCESS;

    if ((rows <= 0) || (columns <= 0)) {
        status = EXIT_INCORRECT_MATRIX;
        result->rows = 0;
        result->columns = 0;
    }

    if (status != EXIT_INCORRECT_MATRIX) {
        result->rows = rows;
        result->columns = columns;

        result->matrix = (double **)malloc(sizeof(double *) * result->rows);
        for (size_t i = 0; i < result->rows; i++) {
            result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
        }
    }

    return status;
}
