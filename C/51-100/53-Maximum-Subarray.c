/*
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 * Created by supercoderx on 2017/8/15.
 */
#include <stdio.h>
#include <limits.h>
int maxSubArray(int* nums, int numsSize) {
    if(numsSize == 1)
        return nums[0];
    int sum=0,maxSum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum+=nums[i];
        if(sum>maxSum)
            maxSum = sum;
        else if(sum<0)
            sum = 0;
    }
    return maxSum;
}

void testMaxSubArray(){
    // int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    int a[] = {-2,-1};
    printf("%d",maxSubArray(a,sizeof(a)/sizeof(int)));
}