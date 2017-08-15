/*
 * Given an array of strings, group anagrams together.

 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Return:
 *
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Created by supercoderx on 2017/8/15.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    *returnSize = 0;
    if(strsSize == 0)
        return NULL;
    int strSize[strsSize],len=0,**hash = NULL,*hashLen =NULL,*rowLen=NULL,*word,id,*col;
    char *s,***result=NULL,**row=NULL,*w;
    columnSizes = NULL;

    for (int i = 0; i <strsSize ; ++i) {
        strSize[i] = 0;
        s = strs[i];
        while(*s!='\0'){
            strSize[i]++;
            s++;
        }
    }
    for (int j = 0; j < strsSize; ++j) {
            if(hash == NULL){
                word = malloc(sizeof(int)*26);
                for (int i = 0; i < 26; ++i) {
                    word[i] = 0;
                }
                for (int k = 0; k < strSize[j]; ++k) {
                    word[strs[j][k]-'a']++;
                }
                hash = malloc(sizeof(int*));
                hash[len] = word;
                hashLen = malloc(sizeof(int));
                hashLen[len++] = strSize[j];
                row = malloc(sizeof(char*));
                row[0] = strs[j];
                result = malloc(sizeof(char**));
                result[0] = row;
                columnSizes = malloc(sizeof(int*));
                col= malloc(sizeof(int));
                col[0] = strSize[j];
                columnSizes[0] = col;
                rowLen = malloc(sizeof(int));
                rowLen[0] = 1;
            } else{
                int i;
                for (i = 0; i <len ; ++i) {
                    if(strSize[j]!=hashLen[i])
                        continue;
                    word = malloc(sizeof(int)*26);
                    for (int p = 0; p < 26; ++p) {
                        word[p] = 0;
                    }
                    for (int k = 0; k < strSize[j]; ++k) {
                        word[strs[j][k]-'a']++;
                    }
                    int l;
                    for (l = 0; l <26 ; ++l) {
                        if(word[l]!=hash[i][l])
                            break;
                    }
                    free(word);
                    if(l != 26 )
                        continue;
                    id = 0;
                    for (int m = 0; m < rowLen[i]-1; ++m) {
                        if(strcmp(strs[j],result[i][m])>=0 &&strcmp(strs[j],result[i][m])<=0){

                        }
                    }
                }
            }
    }

}