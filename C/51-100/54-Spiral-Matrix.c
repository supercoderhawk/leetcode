/*
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

 * For example,
 * Given the following matrix:

 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 * Created by supercoderhawk on 2017/8/16.
 */
#include <stdio.h>
#include <stdlib.h>

int *spiralOrder(int **matrix, int matrixRowSize, int matrixColSize) {
    int isRow = 0;  // 最内圈为行，包括一个数字
    int isCol = 0;  // 最内圈为列

    if (matrixRowSize > matrixColSize)
        isCol = 1;
    if (matrixColSize > matrixRowSize || matrixColSize == matrixRowSize && matrixColSize % 2)
        isRow = 1;

    int *result = malloc(sizeof(int) * (matrixColSize * matrixRowSize));
    int count = isRow ? matrixRowSize / 2 : matrixColSize / 2;
    int index = 0;
    for (int i = 0; i < count; ++i) {
        // 行
        for (int col = i; col < matrixColSize - 1 - i; col++) {
            result[index + col - i] = matrix[i][col];
            result[index + matrixRowSize + matrixColSize - 2 - 5 * i + col] = matrix[matrixRowSize - 1 - i][
                    matrixColSize - 1 - col];
        }
        // 列
        for (int r = i; r < matrixRowSize - 1 - i; ++r) {
            result[index + matrixColSize - 1 - 3 * i + r] = matrix[r][matrixColSize - 1 - i];
            result[index + 2 * matrixColSize + matrixRowSize - 3 - 7 * i + r] = matrix[matrixRowSize - 1 - r][i];
        }
        index += 2 * matrixColSize + 2 * matrixRowSize - 4 - 4 * i;
    }

    if (index == matrixColSize * matrixRowSize)
        return result;

    if (isRow) {
        for (int i = count; i < matrixColSize - count; ++i) {
            result[index++] = matrix[matrixRowSize / 2][i];
        }
    }
    if (isCol) {
        for (int i = count; i < matrixColSize - count; ++i) {
            result[index++] = matrix[i][matrixColSize / 2];
        }
    }

    return result;

}

void testSpiralOrder() {
    int **m = malloc(sizeof(int *)), rowCount = 10, colCount = 10, *row;
    for (int i = 0; i < rowCount; ++i) {
        row = malloc(sizeof(int) * colCount);
        for (int j = 0; j < colCount; ++j) {
            row[j] = i * colCount + j + 1;
        }
        m[i] = row;
    }
    int *res = spiralOrder(m, rowCount, colCount);
    for (int i = 0; i < rowCount * colCount; ++i) {
        printf("%d,", res[i]);
    }
}
