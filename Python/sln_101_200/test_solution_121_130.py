# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_101_200.solution_121_130 import Solution_121_130

class Test_Solution_121_130(TestCase):
    def setUp(self) -> None:
        self.sln = Solution_121_130()

    def test_maxProfit(self):
        a = [7,1,5,3,6,4]
        max_val = self.sln.maxProfit(a)
        self.assertEqual(max_val, 5)