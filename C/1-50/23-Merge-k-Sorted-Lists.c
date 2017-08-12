/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * Created by supercoderx on 2017/8/11.
 */

#include "../main.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize <= 0) {
        return NULL;
    }
    if (listsSize == 1) {
        return lists[0];
    }

    struct ListNode *header = lists[0], *p, *p1, *p2, *node, *prev;
    int count = 0, start = 0;

    for (int i = 1; i < listsSize; i++) {
        p1 = header;
        p2 = lists[i];
        if (p1 == NULL) {
            header = p2;
        }
        if (p1 == NULL || p2 == NULL) {
            continue;
        }

        count++;
        if (count == 1) {
            while (p1 != NULL || p2 != NULL) {
                node = malloc(sizeof(struct ListNode));
                node->next = NULL;
                if (p1 == NULL) {
                    node->val = p2->val;
                    p2 = p2->next;
                } else if (p2 == NULL) {
                    node->val = p1->val;
                    p1 = p1->next;
                } else {
                    if (p1->val < p2->val) {
                        node->val = p1->val;
                        p1 = p1->next;
                    } else {
                        node->val = p2->val;
                        p2 = p2->next;
                    }
                }
                if (start == 0) {
                    header = p = node;
                    start = 1;
                } else {
                    p->next = node;
                    p = node;
                }
            }
        } else {
            prev = NULL;
            while (p1 != NULL || p2 != NULL) {
                if (p1 == NULL) {
                    node = malloc(sizeof(struct ListNode));
                    node->next = NULL;
                    node->val = p2->val;
                    if (prev == NULL) {
                        node->next = header;
                        header = node;
                    } else {
                        prev->next = node;
                        prev = node;
                    }
                    p2 = p2->next;
                } else if (p2 == NULL) {
                    break;
                } else {
                    if (p1->val < p2->val) {
                        prev = p1;
                        p1 = p1->next;
                    } else {
                        node = malloc(sizeof(struct ListNode));
                        node->val = p2->val;
                        if (prev == NULL) {
                            node->next = header;
                            header = node;
                        } else {
                            prev->next = node;
                            node->next = p1;
                        }
                        prev = node;
                        p2 = p2->next;
                    }
                }
            }
        }

    }
    return header;
}

void testMergeKLists() {
    int a[] = {-1, 1};
    int b[] = {-3, 1, 4};
    int c[] = {-2,-1,0,2};
    int a1[] = {1};
    int a2[] = {0};
    struct ListNode *l1 = createList(a, 2);
    struct ListNode *l2 = createList(b, 3);
    struct ListNode *l3 = createList(c, 4);
    struct ListNode *l11 = createList(a1, 1);
    struct ListNode *l12 = createList(a2, 1);
    struct ListNode **l = malloc(sizeof(struct ListNode *) * 4);
    l[0] = l1;l[1] = l2;l[2]=l3;l[3] = l3;
    //l[0] = l11;
    //l[1] = l12;
    printList(mergeKLists(l, 3));
}