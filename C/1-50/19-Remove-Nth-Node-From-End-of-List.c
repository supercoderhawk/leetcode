/*
 * Given a linked list, remove the nth node from the end of list and return its head.

 * For example,

 *  Given linked list: 1->2->3->4->5, and n = 2.
 *  After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 * Created by supercoderx on 2017/8/9.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../main.h"

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    if (head == NULL) {
        return head;
    }
    struct ListNode *p = head, *q;
    int len = 0, id, index = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    id = len - n;
    p = head;
    if (id == 0) {
        head = head->next;
        free(p);
    } else {
        while (index != id - 1) {
            p = p->next;
            index++;
        }
        q = p->next;
        p->next = id == len - 1 ? NULL : q->next;
        free(q);
    }

    return head;

}

void testRemoveNthFromEnd() {

}