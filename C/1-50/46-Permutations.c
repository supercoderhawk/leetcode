/*
 * Given a collection of distinct numbers, return all possible permutations.

 * For example,
 * [1,2,3] have the following permutations:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 * Created by supercoderx on 2017/8/14.
 */
#include <stdio.h>
#include <stdlib.h>

void backtrack(int **result, int *rowIndex, int *row, int colIndex, int *nums, int numsSize) {
    if (colIndex == numsSize) {
        int *r = malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; ++i) {
            r[i] = row[i];
        }

        result[(*rowIndex)++] = r;
        return;
    }
    for (int i = 0; i < numsSize; ++i) {
        int j;
        for (j = 0; j < colIndex; ++j) {
            if (nums[i] == row[j])
                break;
        }
        if (j != colIndex)
            continue;
        row[colIndex] = nums[i];
        backtrack(result, rowIndex, row, colIndex + 1, nums, numsSize);
    }
}

int **permute(int *nums, int numsSize, int *returnSize) {
    *returnSize = 0;
    if (numsSize == 0)
        return NULL;

    for (int i = 1; i <= numsSize; i++)
        *returnSize *= i;
    int **result = malloc(sizeof(int *) * (*returnSize)), *row = malloc(sizeof(int) * numsSize);

    *returnSize = 0;
    backtrack(result, returnSize, row, 0, nums, numsSize);
    free(row);

    return result;
}

void testPermute() {
    int a[] = {1, 2, 3, 4}, count = 1, size = 0;
    int **result = permute(a, count, &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < count; j++) {
            printf("%d,", result[i][j]);
        }
        printf("\n");
    }
}