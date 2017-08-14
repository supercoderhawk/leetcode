/*
 * Given an unsorted integer array, find the first missing positive integer.

 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.

 * Your algorithm should run in O(n) time and uses constant space.
 * Created by supercoderx on 2017/8/13.
 */
#include <stdio.h>

int firstMissingPositive(int *nums, int numsSize) {
    int tmp;
    for (int i = 0; i < numsSize; ++i) {
        while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
            tmp = nums[i];
            nums[i] = nums[tmp - 1];
            nums[tmp - 1] = tmp;
        }
    }
    for (int j = 0; j < numsSize; ++j) {
        if (nums[j] != j + 1)
            return j + 1;
    }
    return numsSize + 1;
}

void testFirstMissingPositive() {
    int a[] = {2, 1};
    printf("%d", firstMissingPositive(a, 2));
}
