#include "s21_tests.h"
#include <stdio.h>
START_TEST(determinant_test_0) {
  matrix_t A = {0};

  double original = 0;
  double result = 0;

  int rows = 3;
  int columns = 3;

  ck_assert_int_eq(0, s21_create_matrix(rows, columns, &A));
  ck_assert_int_eq(0, s21_determinant(&A, &result));
  ck_assert_double_eq_tol(original, result, ACCURACY);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_1) {
  matrix_t A = {0};

  double original = 1;
  double result = 0;

  int rows = 3;
  int columns = 3;
  ck_assert_int_eq(0, s21_create_matrix(rows, columns, &A));

  set_identity_matrix(&A);
  ck_assert_int_eq(0, s21_determinant(&A, &result));
  ck_assert_double_eq_tol(original, result, ACCURACY);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_2) {
  matrix_t A = {0};

  double result = 0;

  int rows = 3;
  int columns = 4;

  ck_assert_int_eq(0, s21_create_matrix(rows, columns, &A));
  set_identity_matrix(&A);
  ck_assert_int_eq(2, s21_determinant(&A, &result));

  s21_remove_matrix(&A);
}
END_TEST

Suite *determinant_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_determinant");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, determinant_test_0);
  tcase_add_test(tc, determinant_test_1);
  tcase_add_test(tc, determinant_test_2);

  return s;
}