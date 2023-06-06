#include "s21_tests.h"

START_TEST(transpose_test_0) {
  for (int N = 1; N < 5; N++) {
    for (int M = 1; M < 5; M++) {
      matrix_t A = {0};
      matrix_t transpose = {0};
      matrix_t result = {0};

      ck_assert_int_eq(0, s21_create_matrix(N, M, &A));

      ck_assert_int_eq(0, s21_transpose(&A, &transpose));
      ck_assert_int_eq(0, s21_transpose(&transpose, &result));

      ck_assert_int_eq(transpose.rows, A.columns);
      ck_assert_int_eq(transpose.columns, A.rows);

      ck_assert_double_matrix_eq_tol(&A, &result);

      s21_remove_matrix(&A);
      s21_remove_matrix(&transpose);
      s21_remove_matrix(&result);
    }
  }
}
END_TEST

START_TEST(transpose_test_1) {
  matrix_t A = {0};
  matrix_t transpose = {0};

  ck_assert_int_eq(1, s21_create_matrix(-3, 3, &A));
  ck_assert_int_eq(1, s21_transpose(&A, &transpose));

  s21_remove_matrix(&A);
  s21_remove_matrix(&transpose);
}
END_TEST

Suite *transpose_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_transpose");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, transpose_test_0);
  tcase_add_test(tc, transpose_test_1);

  return s;
}