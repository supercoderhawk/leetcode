/*
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

 * You may assume the integer do not contain any leading zero, except the number 0 itself.

 * The digits are stored such that the most significant digit is at the head of the list.
 * Created by supercoderhawk on 2017/8/18.
 */
#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize = digitsSize;
    int *result = malloc(sizeof(int)*digitsSize), plus;
    result[digitsSize-1] = (digits[digitsSize-1]+1)%10;
    plus = (digits[digitsSize-1]+1)/10;
    for (int i = digitsSize-2; i >=0 ; --i) {
        if(plus!=0){
            result[i] = (digits[i]+1)%10;
            plus = (digits[i]+1)/10;
        }else{
            result[i] = digits[i];
        }
    }
    if(plus!=0){
        result = realloc(result, sizeof(int)*(digitsSize+1));
        for (int i = digitsSize-1; i >=0 ; --i) {
            result[i+1] = result[i];
        }
        result[0] = plus;
        (*returnSize)++;
    }

    return result;
}

void testPlusOne(){
    int a[] = {1,1,9},count=0;
    int* res = plusOne(a,sizeof(a)/ sizeof(int),&count);
    for (int i = 0; i <count ; ++i) {
        printf("%d,",res[i]);
    }
}