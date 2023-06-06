#include "s21_tests.h"

SRunner *default_srunner_create() {
  SRunner *sr;

  sr = srunner_create(calc_complements_suite());
  srunner_add_suite(sr, combined_suite());
  srunner_add_suite(sr, create_matrix_suite());
  srunner_add_suite(sr, determinant_suite());
  srunner_add_suite(sr, eq_suite());
  srunner_add_suite(sr, inverse_matrix_suite());
  srunner_add_suite(sr, mult_matrix_suite());
  srunner_add_suite(sr, mult_number_suite());
  srunner_add_suite(sr, sub_matrix_suite());
  srunner_add_suite(sr, sum_matrix_suite());
  srunner_add_suite(sr, transpose_suite());

  return sr;
}

int main(int argc, char *argv[]) {
  int exit_status = 1;
  int number_failed = 0;
  SRunner *sr = NULL;

  sr = default_srunner_create();

  srunner_set_log(sr, "test.log");
  srunner_run_all(sr, CK_NORMAL);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  if (number_failed == 0) {
    exit_status = 0;
  }

  return exit_status;
}
