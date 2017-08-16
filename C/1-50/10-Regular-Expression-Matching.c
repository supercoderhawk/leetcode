/*
 * Implement regular expression matching with support for '.' and '*'.

 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.

 * The matching should cover the entire input string (not partial).

 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)

 * Some examples:
 * isMatch("aa","a") ? false
 * isMatch("aa","aa") ? true
 * isMatch("aaa","aa") ? false
 * isMatch("aa", "a*") ? true
 * isMatch("aa", ".*") ? true
 * isMatch("ab", ".*") ? true
 * isMatch("aab", "c*a*b") ? true
 * Created by supercoderx on 2017/8/11.
 */

#include "../main.h"
#include <stdio.h>

bool isMatch(char *s, char *p) {
    if (p == NULL || !*p) {
        return s == NULL || !*s;
    }
    if (s == NULL || !*s) {
        char *str = p;
        while (*str && str[1]) {
            if (str[1] != '*')
                return false;
            str += 2;
        }
        return *str ? false : true;
    }

    if (p[1] == '*')
        return isMatch(s, p + 2) || p != NULL && *p && (s[0] == p[0] || p[0] == '.') && isMatch(s + 1, p);
    else
        return p != NULL && *p && (s[0] == p[0] || p[0] == '.') && isMatch(s + 1, p + 1);

}

void testIsMatch() {
    char *s = "aa";
    char *p = ".*c";
    printf("%d", isMatch(s, p));
}