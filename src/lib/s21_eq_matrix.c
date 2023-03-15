#include "s21_matrix.h"
#include "s21_common.h"

#include <math.h>

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int status = SUCCESS;

    status = (A != NULL) && (B != NULL) && s21_eq_dimension(A, B);

    if (status) {
        for (size_t i = 0; i < A->rows && status; i++) {
            for (size_t j = 0; j < A->columns && status; j++) {
                if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPSILON) {
                    status = FAILURE;
                }
            }
        }
    }

    return status;
}
