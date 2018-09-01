# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_1_100.solution_21_30 import Solution_21_30
from common_utils import ListNode, print_linked_list


class TestSolution_21_30(TestCase):
    def setUp(self):
        self.sln = Solution_21_30()

    def test_swapPairs(self):
        node1 = ListNode(1)
        node2 = ListNode(2)
        node1.next = node2
        node3 = ListNode(3)
        node2.next = node3
        node4 = ListNode(4)
        node3.next = node4
        print_linked_list(node1)
        # node = self.sln.swapPairs(node1)
        node = self.sln.swapPairs(node2)
        print_linked_list(node)

    def test_removeElement(self):
        ret = self.sln.removeElement([1, 2, 2, 3, 4, 5], 2)
        self.assertEqual(ret, 2)
        ret2 = self.sln.removeElement([1], 1)
