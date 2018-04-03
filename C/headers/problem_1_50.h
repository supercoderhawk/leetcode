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

// problem 4
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);
void testFindMedianSortedArrays();

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
bool isMatch(char* s, char* p);
void testIsMatch();

// problem 11
int maxArea(int* height, int heightSize);
void testMaxArea();

// problem 13
int romanToInt(char* s);
void testRomanToInt();

// problem 14
char *longestCommonPrefix(char **strs, int strsSize);
void testLongestCommonPrefix();

// problem 15
int** threeSum(int* nums, int numsSize, int* returnSize);
void testThreeSum();

// problem 17
char **letterCombinations(char *digits, int *returnSize);
void testLetterCombinations();

// problem 18
int **fourSum(int *nums, int numsSize, int target, int *returnSize);
void testFourSum();

// problem 20
bool isValid(char* s);
void testIsValid();

// problem 21
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
void testMergeTwoLists();

// problem 22
char** generateParenthesis(int n, int* returnSize);
void testGenerateParenthesis();

// problem 23
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);
void testMergeKLists();

// problem 26
int removeDuplicates(int* nums, int numsSize);
void testRemoveDuplicates();

// problem 28
int strStr(char* haystack, char* needle);
void testStrStr();

// problem 29
int divide(int dividend, int divisor);
void testDivide();

// problem 32
int longestValidParentheses(char* s);
void testLongestValidParentheses();

// problem 33
int search(int* nums, int numsSize, int target);
void testSearch();

// problem 34
int *searchRange(int *nums, int numsSize, int target, int *returnSize);
void testSearchRange();

// problem 36
bool isValidSudoku(char **board, int boardRowSize, int boardColSize);
void testIsValidSudoku();

// problem 38
char* countAndSay(int n);
void testCountAndSay();

// problem 41
int firstMissingPositive(int* nums, int numsSize);
void testFirstMissingPositive();

// problem 42
int trap(int* height, int heightSize);
void testTrap();

// problem 44
bool isWildcardMatch(char* s, char* p);
void testIsWildcardMatch();

// problem 46
int** permute(int* nums, int numsSize, int* returnSize);
void testPermute();

// problem 48
void rotate(int** matrix, int matrixRowSize, int matrixColSize);
void testRotate();

// problem 50
double myPow(double x, int n);
void testMyPow();
#endif //C_PROBLEM_1_50_H
