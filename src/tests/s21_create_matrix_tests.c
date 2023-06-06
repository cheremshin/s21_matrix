#include "s21_tests.h"

START_TEST(create_matrix_test_0) {
  matrix_t matrix = {0};

  ck_assert_int_eq(1, s21_create_matrix(0, 0, &matrix));
  ck_assert_int_eq(1, s21_create_matrix(1, 0, &matrix));
  ck_assert_int_eq(1, s21_create_matrix(0, 1, &matrix));
  ck_assert_int_eq(1, s21_create_matrix(-1, 1, &matrix));
  ck_assert_int_eq(1, s21_create_matrix(1, -1, &matrix));
  ck_assert_int_eq(1, s21_create_matrix(-1, -1, &matrix));

  ck_assert_int_eq(0, s21_create_matrix(1, 1, &matrix));
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(0, s21_create_matrix(255, 254, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

Suite *create_matrix_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_create_matrix");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, create_matrix_test_0);

  return s;
}
