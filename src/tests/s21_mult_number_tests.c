#include "s21_tests.h"

START_TEST(mult_number_test_0) {
  for (int N = 1; N < 10; N++) {
    matrix_t A = {0};
    matrix_t result = {0};
    double number = 1;

    ck_assert_int_eq(0, s21_create_matrix(N, N + 1, &A));
    set_random_matrix(&A);
    ck_assert_int_eq(0, s21_mult_number(&A, number, &result));

    ck_assert_double_matrix_eq_tol(&A, &result);

    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
  }
}
END_TEST

Suite *mult_number_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_mult_number");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, mult_number_test_0);

  return s;
}