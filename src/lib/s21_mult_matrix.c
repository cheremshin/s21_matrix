#include "s21_common.h"
#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = EXIT_SUCCESS;

  status = s21_check_on_correct(A);
  if (status == EXIT_SUCCESS) {
    if (A->columns != B->rows) {
      status = EXIT_CALCULATION_ERROR;
    }
  }

  if (status == EXIT_SUCCESS) {
    int M = A->rows, N = B->columns, K = A->columns;
    s21_create_matrix(M, N, result);

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < K; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return status;
}
