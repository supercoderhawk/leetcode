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
int** permute(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    if(numsSize == 0)
        return NULL;
    *returnSize = 1;
    
    for(int i = 1; i <=numsSize;i++)
        *returnSize *= i;

    int ** result = malloc(sizeof(int*)**returnSize);
    for(int i = 0;i < *returnSize;i++)
        result[i] = malloc(sizeof(int)*numsSize);
    int start = 0,index = start,cur=*returnSize;
    for(int i = 0; i <numsSize;i++){
            index = start-1;
        cur/=numsSize;
        for(int j =0; j<*returnSize;j++){
            result[j][i] = nums[++index%numsSize];
        }
        start++;
    }

    return result;
}

void testPermute(){
    int a[] = {1,2,3},count = 0;
    int** result = permute(a,3,&count);
    for(int i = 0; i <count;i++){
        for(int j =0 ;j<3;j++){
            printf("%d,",result[i][j]);
        }
        printf("\n");
    }
}