/*
 * Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

 * Your algorithm's runtime complexity must be in the order of O(log n).

 * If the target is not found in the array, return [-1, -1].

 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 * Created by supercoderx on 2017/8/12.
 */
#include <stdio.h>
#include <stdlib.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
    *returnSize = 2;
    int *result = malloc(sizeof(int) * 2);
    result[0] = -1;
    result[1] = -1;
    if (numsSize == 0) {
        return result;
    }

    int left = 0, right = numsSize - 1, mid, start, end;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            start = end = mid;
            while (start >= 0) {
                if (nums[start] != nums[mid]) {
                    start++;
                    break;
                }
                if (start == 0) {
                    break;
                }
                start--;
            }
            while (end <= numsSize - 1) {
                if (nums[end] != nums[mid]) {
                    end--;
                    break;
                }
                if (end == numsSize - 1) {
                    break;
                }
                end++;
            }
            result[0] = start;
            result[1] = end;
            return result;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

void testSearchRange() {
    int a[] = {5, 7, 7, 7, 7, 8, 8, 10}, b[] = {1}, count = 0;
    int *res = searchRange(b, 1, 1, &count);

    printf("[%d,%d]", res[0], res[1]);

}