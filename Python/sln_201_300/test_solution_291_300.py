# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_201_300.solution_291_300 import Solution_291_300


class TestSolution_291_300(TestCase):
    def setUp(self):
        self.sln = Solution_291_300()

    def test_lengthOfLIS(self):
        arr = [10, 9, 2, 5, 3, 7, 101, 18]
        self.assertEqual(self.sln.lengthOfLIS(arr), 4)
        arr1 = [4, 10, 4, 3, 8, 9]
        self.assertEqual(self.sln.lengthOfLIS(arr1), 3)
