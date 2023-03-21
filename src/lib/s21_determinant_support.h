#ifndef SRC_LIB_S21_DETERMINANT_SUPPORT_H_
#define SRC_LIB_S21_DETERMINANT_SUPPORT_H_

#include "s21_matrix.h"

/**
 * @brief A function that checks the main diagonal of a matrix
 * for zero elements
 *
 * @param A Matrix to be checked
 * @return Result of check (SUCCESS/FAIL)
 */
int s21_diagonal_check(matrix_t *A);

/**
 * @brief A function that calculates matrix determinant via
 * Gaussian method
 *
 * @param A Matrix to be calculated
 * @return Determinant
 */
double s21_gaussian_method(matrix_t *A);

/**
 * @brief A function that divides row by A->matrix[row][column]
 *
 * @param A Matrix to be normalized
 * @param row Starting row
 * @param column Starting column
 * @return Multiplier by wich row was divided
 */
double s21_normalize(matrix_t *A, int row, int column);

/**
 * @brief A function that nullifies column under A->matrix[row][column]
 *
 * @param A Matrix to be nullified
 * @param row Starting row
 * @param column Starting column
 */
void s21_nullify(matrix_t *A, int row, int column);

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