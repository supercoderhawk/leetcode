/*
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *  Given "abcabcbb", the answer is "abc", which the length is 3.
 *  Given "bbbbb", the answer is "b", with the length of 1.
 *  Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *  Created by supercoderhawk on 2017/7/23.
 */
#include <stdio.h>
#include "../main.h"


int lengthOfLongestSubstring(char* s) {
    int start =0, end = 0,digit = 0, maxLength = 0;
    char* p = s;
    int letters[128];
    for(int i = 0; i < 128; i++)
        letters[i] = 0;

    while(*p != '\0')
    {
        digit = (int)*p;
        while(letters[digit] != 0)
        {
            letters[(int)s[start]] = 0;
            start += 1;
        }
        letters[digit] = 1;
        end += 1;
        if (end - start > maxLength)
            maxLength = end-start;
        p = p + 1;
    }
    return maxLength;
}

void testLengthOfLongestSubstring()
{
    char *p="pwwkew";
    printf("%d",lengthOfLongestSubstring(p));
}