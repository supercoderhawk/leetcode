/*
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Created by supercoderhawk on 2017/7/23.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../main.h"

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *lSum = NULL;
    struct ListNode *p1 = l1, *p2 = l2, *p = lSum, *tmpS;
    int carry = 0, digit = 0;

    while (p1 != NULL || p2 != NULL) {
        tmpS = (struct ListNode *) malloc(sizeof(struct ListNode));

        digit = carry;
        if (p1 != NULL) {
            digit += p1->val;
        }
        if (p2 != NULL) {
            digit += p2->val;
        }
        if (digit >= 10) {
            digit %= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        tmpS->val = digit;
        tmpS->next = NULL;
        if (lSum == NULL) {
            lSum = p = tmpS;
        } else {
            p->next = tmpS;
            p = tmpS;
        }

        if (p1 != NULL) {
            p1 = p1->next;
        }
        if (p2 != NULL) {
            p2 = p2->next;
        }
    }
    if(carry != 0)
    {
        tmpS = (struct ListNode *) malloc(sizeof(struct ListNode));
        tmpS->val = carry;
        tmpS->next = NULL;
        p->next = tmpS;
    }
    return lSum;
}

void testAddTwoNumbers() {
    int a1[3] = {2, 4, 3};
    int b1[3] = {5, 6, 4};
    int a2[3] = {5};

    struct ListNode *l1 = createList(a1, 3);
    struct ListNode *l2 = createList(b1, 3);
    printList(addTwoNumbers(l1, l2));
    struct ListNode *l3 = createList(a2, 1);
    struct ListNode *l4 = createList(a2, 1);
    printList(addTwoNumbers(l3, l4));
}