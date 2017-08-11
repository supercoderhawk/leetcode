/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 * For example, given n = 3, a solution set is:
 * [
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
 * ]
 * Created by supercoderx on 2017/8/10.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    if(n<=0){
        return NULL;
    }
    char **result = malloc(sizeof(char*)), *str = NULL;
    int *curLeft = malloc(sizeof(int)),*allLeft=malloc(sizeof(int)),count;

    for(int i = 0; i < 2*n;i++){
        if(i == 0 ){
            str = malloc(sizeof(char)*(2*n+1));
            str[0] = '(';
            str[2*n] = '\0';
            result[0] = str;
            curLeft[0] = 1;
            allLeft[0] = n-1;
            (*returnSize)++;
        }else{
            count = *returnSize;
            for(int j = 0; j<count;j++){
                if(curLeft[j]!=0 && allLeft[j]!=0){
                    str = malloc(sizeof(char)*(2*n+1));
                    str[2*n] = '\0';
                    strcpy(str,result[j]);
                    str[i] = '(';
                    result[j][i] = ')';
                    (*returnSize)++;
                    curLeft = realloc(curLeft,sizeof(int)*(*returnSize));
                    allLeft = realloc(allLeft,sizeof(int)*(*returnSize));
                    result = realloc(result, sizeof(char*)*(*returnSize));
                    curLeft[*returnSize-1] = curLeft[j]+1;
                    allLeft[*returnSize-1] = allLeft[j]-1;
                    result[*returnSize-1] = str;
                    curLeft[j]--;
                }else if(curLeft[j] == 0 && allLeft[j]>0){
                    result[j][i] = '(';
                    allLeft[j]--;
                    curLeft[j]++;
                }else if(allLeft[j]==0){
                    result[j][i]=')';
                    curLeft[j]--;
                }
            }
        }
    }
    return result;
}

void testGenerateParenthesis(){
    int count = 0;
    char** result = generateParenthesis(3,&count);
    for(int i = 0; i < count;i++){
        printf("%s,",result[i]);
    }

}
