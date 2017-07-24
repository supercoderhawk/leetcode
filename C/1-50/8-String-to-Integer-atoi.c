/*
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 * Created by supercoderhawk on 2017/7/23.
 */
#include <stdio.h>
#include <limits.h>

int myAtoi(char* str) {
    char* tmp = str;
    int length = 0, negative = 0,digit = 0;
    long long result = 0, preResult = 0;
    while (*tmp != '\0')
    {
        length ++;
        tmp++;
    }

    // 处理开头空格
    while(str[0] == ' ')
    {
        str ++;
        length -- ;
    }
    if (length == 0)
        return 0;

    // 处理正负
    if(str[0] == '-')
        negative = 1;
    if(str[0] == '-' || str[0] == '+')
    {
        str ++;
        length --;
    }

    for(int i = 0; i < length; i++)
    {
        digit = (int)str[i];
        if( digit>= 0x30 && digit <= 0x39){
            preResult = result;
            result = result*10+digit-0x30;
            if(result<0 || preResult > result)
                if(negative)
                    return INT_MIN;
                else
                    return INT_MAX;
        }
        else{
            if(negative)
                result*= -1;
            if(result > INT_MAX )
                return INT_MAX;
            if (result < INT_MIN)
                return INT_MIN;
            return (int)result;
        }
    }
    if(negative)
        result*= -1;
    if(result > INT_MAX )
        return INT_MAX;
    if (result < INT_MIN)
        return INT_MIN;
    return (int)result;
}

void testMyAtoi()
{
    // printf("%d\n",myAtoi("   -0012a12"));
    // printf("%d\n",myAtoi("9223372036854775809"));
    printf("%d\n",myAtoi("18446744073709551617"));
    printf("%d\n",myAtoi("1"));
}