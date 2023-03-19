#include "s21_common.h"

int s21_eq_dimension(matrix_t *A, matrix_t *B) {
    int status = SUCCESS;

    if ((A->rows != B->rows) || (A->columns != B->columns)) {
        status = FAILURE;
    }

    return status;
}

int s21_check_on_square(matrix_t *A) {
    int status = SUCCESS;

    if (A->rows != A->columns) {
        status = FAILURE;
    }

    return status;
}

void s21_copy_matrix(matrix_t *A, matrix_t *result) {
    s21_create_matrix(A->rows, A->columns, result);
    for (size_t i = 0; i < A->rows; i++) {
        for (size_t j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j];
        }
    }
}

int s21_sign(int row, int sign) {
    return (row + sign % 2 == 0) ? 1 : -1;
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
