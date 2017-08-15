//
// Created by supercoderhawk on 2017/7/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "headers/problem_1_50.h"
#include "headers/problem_51_100.h"
#include "headers/problem_151_200.h"
#include "headers/problem_201_250.h"
#include "headers/problem_301_350.h"

struct ListNode *createList(const int *vals, int count) {
    struct ListNode *header = NULL, *tmp, *p = NULL;
    for (int i = 0; i < count; i++) {
        tmp = (struct ListNode *) malloc(sizeof(struct ListNode *));
        tmp->val = vals[i];
        tmp->next = NULL;
        if (header == NULL) {
            header = p = tmp;
        } else {
            p->next = tmp;
            p = tmp;
        }
    }
    return header;
}

void printList(struct ListNode *l) {
    struct ListNode *p = l;
    while (p != NULL) {
        printf("%d", p->val);
        p = p->next;
        if (p != NULL) {
            printf("->");
        }
    }
    printf("\n");
}

void test_1_50() {
    // testTwoSum();
    // testAddTwoNumbers();
    // testLengthOfLongestSubstring();
    // testFindMedianSortedArrays();
    // testLongestPalindrome();
    // testConvert();
    // testReverse();
    // testMyAtoi();
    // testIsPalindrome();
    // testConvert();
    // testMaxArea();
    // testLongestCommonPrefix();
    // testThreeSum();
    // testLetterCombinations();
    // testFourSum();
    // testIsValid();
    // testMergeTwoLists();
    // testGenerateParenthesis();
    // testMergeKLists();
    // testRemoveDuplicates();
    // testStrStr();
    // testDivide();
    // testRomanToInt();
    // testLongestValidParentheses();
    // testSearch();
    // testSearchRange();
    // testIsValidSudoku();
    // testFirstMissingPositive();
    // testTrap();
    // testIsMatch();
    // testIsWildcardMatch();
    // testPermute();
    // testRotate();
    // testCountAndSay();
    testMyPow();
}

void test_51_100() {
    testMaxSubArray();
}

void test_151_200() {
    testTrailingZeroes();
}

void test_201_250() {
    // testCountDigitOne();
}

void test_301_350() {
    // testOddEvenList();
}

//
int main(int argc, char *argv[]) {
    // test_1_50();
    test_51_100();
    // test_151_200();
}