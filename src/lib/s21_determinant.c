#include <stdio.h>

#include "s21_common.h"
#include "s21_determinant_support.h"
#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = EXIT_SUCCESS;

  status = s21_check_on_correct(A);
  if (status == EXIT_SUCCESS) {
    status = s21_check_on_square(A);
  }

  if (status == EXIT_SUCCESS) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      *result = s21_minor_method(A);
    }
  }

  return status;
}
