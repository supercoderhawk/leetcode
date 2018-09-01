# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_101_200.solution_101_110 import Solution_101_110, TreeNode


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
