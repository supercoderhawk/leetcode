/*
 * Given a roman numeral, convert it to an integer.

 * Input is guaranteed to be within the range from 1 to 3999.
 * Created by supercoderx on 2017/8/11.
 */
#include <stdio.h>

int romanToInt(char *s) {
    char chs[] = "IVXLCDM";
    int chsNum[] = {1, 5, 10, 50, 100, 500, 1000}, len = 0, chsLen = 7, id, prevId, res = 0;

    char *ch = s;
    while (*ch != '\0') {
        ch++;
        len++;
    }

    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < chsLen; j++)
            if (s[i] == chs[j]) {
                id = j;
                break;
            }
        if (i == len - 1) {
            res = chsNum[id];
            prevId = id;
        } else {
            if (chsNum[id] < chsNum[prevId])
                res -= chsNum[id];
            else
                res += chsNum[id];
            prevId = id;
        }
    }

    return res;
}

void testRomanToInt() {
    char *s1 = "IV";
    printf("%d", romanToInt(s1));
}