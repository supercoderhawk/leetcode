# -*- coding: utf-8 -*-
from common_utils import *


class Solution_61_70(object):
    def rotateRight(self, head, k):
        """
        61
        :param head:
        :param k:
        :return:
        """
        if not head or not head.next:
            return head

        list_len = 1

        node = head
        while node.next:
            list_len += 1
            node = node.next
        last_node = node
        node = head.next
        prev_node = head
        if k % list_len == 0:
            new_head = head
        else:
            for _ in range(list_len - k % list_len - 1):
                prev_node = prev_node.next
                node = node.next
            new_head = node
            prev_node.next = None
            last_node.next = head
        return new_head

    def addBinary(self, a, b):
        """
        67
        :type a: str
        :type b: str
        :rtype: str
        """
        if len(a) > len(b):
            max_len = len(a)
            b = '0' * (len(a) - len(b)) + b
        else:
            max_len = len(b)
            a = '0' * (len(b) - len(a)) + a

        result = []
        carry = 0
        for ch_a, ch_b in zip(a[::-1], b[::-1]):
            bit = int(ch_a) + int(ch_b) + carry
            if bit > 1:
                result.append(str(bit - 2))
                carry = 1
            else:
                result.append(str(bit))
                carry = 0

        if carry == 1:
            result.append('1')

        return ''.join(result[::-1])
