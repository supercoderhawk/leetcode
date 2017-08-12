/*
 * Implement strStr().

 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * Created by supercoderx on 2017/8/11.
 */
#include <stdio.h>

int strStr(char *haystack, char *needle) {
    int len = 0, subLen = 0, diff = 0, isContain = 1;
    char *str = haystack;
    while (*str != '\0') {
        len++;
        str++;
    }
    str = needle;
    while (*str != '\0') {
        subLen++;
        str++;
    }

    if (subLen > len)
        return -1;

    diff = len - subLen;
    for (int i = 0; i < diff + 1; i++) {
        for (int j = i; j < i + subLen; j++) {
            if (haystack[j] != needle[j - i]) {
                isContain = 0;
                break;
            }
        }
        if (isContain == 1)
            return i;
        isContain = 1;
    }
    return -1;
}

void testStrStr() {
    char *s1 = "abcdefg";
    char *s2 = "bcd";
    printf("%d", strStr(s1, s2));
}