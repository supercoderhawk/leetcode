#include <stdlib.h>
#include <stdio.h>
/*
 * Note: The returned array must be malloced, assume caller calls free().
 * Created by supercoderhawk on 2017/7/20.
 */


int* twoSum(int* nums, int numsSize, int target) {
    int* indices = (int *)malloc(sizeof(int)*2);
    for(int i = 0;i<numsSize;i++)
    {
        for(int j = i + 1; j < numsSize; j ++)
        {
            if (nums[i]+nums[j]== target)
            {
                indices[0] = i;
                indices[1] = j;
            }
        }
    }
    return indices;
}

void testTwoSum()
{
    const int nums[3] = {3,2,3};
    int* indices = twoSum(nums,3,6);
    for(int i = 0; i < 2; i ++)
    {
        printf("%d  ", indices[i]);
    }
}