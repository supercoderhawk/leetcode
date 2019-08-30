# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_101_200.solution_111_120 import Solution_111_120


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
