# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_101_200.solution_101_110 import Solution_101_110, TreeNode
from common_utils import build_binary_tree,build_linked_list


class TestSolution_101_110(TestCase):
    def setUp(self):
        self.sln = Solution_101_110()

    def test_maxDepth(self):
        left_1 = TreeNode(10)
        left_1_1 = TreeNode(111)
        left_1_1_1 = TreeNode(1111)
        left_1_1.left = left_1_1_1
        right_1_2 = TreeNode(112)
        left_1.left = left_1_1
        right_1 = TreeNode(20)
        right_1.right = right_1_2
        root = TreeNode(121)
        root.left = left_1
        root.right = right_1
        depth = self.sln.maxDepth(root)
        self.assertEqual(depth, 4)

    def test_zigzagLevelOrder(self):
        tree = build_binary_tree([3, 9, 20, None, None, 15, 7])
        self.assertEqual(self.sln.zigzagLevelOrder(tree), [[3], [20, 9], [15, 7]])

    def test_sortedListToBST(self):
        head = build_linked_list([-10,-3,0,5,9])
        root = self.sln.sortedListToBST(head)
