/*
 * Given a digit string, return all possible letter combinations that the number could represent.

 * Created by supercoderx on 2017/8/9.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **letterCombinations(char *digits, int *returnSize) {
    char *map[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int mapLen[] = {1, 1, 3, 3, 3, 3, 3, 4, 3, 4};
    int len = 0, count = 0, id = 0;
    char *tmp = digits, **result = NULL;

    while (*tmp != '\0') {
        len++;
        tmp++;
    }
    (*returnSize) = 0;

    for (int i = 0; i < len; i++) {
        id = digits[i] - 0x30;
        count = mapLen[id];
        if (i == 0) {
            result = malloc(sizeof(char *) * count);
            for (int j = 0; j < count; j++) {
                result[j] = malloc(sizeof(char) * (len + 1));
                result[j][0] = map[id][j];
                result[j][len] = '\0';
            }
            *returnSize = count;
        } else {
            result = realloc(result, sizeof(char *) * (*returnSize) * count);
            for (int j = 0; j < count; j++) {

                for (int k = 0; k < *returnSize; k++) {
                    if (j > 0) {
                        result[k + j * (*returnSize)] = malloc(sizeof(char) * (len + 1));
                        result[k + j * (*returnSize)][len] = '\0';
                        strncpy(result[k + j * (*returnSize)], result[k], i);
                    }
                    result[k + j * (*returnSize)][i] = map[id][j];
                }
            }
            (*returnSize) *= count;
        }
    }
    return result;
}

void testLetterCombinations() {
    char str[] = "23";
    int count = 0;
    char **result = letterCombinations(str, &count);
    for (int i = 0; i < count; i++) {
        printf("%s,", result[i]);
    }
}