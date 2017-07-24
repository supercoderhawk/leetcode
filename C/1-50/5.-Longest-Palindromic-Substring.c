/*
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * Example:
 *  Input: "babad"
 *  Output: "bab"
 *  Note: "aba" is also a valid answer.
 * Created by supercoderhawk on 2017/7/23.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestPalindrome(char *s) {
    if (s == NULL)
        return s;
    int maxLength = 0, maxStart = 0, maxEnd = 0, length = 0, isReverse = 0;
    int start = -1, end = -1,reverseStart = 0,reverseEnd = 0;
    char *pStr = s;
    while (*pStr != '\0') {
        length++;
        pStr++;
    }

    char *reverseStr = (char *) malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        reverseStr[i] = s[length - 1 - i];
    }
    reverseStr[length] = '\0';
    for (int i = 1; i <= length; i++) {
        start = end = reverseStart = reverseEnd = -1;
        for (int j = 0; j < i; j++) {
            if (start == -1 && s[j] == reverseStr[length - i + j]) {
                start = j;
                reverseStart = i - j;
            } else if (start != -1 && s[j] != reverseStr[length - i + j]) {
                end = j;
                reverseEnd =  i - j;
                if( start == reverseEnd && end == reverseStart)
                {
                    if (end - start > maxLength) {
                        maxLength = end - start;
                        maxEnd = end;
                        maxStart = start;
                    }
                }
                start = end = -1;
            }
        }
        if (start != -1 && end == -1)
        {
            end = i;
            reverseEnd = 0;
            if( start == reverseEnd && end == reverseStart)
            {
                if (end - start > maxLength) {
                    maxLength = end - start;
                    maxEnd = end;
                    maxStart = start;
                }
            }
        }

    }
    for (int i = 1; i <= length; i++) {
        start = end = -1;
        for (int j = 0; j < i; j++) {
            if (start == -1 && s[length - i + j] == reverseStr[j]) {
                start = j;
                reverseStart =  i - j;
            } else if (start != -1 && s[length - i + j] != reverseStr[j]) {
                end = j;
                reverseEnd = i - j;
                if( start == reverseEnd && end == reverseStart)
                {
                    if (end - start > maxLength) {
                        maxLength = end - start;
                        maxEnd = end;
                        maxStart = start;
                        isReverse = 1;
                    }
                }
                start = end = -1;
            }
        }
        if (start != -1 && end == -1)
        {
            end = i;
            reverseEnd = 0;
            if( start == reverseEnd && end == reverseStart)
            {
                if (end - start > maxLength) {
                    maxLength = end - start;
                    maxEnd = end;
                    maxStart = start;
                    isReverse = 1;
                }
            }
        }


    }

    if (maxEnd - maxStart == 0)
        return '\0';
    char *palindrome = (char *) malloc(sizeof(char) * (maxEnd - maxStart + 1));
    if (isReverse)
        strncpy(palindrome, reverseStr + maxStart, maxEnd - maxStart);
    else
        strncpy(palindrome, s + maxStart, maxEnd - maxStart);
    palindrome[maxEnd - maxStart] = '\0';
    return palindrome;
}

void testLongestPalindrome() {
    char *s1 = "b";
    printf("%s\n", longestPalindrome(s1));
    char *s2 = "babad";
    printf("%s\n", longestPalindrome(s2));
    char *s3 = "abb";
    printf("%s\n", longestPalindrome(s3));
    char *s4 = "abcdasdfghjkldcba";
    printf("%s\n", longestPalindrome(s4));
    char *s5 = "cbbd";
    printf("%s\n", longestPalindrome(s5));
    char *s6 = "babaddtattarrattatddetartrateedredividerb";
    printf("%s\n", longestPalindrome(s6));
}

