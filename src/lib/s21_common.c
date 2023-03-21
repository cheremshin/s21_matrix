#include "s21_common.h"

int s21_eq_dimension(matrix_t *A, matrix_t *B) {
    int status = EXIT_SUCCESS;

    if ((A->rows != B->rows) || (A->columns != B->columns)) {
        status = EXIT_CALCULATION_ERROR;
    }

    return status;
}

int s21_check_on_square(matrix_t *A) {
    int status = EXIT_SUCCESS;

    if (A->rows != A->columns) {
        status = EXIT_CALCULATION_ERROR;
    }

    return status;
}

int s21_check_on_correct(matrix_t *A) {
    int status = EXIT_SUCCESS;

    if ((A == NULL) || (A->matrix == NULL)) {
        status = EXIT_INCORRECT_MATRIX;
    }

    return status;
}

int s21_sign(int row, int column) {
    return ((row + column) % 2 == 0) ? 1 : -1;
}

void s21_get_minor(matrix_t *A, int row, int column, matrix_t *result) {
    s21_create_matrix(A->rows - 1, A->columns - 1, result);

    int m = 0, n = 0;
	for (int i = 0; i < A->rows; i++, m++) {
		if (i == row) m--;
		for (int j = 0; j < A->columns; j++) {
			if(i != row && j != column) {
				result->matrix[m][n] = A->matrix[i][j];
				n++;
			}
		}
		n = 0;
	}
}
