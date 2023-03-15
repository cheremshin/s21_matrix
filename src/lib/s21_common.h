#ifndef SRC_LIB_S21_COMMON_H_
#define SRC_LIB_S21_COMMON_H_

#include "s21_matrix.h"

/**
 * @brief A function that compares matrices dimension
 * 
 * @param A Matrix to be compared
 * @param B Matrix to be compared
 * @return Comparison result (SUCCESS/FAILURE)
 */
int s21_eq_dimension(matrix_t *A, matrix_t *B);

/**
 * @brief A function that checks matrix on equality of rows and columns
 * 
 * @param A Matrix to be checked
 * @return Check result (SUCCESS/FAILURE)
 */
int s21_check_on_square(matrix_t *A);

/**
 * @brief A function that copies matrix
 * 
 * @param A Matrix to be copied
 * @param result Matrix to copy to
 */
void s21_copy_matrix(matrix_t *A, matrix_t *result);

/**
 * @brief A function that calculates sign
 * 
 * @param row Matrix row
 * @param column Matrix column
 * @return Sign
 */
int s21_sign(int row, int column);

/**
 * @brief A function that finds minor of A->matrix[row][column]
 * 
 * @param A Matrix where find
 * @param row Matrix row
 * @param column Matrix column
 * @param result Minor
 */
void s21_get_minor(matrix_t *A, int row, int column, matrix_t *result);

#endif  // SRC_LIB_S21_COMMON_H_