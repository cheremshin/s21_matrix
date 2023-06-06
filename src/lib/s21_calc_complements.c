#include "s21_common.h"
#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = EXIT_SUCCESS;

  status = s21_check_on_correct(A);
  if (status == EXIT_SUCCESS) {
    status = s21_check_on_square(A);
  }

  if (status == EXIT_SUCCESS) {
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
  }

  return status;
}
