# -*- coding: utf-8 -*-
from typing import List
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

    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        88
        Do not return anything, modify nums1 in-place instead.
        """

        merged_arr = []
        if not m:
            merged_arr = nums2
        elif not n:
            merged_arr = nums1
        else:
            i1 = i2 = 0
            for _ in range(m + n):
                if nums1[i1] < nums2[i2]:
                    merged_arr.append(nums1[i1])
                    i1 += 1
                else:
                    merged_arr.append(nums2[i2])
                    i2 += 1
                if i1 == m:
                    merged_arr.extend(nums2[i2:n])
                    break
                if i2 == n:
                    merged_arr.extend(nums1[i1:m])
                    break

        for i, val in enumerate(merged_arr):
            nums1[i] = val
