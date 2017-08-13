/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 * For "(()", the longest valid parentheses substring is "()", which has length = 2.

 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 * Created by supercoderx on 2017/8/12.
 */
#include <stdio.h>
int longestValidParentheses(char* s) {
    int len = 0;
    char* ch = s;
    while(*ch!='\0'){
        ch++;
        len++;
    }
    if(len == 0)
        return 0;
    int stack[len],top = -1, longest = -1;
    for(int i = 0;i < len;i++){
      if(s[i]=='(')
          stack[++top] = i;
      else{
          if(top>-1){
            if(s[stack[top]] == '(')
                top--;
            else
                stack[++top] = i;
          }else
              stack[++top] = i;
      }
    }
    if(top == -1)
        return len;

    int a=len,b,curLen = -1;
    while(top>-1){
        b = stack[top];
        curLen = a-b-1;
        longest = longest>curLen?longest:curLen;
        a = b;
        top--;
    }
    return a>longest?a:longest;
}

void testLongestValidParentheses(){
    char* s1 = "()(())";
    printf("%d",longestValidParentheses(s1));
}