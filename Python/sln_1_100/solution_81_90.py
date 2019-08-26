# -*- coding: utf-8 -*-
from common_utils import ListNode


class Solution_81_90(object):
    def partition(self, head: ListNode, x: int) -> ListNode:
        """
        86
        :param head:
        :param x:
        :return:
        """
        if not head:
            return head
        less_head = less_node = None
        equal_more_than_head = equal_more_than_node = None
        node = head
        while node:
            val = node.val
            if val < x:
                if less_head is None:
                    less_head = less_node = ListNode(val)
                else:
                    less_node.next = ListNode(val)
                    less_node = less_node.next
            else:
                if equal_more_than_head is None:
                    equal_more_than_head = equal_more_than_node = ListNode(val)
                else:
                    equal_more_than_node.next = ListNode(val)
                    equal_more_than_node = equal_more_than_node.next
            node = node.next

        if less_head is None:
            new_head = equal_more_than_head
        else:
            less_node.next = equal_more_than_head
            new_head = less_head
        return new_head
