#include "s21_tests.h"

START_TEST(calc_complements_test_0) {
  matrix_t A = {0};
  matrix_t original = {0};
  matrix_t result = {0};

  int rows = 3;
  int columns = 3;

  ck_assert_int_eq(0, s21_create_matrix(rows, columns, &A));

  set_identity_matrix(&A);
  set_random_matrix(&A);

  ck_assert_int_eq(0, s21_calc_complements(&A, &result));
  ck_assert_double_matrix_eq_tol(&original, &result);

  s21_remove_matrix(&A);
  s21_remove_matrix(&original);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_test_1) {
  matrix_t A = {0};
  matrix_t result = {0};

  int rows = 3;
  int columns = 4;

  ck_assert_int_eq(0, s21_create_matrix(rows, columns, &A));
  ck_assert_int_eq(2, s21_calc_complements(&A, &result));

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

Suite *calc_complements_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_calc_complements");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, calc_complements_test_0);
  tcase_add_test(tc, calc_complements_test_1);

  return s;
}
