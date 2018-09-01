# -*- coding: utf-8 -*-
from common_utils import ListNode


class Solution_21_30(object):
    def swapPairs(self, head):
        """
        24
        :param head:
        :return:
        """
        if not head or not head.next:
            return head
        prev_node = node = head
        is_start = True
        while node:
            if not node.next:
                break
            next_node = node.next
            node.next = next_node.next

            next_node.next = node

            if is_start:
                head = next_node
                is_start = False
            else:
                prev_node.next = next_node
            prev_node = node
            node = node.next

        return head

    def removeElement(self, nums, val):
        """
        27
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        count = index = 0
        original_nums_len = nums_len = len(nums)
        while index < nums_len:
            if nums[index] == val:
                nums.pop(index)
                count += 1
                nums_len -= 1
            else:
                index += 1

        return original_nums_len - count
