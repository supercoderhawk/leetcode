from unittest import TestCase
from sln_1_100.solution_41_50 import Solution_41_50


# -*- coding: UTF-8 -*-
class TestSolution_41_50(TestCase):
    def setUp(self):
        self.sln = Solution_41_50()

    def test_multiply(self):
        self.assertEqual(self.sln.multiply('3', '2'), '6')
        self.assertEqual(self.sln.multiply('123', '456'), '56088')
        self.assertEqual(self.sln.multiply('123', '0'), '0')

    def test_permute(self):
        a = [1, 2, 3]
        b = [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
        self.assertCountEqual(self.sln.permute(a), b)

    def test_groupAnagrams(self):
        a = ["eat", "tea", "tan", "ate", "nat", "bat"]
        b = [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]
        self.assertCountEqual(self.sln.groupAnagrams(a), b)
        self.assertCountEqual(self.sln.groupAnagrams(['']), [['']])
