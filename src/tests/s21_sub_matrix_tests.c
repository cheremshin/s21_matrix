#include "s21_tests.h"

START_TEST(sub_matrix_test_0) {
  for (int N = 1; N < 10; N++) {
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t tmp_res = {0};
    matrix_t result = {0};

    ck_assert_int_eq(0, s21_create_matrix(N, N + 1, &A));
    ck_assert_int_eq(0, s21_create_matrix(N, N + 1, &B));

    set_random_matrix(&A);
    set_random_matrix(&B);

    ck_assert_int_eq(0, s21_sub_matrix(&A, &B, &tmp_res));
    ck_assert_int_eq(0, s21_sum_matrix(&tmp_res, &B, &result));

    ck_assert_double_matrix_eq_tol(&A, &result);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(sub_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  ck_assert_int_eq(1, s21_create_matrix(-3, 3, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));

  ck_assert_int_eq(1, s21_sub_matrix(&A, &B, &result));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  ck_assert_int_eq(0, s21_create_matrix(3, 5, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 6, &B));

  ck_assert_int_eq(2, s21_sub_matrix(&A, &B, &result));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *sub_matrix_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sub_matrix");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, sub_matrix_test_0);
  tcase_add_test(tc, sub_matrix_test_1);
  tcase_add_test(tc, sub_matrix_test_2);

  return s;
}