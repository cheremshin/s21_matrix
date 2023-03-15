#include "s21_tests.h"

START_TEST(eq_test_0) {
  matrix_t A = {0};
  matrix_t B = {0};

  ck_assert_int_eq(0, s21_create_matrix(2, 3, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));

  ck_assert_int_eq(0, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};

  ck_assert_int_eq(0, s21_create_matrix(10, 10, &A));

  set_random_matrix(&A);
  copy_matrix(&A, &B);

  ck_assert_int_eq(1, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};

  ck_assert_int_eq(0, s21_create_matrix(3, 4, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 4, &B));

  A.matrix[0][0] = 1;

  ck_assert_int_eq(0, s21_eq_matrix(&A, &B));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *eq_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_eq");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, eq_test_0);
  tcase_add_test(tc, eq_test_1);
  tcase_add_test(tc, eq_test_2);

  return s;
}