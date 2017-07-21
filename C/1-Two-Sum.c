#include <malloc.h>

/*
 * Note: The returned array must be malloced, assume caller calls free().
 * Created by supercoderhawk on 2017/7/20.
 */


int* twoSum(int* nums, int numsSize, int target) {
    int* indices = (int *)malloc(sizeof(int)*2);
    for(int i = 0;i<numsSize-1;i++)
    {
        if (nums[i]+nums[i+1]== target)
        {
            indices[0] = i;
            indices[1] = i + 1;
        }
    }
    return indices;
}