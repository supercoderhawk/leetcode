/*
 * You are given an n x n 2D matrix representing an image.

 * Rotate the image by 90 degrees (clockwise).

 * Follow up:
 * Could you do this in-place?
 * Created by supercoderx on 2017/8/14.
 */
#include <stdio.h>
#include <stdlib.h>

void rotate(int **matrix, int matrixRowSize, int matrixColSize) {
    int tmp;
    for (int i = 0; i < matrixRowSize / 2; i++) {
        if (2 * i == matrixRowSize - 1)
            break;
        for (int j = i; j < matrixRowSize - i - 1; j++) {
            // 上<->右
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][matrixRowSize - 1 - i];
            matrix[j][matrixRowSize - 1 - i] = tmp;
            // 下<->左
            tmp = matrix[matrixRowSize - 1 - j][i];
            matrix[matrixRowSize - 1 - j][i] = matrix[matrixRowSize - 1 - i][matrixColSize - 1 - j];
            matrix[matrixRowSize - 1 - i][matrixColSize - 1 - j] = tmp;
            // 上<->下
            tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixColSize - 1 - i][matrixRowSize - 1 - j];
            matrix[matrixColSize - 1 - i][matrixRowSize - 1 - j] = tmp;
        }
    }
}

void testRotate() {
    int count = 3, **matrix = malloc(sizeof(int *) * count);
    matrix[0] = malloc(sizeof(int) * count);
    matrix[1] = malloc(sizeof(int) * count);
    matrix[2] = malloc(sizeof(int) * count);
    //matrix[3] = malloc(sizeof(int)*count);
    //matrix[4] = malloc(sizeof(int)*count);

    for (int k = 0; k < count; ++k) {
        for (int i = 0; i < count; ++i) {
            matrix[k][i] = k * count + i + 1;
        }
    }
    rotate(matrix, count, count);
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; ++j) {
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }


}