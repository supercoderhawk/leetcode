/*
 * Implement wildcard pattern matching with support for '?' and '*'.
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).

 * The matching should cover the entire input string (not partial).

 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)

 * Some examples:
 * isMatch("aa","a") ? false
 * isMatch("aa","aa") ? true
 * isMatch("aaa","aa") ? false
 * isMatch("aa", "*") ? true
 * isMatch("aa", "a*") ? true
 * isMatch("ab", "?*") ? true
 * isMatch("aab", "c*a*b") ? false
 * Created by supercoderx on 2017/8/14.
 */
#include "../main.h"

#include <stdio.h>

bool isWildcardMatch(char *s, char *p) {
    int patternLen = 0, ques = 0,asterisk =0;
    char *star = NULL, *ss = s, *tmp = p;
    bool all = true, other = false;
    while (*tmp != '\0') {
        patternLen++;
        if (*tmp != '*')
            all = false;
        if (*tmp == '?')
            ques++;
        if (*tmp != '?' && *tmp != '*')
            other = true;
        tmp++;
    }
    if (*s == '\0' && (other || ques > 0))
        return false;
    if (*s == '\0' && (patternLen > 0 && (all || !other && ques == 1)))
        return true;
    while (*s != '\0') {
        if (*p == '?' || (*p == *s)) {
            s++;
            p++;
            continue;
        }
        if (*p == '*') {
            star = p++;
            ss = s;
            continue;
        }
        if (star) {
            p = star + 1;
            s = ++ss;
            continue;
        }
        return false;
    }
    while(*p!='\0'){
        if(*p!='*')
            return false;
        p++;
    }
    return true;
}

void testIsWildcardMatch() {
    printf("%d", isWildcardMatch("a", "?*?"));
}