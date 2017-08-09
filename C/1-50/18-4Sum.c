/*
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 * Note: The solution set must not contain duplicate quadruplets.

 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

 * A solution set is:
 * [
    [-1,  0, 0, 1],
    [-2, -1, 1, 2],
    [-2,  0, 0, 2]
 * ]
 * Created by supercoderx on 2017/8/9.
 */
#include <stdio.h>
#include <stdlib.h>

int **fourSum(int *nums, int numsSize, int target, int *returnSize) {
    *returnSize = 0;
    if (numsSize < 4) {
        return NULL;
    }

    int p, q, sum, tmp, counter = 0, **result = NULL, *item = NULL;

    // 排序
    for (int m = 0; m < numsSize - 1; m++) {
        for (int n = 0; n < numsSize - 1 - m; n++) {
            if (nums[n] > nums[n + 1]) {
                tmp = nums[n];
                nums[n] = nums[n + 1];
                nums[n + 1] = tmp;
            }
        }
    }

    // 挑序列
    for (int j = numsSize - 1; j > 2; j--) {
        for (int i = 0; i < j - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i] || j < numsSize - 1 && nums[j] == nums[j + 1]) {
                continue;
            }
            sum = target - nums[i] - nums[j];
            p = i + 1;
            q = j - 1;
            while (p < q) {
                if (nums[p] + nums[q] == sum) {
                    item = malloc(sizeof(int) * 4);
                    item[0] = nums[i];
                    item[1] = nums[p];
                    item[2] = nums[q];
                    item[3] = nums[j];
                    (*returnSize)++;
                    if (result == NULL) {
                        result = malloc(sizeof(int *));
                    } else {
                        result = realloc(result, sizeof(int *) * (*returnSize));
                    }
                    result[*returnSize - 1] = item;
                    p++;
                    q--;
                    while (p < q && nums[p - 1] == nums[p]) p++;
                    while (p < q && nums[q + 1] == nums[q]) q--;
                } else if (nums[p] + nums[q] < sum) {
                    p++;
                } else {
                    q--;
                }
            }
        }
    }
    return result;
}

void testFourSum() {
    int a[] = {1, 0, -1, 0, -2, 2};
    int b[] = {-3, -1, 0, 2, 4, 5};
    int target = 0, count = 0;
    // int **result = fourSum(a, 6, target, &count);
    int **result = fourSum(b, 6, target, &count);
    for (int i = 0; i < count; i++) {
        printf("%d,%d,%d,%d\n", result[i][0], result[i][1], result[i][2], result[i][3]);
    }

}