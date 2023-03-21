#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <stdlib.h>

/**
 * Structure that represents matrix in C language
 */
typedef struct matrix_struct {
  double **matrix; /**< Pointer to a memory area that stores the values of the
                      matrix cells */
  int rows;        /**< Number of rows */
  int columns;     /**< Number of columns */
} matrix_t;

#define EPSILON 1e-6

/**************************
 *       Exit codes       *
 *************************/

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif  // EXIT_SUCCESS

#ifndef EXIT_INCORRECT_MATRIX
#define EXIT_INCORRECT_MATRIX 1
#endif  // EXIT_INCORRECT_MATRIX

#ifndef EXIT_CALCULATION_ERROR
#define EXIT_CALCULATION_ERROR 2
#endif  // EXIT_CALCULATION_ERROR

/**************************
 *   Comparison results   *
 *************************/

#ifndef SUCCESS
#define SUCCESS 1
#endif  // SUCCESS

#ifndef FAILURE
#define FAILURE 0
#endif  // FAILURE

/**************************
 *   Matrix operations    *
 *************************/

/**
 * @brief A function that creates a matrix of dimension rows * columns
 *
 * @param rows Number of rows in the created matrix
 * @param columns Number of columns int the created matrix
 * @param result Pointer to created matrix_t structure
 * @return Error code
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

/**
 * @brief A function that clears memory used to store matix_t structure
 *
 * @param A Matrix to be cleared
 */
void s21_remove_matrix(matrix_t *A);

/**
 * @brief A function that compares two matrices
 *
 * @param A Matrix to be compared
 * @param B Matrix to be compared
 * @return Comparison result (SUCCESS/FAILURE)
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief A function that sums two matrices
 *
 * @param A Matrix to be summed
 * @param B Matrix to be summed
 * @param result Resulting matrix
 * @return Error code
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief A function that subtracts another from one matrix
 *
 * @param A Minuend matrix
 * @param B Subtrahend matrix
 * @param result Resulting matrix
 * @return Error code
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief A function that multiplies a matrix by a scalar
 *
 * @param A Matrix to be multiplied
 * @param number The scalar to be multiplied by
 * @param result Resulting matrix
 * @return Error code
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

/**
 * @brief A function that multiplies a matrix by another one
 *
 * @param A Multiplicanda matrix
 * @param B Multiplier matrix
 * @param result Resulting matrix
 * @return Error code
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief A function that transpose matrix
 *
 * @param A Matrix to be transposed
 * @param result Resulting matrix
 * @return Error code
 */
int s21_transpose(matrix_t *A, matrix_t *result);

/**
 * @brief A function that calculates algebraic complement matrix
 *
 * @param A Matrix to be calculated
 * @param result Resulting matrix
 * @return Error code
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);

/**
 * @brief A function that calculates matrix determinant
 *
 * @param A Matrix to be calculated
 * @param result Determinant
 * @return Error code
 */
int s21_determinant(matrix_t *A, double *result);

/**
 * @brief A function that inverts matrix
 *
 * @param A Matrix to be inverted
 * @param result Resulting matrix
 * @return Error code
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // SRC_S21_MATRIX_H_