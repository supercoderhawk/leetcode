# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_101_200.solution_111_120 import Solution_111_120
from common_utils import build_binary_tree


class Test_Solution_111_120(TestCase):
    def setUp(self) -> None:
        self.sln = Solution_111_120()

    def test_minimumTotal(self):
        triangle = [
            [2],
            [3, 4],
            [6, 5, 7],
            [4, 1, 8, 3]
        ]
        self.assertEqual(self.sln.minimumTotal(triangle), 11)

    def test_pathSum(self):
        tree = build_binary_tree([5, 4, 8, 11, None, 13, 4, 7, 2, None, None, 5, 1])
        self.assertEqual(self.sln.pathSum(tree, 22), [[5, 4, 11, 2], [5, 8, 4, 5]])
