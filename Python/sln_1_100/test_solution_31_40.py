from unittest import TestCase

from sln_1_100.solution_31_40 import Solution_31_40


# -*- coding: UTF-8 -*-
class TestSolution_31_40(TestCase):
    def setUp(self):
        self.sln = Solution_31_40()

    def test_searchInsert(self):
        ret1 = self.sln.searchInsert([1, 3, 5, 6], 5)
        self.assertEqual(ret1, 2)
        self.assertEqual(self.sln.searchInsert([], 0), 0)
        self.assertEqual(self.sln.searchInsert([1, 2, 3], 0), 0)
        self.assertEqual(self.sln.searchInsert([1, 2, 3], 10), 3)

    def test_countAndSay(self):
        self.assertEqual(self.sln.countAndSay(2), '11')
        self.assertEqual(self.sln.countAndSay(4), '1211')
