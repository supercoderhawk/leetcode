/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 * You are given a target value to search. If found in the array return its index, otherwise return -1.

 * You may assume no duplicate exists in the array.
 * Created by supercoderx on 2017/8/11.
 */
#include <stdio.h>

int search(int *nums, int numsSize, int target) {
    if (numsSize == 0)
        return -1;
    if (numsSize == 1) {
        return nums[0] == target ? 0 : -1;
    }
    int left = 0, right = numsSize - 1, mid, num;

    // 寻找最小值，即反转点
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }

    int rot = left;
    left = 0;
    right = numsSize - 1;
    int realMid;
    while (left <= right) {
        mid = (left + right) / 2;
        realMid = (mid + rot) % numsSize;
        if (nums[realMid] == target)
            return realMid;
        else if (nums[realMid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void testSearch() {
    int a[] = {3, 1};
    printf("%d", search(a, 2, 3));
}