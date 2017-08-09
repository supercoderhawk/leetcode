/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 * Created by supercoderx on 2017/8/9.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    char *str = NULL;
    if (strsSize == 0) {
        return "";
    }
    if (strsSize == 1) {
        return strs[0];
    }
    int lenArr[strsSize], len = 0, minLen = 0, curMinLen = 0;

    for (int i = 0; i < strsSize; i++) {
        str = strs[i];
        lenArr[i] = 0;
        while (*str != '\0') {
            lenArr[i]++;
            str++;
        }
    }
    minLen = lenArr[0];
    for (int i = 1; i < strsSize; i++) {
        curMinLen = 0;
        len = lenArr[i] > minLen ? minLen : lenArr[i];
        for (int j = 0; j < len; j++) {
            if (strs[i - 1][j] != strs[i][j])
                break;
            curMinLen++;
        }
        if (curMinLen < minLen)
            minLen = curMinLen;
    }
    if (minLen == 0)
        return "";
    str = malloc(sizeof(char) * (minLen + 1));
    str = strncpy(str, strs[strsSize - 1], minLen);
    str[minLen] = '\0';
    return str;
}

void testLongestCommonPrefix() {

    char *s1[] = {"aa", "b"};
    printf("%s", longestCommonPrefix(s1, 3));
}
