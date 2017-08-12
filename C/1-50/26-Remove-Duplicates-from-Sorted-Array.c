/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

 * Do not allocate extra space for another array, you must do this in place with constant memory.

 * For example,
 * Given input array nums = [1,1,2],

 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 * Created by supercoderx on 2017/8/11.
 */

#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
    int len = numsSize;
    if (numsSize <= 1)
        return numsSize;
    int i = 0;
    while (i < len - 1) {
        if (nums[i] == nums[i + 1]) {
            for (int j = i + 1; j < len; j++) {
                nums[j - 1] = nums[j];
            }
            len--;
            i--;
        }
        i++;
    }

    return len;
}

void testRemoveDuplicates() {
    int a1[] = {1, 1, 1, 2, 2, 3, 4, 4};
    int count = removeDuplicates(a1, 7);
    for (int i = 0; i < count; i++)
        printf("%d,", a1[i]);
}