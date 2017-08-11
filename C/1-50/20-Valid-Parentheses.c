/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * Created by supercoderx on 2017/8/9.
 */

#include <stdio.h>
#include "../main.h"

bool isValid(char* s) {
    char* tmp=s;
    int len = 0, index = -1;

    while (*tmp!='\0'){
        len++;
        tmp++;
    }

    char indicator[len] ;
    for(int i = 0; i < len;i++){
        switch (s[i]){
            case '{':
                indicator[++index]='{';
                break;
            case '}':
                if(index==-1 || indicator[index]!='{'){
                    return false;
                }else{
                    index--;
                }
                break;
            case '[':
                indicator[++index]='[';
                break;
            case ']':
                if(index == -1 || indicator[index]!='['){
                    return false;
                } else{
                    index--;
                }
                break;
            case '(':
                indicator[++index] = '(';
                break;
            case ')':
                if(index == -1 || indicator[index]!='('){
                    return false;
                } else{
                    index--;
                }
                break;
            default:
                break;
        }
    }
    return index == -1?true:false;
}

void testIsValid(){
    char s[] = "[(](";
    printf("%d",isValid(s));
}