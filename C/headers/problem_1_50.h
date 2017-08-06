/*
 * Created by supercoderhawk on 2017/7/23.
 */

#ifndef C_PROBLEM_1_50_H
#define C_PROBLEM_1_50_H

#include "../main.h"

// problem 1
int* twoSum(int* nums, int numsSize, int target);
void testTwoSum();

// problem 2
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);
void testAddTwoNumbers();

// problem 3
int lengthOfLongestSubstring(char* s);
void testLengthOfLongestSubstring();

// problem 5
char* longestPalindrome(char* s);
void testLongestPalindrome();

// problem 6
char* convert(char* s, int numRows);
void testConvert();

// problem 7
int reverse(int x);
void testReverse();

// problem 8
int myAtoi(char* str);
void testMyAtoi();

// problem 9
bool isPalindrome(int x);
void testIsPalindrome();

// problem 11
int maxArea(int* height, int heightSize);
void testMaxArea();
#endif //C_PROBLEM_1_50_H
