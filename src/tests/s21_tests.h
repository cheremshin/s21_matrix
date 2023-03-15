#ifndef SRC_TESTS_S21_TEST_H
#define SRC_TESTS_S21_TEST_H

#include <check.h>

#include "../lib/s21_common.h"
#include "time.h"

#define ACCURACY 1e-7

#define RAND_DOUBLE \
  ((double)(rand() % 100000 - 50000) / (rand() % 100000 - 50000))

#define START_FOREACH(A)              \
  for (int i = 0; i < A->rows; i++) { \
    for (int j = 0; j < A->columns; j++) {
#define END_FOREACH \
  }                 \
  }

#define MATRIX_ELEMENT(A) A->matrix[i][j]

SRunner *default_srunner_create();

Suite *calc_complements_suite(void);
Suite *combined_suite(void);
Suite *create_matrix_suite(void);
Suite *determinant_suite(void);
Suite *eq_suite(void);
Suite *inverse_matrix_suite(void);
Suite *mult_matrix_suite(void);
Suite *mult_number_suite(void);
Suite *sub_matrix_suite(void);
Suite *sum_matrix_suite(void);
Suite *transpose_suite(void);

void set_identity_matrix(matrix_t *A);
void ck_assert_double_matrix_eq_tol(matrix_t *original, matrix_t *result);
void set_random_matrix(matrix_t *A);
void copy_matrix(matrix_t *A, matrix_t *B);

#endif  // SRC_TESTS_S21_TEST_H