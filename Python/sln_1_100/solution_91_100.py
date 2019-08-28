# -*- coding: utf-8 -*-
from typing import List
from common_utils import ListNode


class Solution_91_100(object):
    def numDecodings(self, s: str) -> int:
        """
        91
        :param s:
        :return:
        """
        prefix2num = {}
        for i in range(len(s)):
            candidate = s[:i + 1]
            prefix1 = candidate[:-1]
            prefix2 = candidate[:-2]
            count = 0
            if int(candidate[-1]) > 0:
                count += prefix2num.get(prefix1, 1)
            if 10 <= int(candidate[-2:]) <= 26:
                count += prefix2num.get(prefix2, 1)
            if candidate:
                prefix2num[candidate] = count
        return prefix2num[s]

    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        """
        92
        :param head:
        :param m:
        :param n:
        :return:
        """
        if m == n:
            return head
        infix_tail = None
        infix_head = None
        node = None
        idx = 1
        while idx < m:
            if node is None:
                node = head
            else:
                node = node.next
            idx += 1
        prefix_tail = node

        while idx <= n:
            if node is None:
                node = head
            else:
                node = node.next
            infix_node = ListNode(node.val)
            if infix_head is None:
                infix_head = infix_tail = infix_node
            else:
                infix_node.next = infix_head
                infix_head = infix_node

            idx += 1
        if prefix_tail is None:
            new_head = infix_head
        else:
            new_head = head
            prefix_tail.next = infix_head
        infix_tail.next = node.next
        return new_head

    def restoreIpAddresses(self, s: str) -> List[str]:
        """
        93
        :param s:
        :return:
        """
        results = []

        def resolve_ip(segments, rest_s, last_num):
            if len(segments) == 4:
                if not rest_s:
                    results.append('.'.join(segments))
                    return
            elif len(segments) > 4:
                return
            if last_num is None:
                if not rest_s:
                    return

                segments.append(rest_s[0])
            elif not rest_s:
                return
            else:
                first_digit = int(rest_s[0])
                new_num = last_num * 10 + first_digit
                if new_num > 255 or segments[-1] == '0':
                    segments.append(rest_s[0])
                else:
                    # if first_digit < 3:
                    new_segments = segments[::]
                    new_segments.append(rest_s[0])
                    resolve_ip(new_segments, rest_s[1:], first_digit)
                    segments[-1] += rest_s[0]
            last_num = int(segments[-1])
            rest_s = rest_s[1:]
            resolve_ip(segments, rest_s, last_num)

        resolve_ip([], s, None)

        return results
