/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 * Created by supercoderhawk on 2017/7/24.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../main.h"

bool isPalindrome(int x) {
    if(x == 0)
        return true;
    if(x<0)
        return false;
    int length = 0, num = x;
    int *digits = (int*)malloc(sizeof(int)*10);

    while(num!=0)
    {
        digits[length++] = num%10;
        num/=10;
    }
    if(length == 1)
        return true;

    for(int i = 0; i < length/2;i++)
    {
        if(digits[i] != digits[length-1-i])
            return false;
    }
    return true;
}

void testIsPalindrome()
{
    printf("%d\n", isPalindrome(54245));
    printf("%d\n", isPalindrome(54246));
    printf("%d\n", isPalindrome(112211));
    printf("%d\n", isPalindrome(1000000001));
}