/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * Created by supercoderx on 2017/8/10.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../main.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1,*p2=l2, *header=NULL,*p3=NULL,*node=NULL;
    if(l1==NULL || l2 == NULL){
        return l1==NULL?l2:l1;
    }

    while (p1!=NULL || p2!=NULL){
        node = malloc(sizeof(struct ListNode));
        node->next = NULL;
        if(p1==NULL){
            node->val = p2->val;
            p3->next = node;
            p3 = node;
            p2=p2->next;
        }
        else if(p2==NULL){
            node->val = p1->val;
            p3->next = node;
            p3 = node;
            p1=p1->next;
        } else{
            if(p1->val<p2->val){
                node->val = p1->val;
                p1=p1->next;
            }else{
                node->val = p2->val;
                p2=p2->next;
            }
            if(header == NULL){
                header = node;
            }else{
                p3->next = node;
            }
            p3 = node;
        }
    }
    return header;
}

void testMergeTwoLists(){
    int a1[]={1,2,3},b1[]={4,5,6};
    int a2[]={1,9,10},b2[]={2,3,4,6,7};
    struct ListNode * la1 = createList(a1,3);
    struct ListNode * lb1 = createList(b1,3);
    struct ListNode * la2 = createList(a2,3);
    struct ListNode * lb2 = createList(b2,5);
    printList(mergeTwoLists(la1,lb1));
    printList(mergeTwoLists(la2,lb2));

}