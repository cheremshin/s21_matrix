#include "s21_tests.h"

START_TEST(combined_test_0) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t C = {0};
  matrix_t D = {0};

  int M = 4;
  int N = 4;

  ck_assert_int_eq(0, s21_create_matrix(N, N, &A));
  ck_assert_int_eq(0, s21_create_matrix(N, N, &B));
  ck_assert_int_eq(0, s21_create_matrix(N, N, &C));
  ck_assert_int_eq(0, s21_create_matrix(N, N, &D));

  set_random_matrix(&A);
  set_random_matrix(&B);
  set_random_matrix(&C);
  set_random_matrix(&D);

  matrix_t sum_res_1 = {0};
  matrix_t sum_res_2 = {0};
  matrix_t sum_res_3 = {0};
  matrix_t sum_res_4 = {0};

  ck_assert_int_eq(0, s21_sum_matrix(&A, &B, &sum_res_1));
  ck_assert_int_eq(0, s21_sum_matrix(&C, &D, &sum_res_2));
  ck_assert_int_eq(0, s21_sum_matrix(&A, &D, &sum_res_3));
  ck_assert_int_eq(0, s21_sum_matrix(&B, &C, &sum_res_4));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);

  matrix_t sum_res_1_transpose = {0};
  matrix_t sum_res_3_transpose = {0};

  s21_transpose(&sum_res_1, &sum_res_1_transpose);
  s21_transpose(&sum_res_3, &sum_res_3_transpose);

  s21_remove_matrix(&sum_res_1);
  s21_remove_matrix(&sum_res_3);

  matrix_t sub_res_1 = {0};
  matrix_t sub_res_2 = {0};

  ck_assert_int_eq(
      0, s21_sub_matrix(&sum_res_1_transpose, &sum_res_2, &sub_res_1));
  ck_assert_int_eq(
      0, s21_sub_matrix(&sum_res_3_transpose, &sum_res_4, &sub_res_2));

  s21_remove_matrix(&sum_res_1_transpose);
  s21_remove_matrix(&sum_res_2);
  s21_remove_matrix(&sum_res_3_transpose);
  s21_remove_matrix(&sum_res_4);

  matrix_t mul_res_0 = {0};

  ck_assert_int_eq(0, s21_mult_matrix(&sub_res_1, &sub_res_2, &mul_res_0));

  s21_remove_matrix(&sub_res_1);
  s21_remove_matrix(&sub_res_2);

  matrix_t calc_complements_0 = {0};
  matrix_t inverse_0 = {0};
  matrix_t result = {0};

  ck_assert_int_eq(0, s21_calc_complements(&mul_res_0, &calc_complements_0));

  s21_remove_matrix(&mul_res_0);

  ck_assert_int_eq(0, s21_inverse_matrix(&calc_complements_0, &inverse_0));
  ck_assert_int_eq(0,
                   s21_mult_matrix(&calc_complements_0, &inverse_0, &result));

  s21_remove_matrix(&calc_complements_0);
  s21_remove_matrix(&inverse_0);

  matrix_t identity = {0};
  set_identity_matrix(&identity);
  ck_assert_double_matrix_eq_tol(&identity, &result);

  s21_remove_matrix(&result);
  s21_remove_matrix(&identity);
}
END_TEST

Suite *combined_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("combined_tests");
  tc = tcase_create("core");

  suite_add_tcase(s, tc);

  tcase_add_test(tc, combined_test_0);

  return s;
}