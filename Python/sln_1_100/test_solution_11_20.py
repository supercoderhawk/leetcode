# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_1_100.solution_11_20 import Solution_11_20


class Test_solution_11_20(TestCase):
    def setUp(self) -> None:
        self.sln = Solution_11_20()

    def test_threeSumClosest(self):
        ret = self.sln.threeSumClosest([-1, 0, 1, 1, 55], 3)
        self.assertEqual(ret, 2)
