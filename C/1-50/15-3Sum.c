/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

 * Note: The solution set must not contain duplicate triplets.

 * For example, given array S = [-1, 0, 1, 2, -1, -4],

 * A solution set is:
 * [
    [-1, 0, 1],
    [-1, -1, 2]
 * ]
 * Created by supercoderx on 2017/8/9.
 */
#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int left, int right)
{
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];

    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
            /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
            序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
        {
            j--;/*向前寻找*/
        }

        a[i] = a[j];
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
        a[left]，那么就是给key）*/

        while(i < j && key >= a[i])
            /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
            因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }

        a[j] = a[i];
    }

    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    sort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    sort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
    /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int *pItem = NULL, **result = NULL;
    int tmp, sum = 0;
    *returnSize = 0;
    if (numsSize < 3) {
        return NULL;
    }

    // 冒泡排序
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - 1 - i; j++) {
            if (nums[j + 1] < nums[j]) {
                tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
    }
    // sort(nums,0,numsSize-1);

    // 寻找三元组
    for(int i = 0; i < numsSize-2;i++){
        // 去除元素1的重复
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        sum = -nums[i];
        int j = i+1,k=numsSize-1;
        while (j<k){
            if(nums[j]+nums[k]==sum){
                // 加进结果列表中
                pItem = malloc(sizeof(int)*3);
                pItem[0] = nums[i];
                pItem[1] = nums[j];
                pItem[2] = nums[k];
                (*returnSize)++;
                if(result == NULL){
                    result = malloc(sizeof(int*));
                    result[0] = pItem;
                }else{
                    result = realloc(result, sizeof(int*)*(*returnSize));
                    result[*returnSize-1] = pItem;
                }

                j ++;
                k --;
                // 去除元素2和元素3的重复
                while (nums[j]==nums[j-1] && j<k) j++;
                while (nums[k]==nums[k+1] && j<k) k--;
            }else if(nums[j]+nums[k]<sum){
                j++;
            } else{
                k--;
            }
        }
    }
    return result;
}

void testThreeSum(){
    int a[6] = {-1, 0, 1, 2, -1, -4}, count=0;
    int ** res = threeSum(a,6, &count);
    for(int i = 0;i<count;i++){
        printf("%d, %d, %d\n", res[i][0],res[i][1],res[i][2]);
    }

}