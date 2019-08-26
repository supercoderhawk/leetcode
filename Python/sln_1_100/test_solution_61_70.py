# -*- coding: utf-8 -*-
from sln_1_100.solution_61_70 import Solution_61_70
from common_utils import *
from unittest import TestCase


class TestSolution_61_70(TestCase):
    def setUp(self):
        self.sln = Solution_61_70()

    def test_rotate_right(self):
        l1 = ListNode(1)
        l2 = ListNode(2)
        l1.next = l2
        l3 = ListNode(3)
        l2.next = l3
        l4 = ListNode(4)
        l3.next = l4
        l5 = ListNode(5)
        l4.next = l5
        node = self.sln.rotateRight(l1, 8)
        while node:
            print(node.val)
            node = node.next

    def test_addBinary(self):
        ret = self.sln.addBinary('11', '1')
        print(ret)

    def test_uniquePathsWithObstacles(self):
        matrix = [
            [0, 0, 0],
            [0, 1, 0],
            [0, 0, 0]
        ]
        ret = self.sln.uniquePathsWithObstacles(matrix)
        print(ret)
