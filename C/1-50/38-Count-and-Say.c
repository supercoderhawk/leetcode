/*
 * Created by supercoderx on 2017/8/13.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *countAndSay(int n) {
    int len = 1, curLen = 0;
    char *str = malloc(sizeof(char) * (len)), *prevStr, say;
    str[0] = '1';
    if (n == 1)
        return str;
    int count = 0;
    for (int i = 1; i < n; i++) {
        prevStr = malloc(sizeof(char) * len);
        strncpy(prevStr, str, len);
        free(str);
        str = NULL;
        curLen = 0;
        say = prevStr[0];
        count = 1;
        for (int j = 1; j < len; ++j) {
            if (say == prevStr[j]) {
                count++;
            } else {
                if (str == NULL)
                    str = malloc(sizeof(char) * (curLen + 2));
                else
                    str = realloc(str, sizeof(char) * (curLen + 2));
                str[curLen] = (char) (count + 0x30);
                str[curLen + 1] = say;
                curLen += 2;
                say = prevStr[j];
                count = 1;
            }
        }
        if (str == NULL)
            str = malloc(sizeof(char) * (curLen + 2));
        else
            str = realloc(str, sizeof(char) * (curLen + 2));
        str[curLen] = (char) (count + 0x30);
        str[curLen + 1] = say;
        curLen += 2;
        len = curLen;
    }
    str = realloc(str, sizeof(char) * (len + 1));
    str[len] = '\0';
    return str;
}

void testCountAndSay() {
    printf("%s", countAndSay(13));
}