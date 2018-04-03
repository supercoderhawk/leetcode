/*
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * Created by supercoderhawk on 2017/8/21.
 */
#include <stdio.h>
#include <stdlib.h>

void setZeroes(int **matrix, int matrixRowSize, int matrixColSize) {
    int isRow = 0;
    for (int i = 0; i < matrixRowSize; ++i) {
        for (int j = 0; j < matrixColSize; ++j) {
            if (matrix[i][j] == 0) {
                if (i == 0) {
                    isRow = 1;
                    matrix[0][j] = 0;
                } else {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
    }

    for (int k = 1; k < matrixRowSize; ++k) {
        if (matrix[k][0] == 0)
            for (int i = 0; i < matrixColSize; ++i) {
                matrix[k][i] = 0;
            }
    }

    for (int l = 1; l < matrixColSize; ++l) {
        if (matrix[0][l] == 0) {
            for (int i = 1; i < matrixRowSize; ++i) {
                matrix[i][l] = 0;
            }
        }
    }
    if (matrix[0][0] == 0)
        for (int m = 0; m < matrixRowSize; ++m) {
            matrix[m][0] = 0;
        }
    if (isRow)
        for (int n = 0; n < matrixColSize; ++n) {
            matrix[0][n] = 0;
        }
}

void testSetZeroes() {
    int **m = malloc(sizeof(int *) * 2);
    m[0] = malloc(sizeof(int) * 3);
    m[1] = malloc(sizeof(int) * 3);
    m[0][0] = 1;
    m[0][1] = 1;
    m[0][2] = 1;
    m[1][0] = 0;
    m[1][1] = 1;
    m[1][2] = 2;

    setZeroes(m, 2, 3);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d,", m[i][j]);
        }
    }
}