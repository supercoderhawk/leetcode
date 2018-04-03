/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

 * Each element in the array represents your maximum jump length at that position.

 * Determine if you are able to reach the last index.

 * For example:
 * A = [2,3,1,1,4], return true.

 * A = [3,2,1,0,4], return false.
 * Created by supercoderhawk on 2017/8/17.
 */

#include "../main.h"
#include <stdio.h>

bool canJump(int *nums, int numsSize) {
    if (numsSize == 0)
        return false;

    int i = 0, maxJump;
    for (int reach = 0; i < numsSize && i <= reach; ++i) {
        maxJump = nums[i] + i;
        reach = reach > maxJump ? reach : maxJump;
    }
    return i == numsSize;
}

void testCanJump() {
    int nums[] = {2, 3, 1, 1, 4};
    int nums1[] = {3, 2, 1, 0, 4};
    printf("%d", canJump(nums, sizeof(nums) / sizeof(int)));
}