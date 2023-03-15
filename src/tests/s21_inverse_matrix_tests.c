#include "s21_tests.h"

START_TEST(inverse_matrix_test_0) {
  for (int N = 1; N < 5; N++) {
    matrix_t A = {0};
    matrix_t inverse_A = {0};
    matrix_t result = {0};

    ck_assert_int_eq(0, s21_create_matrix(N, N, &A));

    set_random_matrix(&A);

    ck_assert_int_eq(0, s21_inverse_matrix(&A, &inverse_A));
    ck_assert_int_eq(0, s21_inverse_matrix(&inverse_A, &result));

    ck_assert_double_matrix_eq_tol(&A, &result);

    s21_remove_matrix(&A);
    s21_remove_matrix(&inverse_A);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(inverse_matrix_test_1) {
  matrix_t A = {0};
  matrix_t inverse_A = {0};
  matrix_t result = {0};

  ck_assert_int_eq(0, s21_create_matrix(3, 4, &A));

  set_random_matrix(&A);

  ck_assert_int_eq(2, s21_inverse_matrix(&A, &inverse_A));
  ck_assert_int_eq(1, s21_inverse_matrix(&inverse_A, &result));

  s21_remove_matrix(&A);
  s21_remove_matrix(&inverse_A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_test_2) {
  matrix_t A = {0};
  matrix_t inverse_A = {0};

  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));

  ck_assert_int_eq(2, s21_inverse_matrix(&A, &inverse_A));

  s21_remove_matrix(&A);
  s21_remove_matrix(&inverse_A);
}
END_TEST

Suite *inverse_matrix_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_inverse_matrix");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, inverse_matrix_test_0);
  tcase_add_test(tc, inverse_matrix_test_1);
  tcase_add_test(tc, inverse_matrix_test_2);

  return s;
}