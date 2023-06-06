#include "s21_tests.h"

void set_identity_matrix(matrix_t *A) {
  START_FOREACH(A)
  MATRIX_ELEMENT(A) = !(i ^ j);
  END_FOREACH
}

void set_random_matrix(matrix_t *A) {
  START_FOREACH(A)
  MATRIX_ELEMENT(A) = RAND_DOUBLE;
  END_FOREACH
}

void ck_assert_double_matrix_eq_tol(matrix_t *original, matrix_t *result) {
  START_FOREACH(original)
  ck_assert_double_eq_tol(MATRIX_ELEMENT(original), MATRIX_ELEMENT(result),
                          ACCURACY);
  END_FOREACH
}

void copy_matrix(matrix_t *A, matrix_t *B) {
  s21_create_matrix(A->rows, A->columns, B);
  START_FOREACH(A)
  MATRIX_ELEMENT(B) = MATRIX_ELEMENT(A);
  END_FOREACH
}
