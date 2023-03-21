#include "s21_matrix.h"
#include "s21_common.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int status = EXIT_SUCCESS;

    if ((A != NULL) && s21_check_on_square(A)) {
        s21_create_matrix(A->rows, A->columns, result);

        double determinant;
        matrix_t minor = {0, 0, 0};

        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                s21_get_minor(A, i, j, &minor);
                s21_determinant(&minor, &determinant);

                result->matrix[i][j] = s21_sign(i, j) * determinant;

                s21_remove_matrix(&minor);
            }
        }
    } else {
        status = EXIT_CALCULATION_ERROR;
    }

    return status;
}
