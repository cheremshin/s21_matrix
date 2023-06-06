#ifndef SRC_LIB_S21_DETERMINANT_SUPPORT_H_
#define SRC_LIB_S21_DETERMINANT_SUPPORT_H_

#include "s21_matrix.h"

/**
 * @brief A function that calculate determinant of second-order matrix
 *
 * @param A Matrix to be calculated
 * @return Determinant
 */
double s21_second_order_matrix_determinant(matrix_t *A);

/**
 * @brief A function that calculates matrix determinant via
 * minor method
 *
 * @param A Matrix to be calculated
 * @return Determinant
 */
double s21_minor_method(matrix_t *A);

#endif  // SRC_LIB_S21_DETERMINANT_SUPPORT_H_