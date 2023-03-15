#include "s21_tests.h"

START_TEST(mult_matrix_test_0) {
  for (int N = 1; N < 10; N++) {
    matrix_t A = {0};
    matrix_t inverse_A = {0};
    matrix_t result = {0};
    matrix_t original = {0};

    ck_assert_int_eq(0, s21_create_matrix(N, N, &A));
    ck_assert_int_eq(0, s21_create_matrix(N, N, &original));

    set_random_matrix(&A);
    set_identity_matrix(&original);

    ck_assert_int_eq(0, s21_inverse_matrix(&A, &inverse_A));
    ck_assert_int_eq(0, s21_mult_matrix(&A, &inverse_A, &result));
    ck_assert_double_matrix_eq_tol(&original, &result);

    s21_remove_matrix(&A);
    s21_remove_matrix(&inverse_A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&original);
  }
}
END_TEST

START_TEST(mult_matrix_test_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t original = {0};

  ck_assert_int_eq(0, s21_create_matrix(3, 4, &A));
  ck_assert_int_eq(0, s21_create_matrix(4, 5, &B));
  ck_assert_int_eq(0, s21_create_matrix(3, 5, &original));

  set_random_matrix(&A);

  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));
  ck_assert_double_matrix_eq_tol(&original, &result);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&original);
}
END_TEST

START_TEST(mult_matrix_test_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  ck_assert_int_eq(0, s21_create_matrix(3, 4, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 4, &B));

  ck_assert_int_eq(2, s21_mult_matrix(&A, &B, &result));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_test_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  ck_assert_int_eq(1, s21_create_matrix(-3, 4, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 4, &B));

  ck_assert_int_eq(1, s21_mult_matrix(&A, &B, &result));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *mult_matrix_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_mult_matrix");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, mult_matrix_test_0);
  tcase_add_test(tc, mult_matrix_test_1);
  tcase_add_test(tc, mult_matrix_test_2);
  tcase_add_test(tc, mult_matrix_test_3);

  return s;
}