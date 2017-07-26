//
// Created by supercoderhawk on 2017/7/19.
//

#ifndef C_MAIN_H
#define C_MAIN_H
#define bool char
#define true 1
#define false 0

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createList(const int *vals, int count);

void printList(struct ListNode *l);

#endif //C_MAIN_H
