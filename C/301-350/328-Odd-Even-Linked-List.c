/*
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 *
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 *
 * Example:
 *  Given 1->2->3->4->5->NULL,
 *  return 1->3->5->2->4->NULL.
 *
 * Note:
 *  The relative order inside both the even and odd groups should remain as it was in the input.
 *  The first node is considered odd, the second node even and so on ...
 */
#include <stdio.h>
#include "../main.h"

struct ListNode *oddEvenList(struct ListNode *head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return head;
    }

    struct ListNode *pOddHead = head, *pEvenHead = head->next;
    struct ListNode *pOdd = pOddHead, *pEven = pEvenHead, *p = pEven->next;

    int count = 3;
    while (p!=NULL) {
        if (count % 2) {
            pOdd->next = p;
            pOdd = pOdd->next;
        } else {
            pEven->next = p;
            pEven = pEven->next;
        }
        p = p->next;
        count++;
    }

    pEven->next = NULL;
    pOdd->next = pEvenHead;
    return pOddHead;
}

void testOddEvenList() {
    int a1[4] = {1, 2, 3, 4};
    int a2[2] = {1, 2};
    int a3[4] = {1};
    struct ListNode *p;

    p = createList(a1, 4);
    printList(oddEvenList(p));

    p = createList(a2, 2);
    printList(oddEvenList(p));

    p = createList(a3, 1);
    printList(oddEvenList(p));

    p = NULL;
    printList(oddEvenList(p));

}