#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

void fill_matrix(matrix_t *A);
void print_matrix(matrix_t *A);

int main(void) {
    matrix_t test = {};
    matrix_t result = {};
    s21_create_matrix(2, 2, &test);

    fill_matrix(&test);
    print_matrix(&test);

    s21_calc_complements(&test, &result);
    //s21_inverse_matrix(&test, &result);

    print_matrix(&result);

    return 0;
}

void fill_matrix(matrix_t *A) {
    double value;
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            scanf("%lf", &value);
            A->matrix[i][j] = value;
        }
    }
}

void print_matrix(matrix_t *A) {
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
            printf("%lf", A->matrix[i][j]);
            if (j != A->columns - 1) printf(" ");
        }
        printf("\n");
    }
}
